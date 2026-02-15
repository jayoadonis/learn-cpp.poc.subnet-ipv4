#ifndef __LEARN_CPP_POC_SUBNET_IPV4_CORE_ENGINE_H
#define __LEARN_CPP_POC_SUBNET_IPV4_CORE_ENGINE_H

#include "learn_cpp/poc/subnet_ipv4/core/IPv4.h"
#include <cstdio>

namespace subnet_ipv4 {
  namespace core = learn_cpp::poc::subnet_ipv4::core;
} 
using xyz_t = subnet_ipv4::core::IPv4;
typedef subnet_ipv4::core::IPv4 zyx_t;

namespace learn_cpp::poc::subnet_ipv4::app {
  class Engine {
  public:
    static void test() { 
      std::printf("::: Hi from Engine test(V)V.\n");
    }
  };
}
#endif