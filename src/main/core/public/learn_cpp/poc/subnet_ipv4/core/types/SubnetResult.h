#ifndef __LEARNCPP_POC_SUBNETIPV4_CORE_SUBNETRESULT_H //REM: Observe header guard name
#define __LEARNCPP_POC_SUBNETIPV4_CORE_SUBNETRESULT_H

#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetResult.h"
#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetRow.h"
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <cstdint>
#include <vector>

namespace learn_cpp::poc::subnet_ipv4::core::types {
  struct SubnetResult {
    private:  mutable int private_x;
    public:  int public_x;
    std::string m_ip;
    std::string m_classfull_name;
    std::vector<types::SubnetRow> m_table;
    std::uint32_t m_amount_requested_host{};
    std::uint32_t m_amount_usable_host{};
    std::uint32_t m_amount_total_host{};
    std::uint32_t m_default_cidr{};
    std::uint32_t m_actual_cidr{};
    std::uint32_t m_barrowed_network_bits{};
    std::uint32_t m_usable_host_bits{};
    std::uint32_t m_amount_subnet{};

    friend std::ostream &operator<<(std::ostream &os, SubnetResult const & r) {
      return os << "ip: " << r.m_ip << "\n"
        << "classfull_name: " << r.m_classfull_name << "\n"
        << "default_cidr: /" << r.m_default_cidr << "\n"
        << "actual_cidr: /" << r.m_actual_cidr << "\n"
        << "amount_requested_host: " << r.m_amount_requested_host << "\n"
        << "amount_usable_host: " << r.m_amount_usable_host << "\n"
        << "amount_total_host: " << r.m_amount_total_host << "\n"
        << "barrowed_network_bits: " << r.m_barrowed_network_bits << "\n"
        << "usable_host_bits: " << r.m_usable_host_bits << "\n"
        << "amount_subnet: " << r.m_amount_subnet;
    }

    friend char const* subnet_result_info(SubnetResult const& r);
  };
}
#endif