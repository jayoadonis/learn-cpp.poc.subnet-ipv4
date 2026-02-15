#ifndef __LEARNCPP_POC_SUBNETIPV4_UNITTEST_TESTIPV4_H
#define __LEARNCPP_POC_SUBNETIPV4_UNITTEST_TESTIPV4_H

#include <cassert>
#include <iostream>

#include "learn_cpp/poc/subnet_ipv4/core/IPv4.h"

namespace learn_cpp::poc::subnet_ipv4::unit_test {
  void test_ipv4() {
    char const *ip = "101.20.1.30";
    subnet_ipv4::core::IPv4 ipv4 
      = subnet_ipv4::core::IPv4::from_string(ip);
    std::cout << "::: " << ipv4.to_string() << ", " << ipv4.value() << "\n";

    assert(ipv4.to_string() == ip);
  }

  void test_ipv4_ii() {
    std::cout << "<><><> OK\n";
  }
}

#endif