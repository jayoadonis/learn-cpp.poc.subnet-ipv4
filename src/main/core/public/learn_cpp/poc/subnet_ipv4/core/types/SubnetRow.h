#ifndef __LEARNCPP_POC_SUBNETIPV4_CORE_TYPES_SUBNETROW_H
#define __LEARNCPP_POC_SUBNETIPV4_CORE_TYPES_SUBNETROW_H

#include <string>

namespace learn_cpp::poc::subnet_ipv4::core::types {
  struct SubnetRow {
    std::string m_network_ip;
    std::string m_usable_range_ips;
    std::string m_broadcast_ip;
  };
}
#endif