#ifndef __LEARN_CPP_POC_SUBNET_IPV4_CORE_IPV4_H
#define __LEARN_CPP_POC_SUBNET_IPV4_CORE_IPV4_H

#include <cstdint>
#include <string>

namespace learn_cpp::poc::subnet_ipv4::core {
  class IPv4 {
  public:
    enum class CIDRNotation : std::uint16_t {
      A = 8u,
      B = 16u,
      C = 24u
    };
  public:
    explicit IPv4(std::uint32_t ip);
    [[nodiscard]] virtual constexpr inline std::uint32_t value() const;
    virtual std::uint16_t first_octet() const;
    virtual std::string to_string() const;
    static IPv4 from_string(std::string const &str);
  private:
    std::uint32_t m_value;
  };
}
#endif