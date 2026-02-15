#ifndef __LEARN_CPP_POC_SUBNET_IPV4_IPV4_H
#define __LEARN_CPP_POC_SUBNET_IPV4_IPV4_H

#include <cstdint>

namespace learn_cpp::poc::subnet_ipv4::core {
  class IPv4 {
  public:
    explicit IPv4(std::uint32_t ip);
  private:
    std::uint32_t _value;
  };
}
#endif