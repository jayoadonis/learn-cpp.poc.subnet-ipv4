#ifndef __LEARNCPP_POC_SUBNETIPV4_CORE_SUBNETCALC_H
#define __LEARNCPP_POC_SUBNETIPV4_CORE_SUBNETCALC_H

#include "learn_cpp/poc/subnet_ipv4/core/IPv4.h"
#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetResult.h"
#include <string>

namespace learn_cpp::poc::subnet_ipv4::core {
  class SubnetCalc {
  public:
    explicit SubnetCalc() = default;
    virtual ~SubnetCalc() = default;
    virtual types::SubnetResult compute(std::string const &ip,
      signed requested_host_amount) const;
  private:
      virtual IPv4::CIDRNotation default_cidr(core::IPv4 const &ip) const;
      virtual char const* class_name(core::IPv4 const &ip) const;
      virtual types::SubnetResult build(
        core::IPv4 const &ip,
        unsigned requested_host_amount,
        unsigned default_cidr,
        unsigned actual_cidr,
        unsigned total_host_amount,
        unsigned subnet_amount,
        unsigned barrowed_network_bits,
        unsigned usable_host_amount,
        unsigned usable_host_bits) const;
      virtual unsigned classfull_amount_usable_host_max_boundary(
        IPv4::CIDRNotation const &cidr) const;
  };
}
#endif