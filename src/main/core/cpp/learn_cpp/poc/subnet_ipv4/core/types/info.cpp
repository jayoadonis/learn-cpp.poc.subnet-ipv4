#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetResult.h"

namespace learn_cpp::poc::subnet_ipv4::core::types {
  char const* subnet_result_info(SubnetResult const& r) {
    static thread_local char info[1024];
    
    int n = std::snprintf(info, sizeof(info), 
      "ip: %s\nclassfull_name: %s\ndefault_cidr: /%u\nactual_cidr: /%u\namount_requested_host: %u\namount_usable_host: %u\namount_total_host: %u\nbarrowed_network_bits: %u\nusable_host_bits: %u\namount_subnet: %u",
      r.m_ip.c_str(),
      r.m_classfull_name.c_str(),
      r.m_default_cidr,
      r.m_actual_cidr,
      r.m_amount_requested_host,
      r.m_amount_usable_host,
      r.m_amount_total_host,
      r.m_barrowed_network_bits,
      r.m_usable_host_bits,
      r.m_amount_subnet);

    if(n < 0 || static_cast<size_t>(n) > sizeof(info)) 
      return &(info[0] = '\0');
    
    return info;
  }
}