#ifndef __LEARNCPP_POC_SUBNETIPV4_UNITTEST_SUBNETCALC_TEST_H
#define __LEARNCPP_POC_SUBNETIPV4_UNITTEST_SUBNETCALC_TEST_H

#include "learn_cpp/poc/subnet_ipv4/core/SubnetCalc.h"
#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetResult.h"
#include "learn_cpp/poc/subnet_ipv4/core/types/SubnetRow.h"
#include <iostream>
#include <iomanip>
#include <assert.h>

namespace learn_cpp::poc::subnet_ipv4::unit_test {
  void subnet_calc_test_i() {

    core::SubnetCalc calc;

    core::types::SubnetResult subnet_result = 
      calc.compute("192.0.10.2", 254);

    std::cout << subnet_result << "\n";

    assert(subnet_result.m_classfull_name == "Class C");
    assert(subnet_result.m_actual_cidr == 24u);
    assert(subnet_result.m_table.size() == 1);

    size_t i = 0;
    for(core::types::SubnetRow x : subnet_result.m_table) {
      
      char prev_fill = std::cout.fill();

      std::cout << std::setw(static_cast<int>(3))
                << std::setfill('0') << std::right << i;

      std::cout << " | "
                << std::setw(17) << std::setfill(' ') << std::right << x.m_network_ip
                << " | "
                << std::setw(34) << std::setfill(' ') << std::left << x.m_usable_range_ips
                << " | "
                << std::setw(17) << std::setfill(' ') << std::right << x.m_broadcast_ip
                << '\n';

      std::cout.fill(prev_fill);

      ++i;
    }
  }
}
#endif


