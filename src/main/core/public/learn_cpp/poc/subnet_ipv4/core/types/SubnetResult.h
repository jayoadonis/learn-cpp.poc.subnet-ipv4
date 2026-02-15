#ifndef __LEARNCPP_POC_SUBNETIPV4_CORE_SUBNETRESULT_H //REM: Observe header guard name
#define __LEARNCPP_POC_SUBNETIPV4_CORE_SUBNETRESULT_H

#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetRow.h"
#include <string>
#include <cstdint>
#include <vector>

namespace learn_cpp::poc::subnet_ipv4::core::types {
  struct SubnetResult {
    std::string m_ip;
    std::string m_class_type;
    std::vector<types::SubnetRow> m_table;
    std::uint64_t m_number_of_subnets{};
    std::uint32_t m_default_cidr{};
    std::uint32_t m_actual_cidr{};
    std::uint32_t m_barrowed_bits{};
    std::uint32_t m_usable_host_per_subnets{};
  };
}
#endif