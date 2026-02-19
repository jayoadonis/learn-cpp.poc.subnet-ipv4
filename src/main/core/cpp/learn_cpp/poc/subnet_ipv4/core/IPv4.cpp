#include "learn_cpp/poc/subnet_ipv4/core/IPv4.h"
#include <limits>
#include <sstream>
#include <string>

namespace learn_cpp::poc::subnet_ipv4::core {
  IPv4::IPv4(std::uint32_t ip) : m_value{ip} { }

  [[nodiscard]] constexpr inline std::uint32_t IPv4::value() const {
    return this->m_value;
  }

  std::uint16_t IPv4::first_octet() const {
    return static_cast<std::uint16_t>((this->m_value >> 24u) & 0xFF);
  }

  std::string IPv4::to_string() const { 
    std::ostringstream oss;
    oss << ((this->m_value >> static_cast<unsigned>(IPv4::CIDRNotation::C)) & 255u) << "."
        << ((this->m_value >> static_cast<unsigned>(IPv4::CIDRNotation::B)) & 255u) << "."
        << ((this->m_value >> static_cast<unsigned>(IPv4::CIDRNotation::A)) & 255u) << "."
        << ((this->m_value >> 0u) & 255u);
    return oss.str();
  }

  IPv4 IPv4::from_string(std::string const &ip) {
    std::istringstream iss(ip);
    std::string out_token;
    std::uint32_t result = 0;

    for(std::size_t i = 0; i < 4; ++i) {
      if(!std::getline(iss, out_token, '.')) {
        throw std::runtime_error("Invalid IPv4 format");
      }
      
      std::uint32_t octet = std::stoul(out_token, nullptr, 10);
      if(octet < 0 || octet > std::numeric_limits<std::uint8_t>::max()) {
        throw std::runtime_error("Invalid IPv4 octect");
      }

      result = (result << 8) | octet;
    }

    return IPv4(result);
  }


}