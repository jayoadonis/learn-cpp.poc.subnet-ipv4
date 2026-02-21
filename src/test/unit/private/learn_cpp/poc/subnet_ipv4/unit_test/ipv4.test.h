#ifndef __LEARNCPP_POC_SUBNETIPV4_UNITTEST_TESTIPV4_H
#define __LEARNCPP_POC_SUBNETIPV4_UNITTEST_TESTIPV4_H

#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

#include "learn_cpp/poc/subnet_ipv4/core/IPv4.h"

namespace learn_cpp::poc::subnet_ipv4::unit_test {
  void test_ipv4() {
    char const *ip = "101.20.1.30";

    subnet_ipv4::core::IPv4 ipv4 
      = subnet_ipv4::core::IPv4::from_string(ip);
      
    std::cout << "::: " << ipv4.to_string() << ", " << ipv4.value() << ", " << ipv4.first_octet() << "\n";

    assert(ipv4.to_string() == ip);
    assert(ipv4.value() == 1'695'809'822u);
  }

  void test_ipv4_ii() {

    std::istringstream iss("1.2.3.4");
    std::string out_token;
    std::uint32_t result = 0;

    for(std::size_t i = 0; i < 4; ++i) {
      if(!std::getline(iss, out_token, '.')) {
        throw std::runtime_error("Invalid IPv4 format");
      }

      std::cout << ":::<" << i << "> iss.str(): '" << iss.str() << "'\n";
      std::cout << ":::<" << i << "> out_token: '" << out_token << "'\n";
      
      std::int32_t octet = std::stoi(out_token);
      if(octet < 0 || octet > std::numeric_limits<std::uint8_t>::max()) {
        throw std::runtime_error("Invalid IPv4 octect");
      }


      std::cout << ":::<" << i << "> octet: " << octet << "\n";
      std::cout << ":::<" << i << "> result << 8: " << (result << 8) << "\n";

      result = (result << 8) | static_cast<std::uint32_t>(octet);
      
      std::cout << ":::<" << i << "> result: " << result << "\n";
    }
  }
}

#endif