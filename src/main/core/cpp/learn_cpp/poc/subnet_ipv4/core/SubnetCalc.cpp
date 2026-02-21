#include "learn_cpp/poc/subnet_ipv4/core/SubnetCalc.h"
#include "learn_cpp/poc/subnet_ipv4/core/IPv4.h"
#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetResult.h"
#include "learn_cpp/poc/subnet_ipv4/core/types/info.h"


#include <iostream>
#include <stdexcept>

namespace learn_cpp::poc::subnet_ipv4::core {
  unsigned classfull_host_max_boundary(IPv4::CIDRNotation const&);

  types::SubnetResult SubnetCalc::compute(std::string const &ip,
    signed requested_host_amount) const
  {
    // if(requested_host_amount <= 2)
    //   throw std::runtime_error("Please reserve 2 for network and broadcast ip addresses. Input should be atleast (3).");
    
    IPv4 ipv4 = IPv4::from_string(ip);

    IPv4::CIDRNotation cidr = this->default_cidr(ipv4);
    unsigned default_cidr = static_cast<unsigned>(cidr);
    unsigned default_host_bits = 32u - default_cidr; 

    unsigned usable_host_bits = 0u;
    while(static_cast<signed>((1u << (usable_host_bits))-2u) < requested_host_amount) {
      ++usable_host_bits;
    }

    unsigned barrowed_network_bits = (default_host_bits - usable_host_bits);
    unsigned actual_cidr = default_cidr + barrowed_network_bits;

    unsigned subnet_amount = (1u << barrowed_network_bits);
    unsigned total_host_amount = (1u << usable_host_bits);
    unsigned usable_host_amount = total_host_amount - 2u;

    if(usable_host_amount > (this->classfull_amount_usable_host_max_boundary(cidr))) {
      throw std::runtime_error(
        "Exceeds host amount for classfull (" + std::string(this->class_name(ipv4))
        + ", " + std::to_string(this->classfull_amount_usable_host_max_boundary(cidr))
        + "). Found input amount host: " 
        + std::to_string(total_host_amount));
    }

    return this->build(
      ipv4, 
      requested_host_amount,
      default_cidr,
      actual_cidr, 
      total_host_amount,
      subnet_amount, 
      barrowed_network_bits,
      usable_host_amount,
      usable_host_bits);
  }

  IPv4::CIDRNotation SubnetCalc::default_cidr(IPv4 const &ipv4) const {
    unsigned first_octet = ipv4.first_octet();
    if(first_octet <= 127u) return IPv4::CIDRNotation::A;
    if(first_octet <= 191u) return IPv4::CIDRNotation::B;
    if(first_octet <= 223u) return IPv4::CIDRNotation::C;
    throw std::runtime_error("Unsupported Class.");
  }

  char const* SubnetCalc::class_name(core::IPv4 const &ipv4) const {
    switch(this->default_cidr(ipv4)) {
      case IPv4::CIDRNotation::A: return "Class A";
      case IPv4::CIDRNotation::B: return "Class B";
      case IPv4::CIDRNotation::C: return "Class C";
      default: return "Invalid";
    }
  }

  unsigned SubnetCalc::classfull_amount_usable_host_max_boundary(IPv4::CIDRNotation const &cidr) const {
    switch(cidr) {
      case IPv4::CIDRNotation::A: return 16'777'214u;
      case IPv4::CIDRNotation::B: return 65'534u;
      case IPv4::CIDRNotation::C: return 254u;
      default:
        throw std::runtime_error("Cannot found CIDR notation");
    }
  }
  
  types::SubnetResult SubnetCalc::build(
    core::IPv4 const &ip,
    unsigned requested_host_amount,
    unsigned default_cidr,
    unsigned actual_cidr,
    unsigned total_host_amount,
    unsigned subnet_amount,
    unsigned barrowed_network_bits,
    unsigned usable_host_amount,
    unsigned usable_host_bits) const 
  {
    types::SubnetResult result;
    result.m_ip = ip.to_string();
    result.m_classfull_name = this->class_name(ip);
    result.m_amount_requested_host = requested_host_amount;
    result.m_amount_total_host = total_host_amount;
    result.m_amount_usable_host = usable_host_amount;
    result.m_default_cidr = default_cidr;
    result.m_actual_cidr = actual_cidr;
    result.m_barrowed_network_bits = barrowed_network_bits;
    result.m_usable_host_bits = usable_host_bits;
    result.m_amount_subnet = subnet_amount;

    std::uint32_t network_mask = (result.m_default_cidr==0)
      ? 0u : (~0u << (32-result.m_default_cidr));
    std::uint32_t base = ip.value() & network_mask;

    for(size_t i = 0; i < result.m_amount_subnet; ++i) {
      unsigned network_ip = base + (i * result.m_amount_total_host);
      unsigned broadcast_ip = (network_ip + result.m_amount_total_host) - 1;

      core::types::SubnetRow subnet_row;
      subnet_row.m_network_ip = core::IPv4(network_ip).to_string();
      subnet_row.m_broadcast_ip = core::IPv4(broadcast_ip).to_string();

      if(result.m_amount_usable_host >= 2) {
        subnet_row.m_usable_range_ips = 
          IPv4(network_ip + 1).to_string() + " - " +
          IPv4(broadcast_ip - 1).to_string();
      } 
      else {
        subnet_row.m_usable_range_ips = "N/A";
      }

      result.m_table.push_back(subnet_row);
    }

    return result;
  }

}
