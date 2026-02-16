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
    return static_cast<std::uint16_t>((this->m_value >> 24) & 0xFF);
  }

  std::string IPv4::to_string() const {
    std::ostringstream oss;
    oss << ((this->m_value >> 24) & 0xFF) << "."
        << ((this->m_value >> 16) & 0xFF) << "."
        << ((this->m_value >> 8) & 0xFF) << "."
        << ((this->m_value >> 0) & 0xFF);

    return oss.str();
  }

  IPv4 IPv4::from_string(std::string const &ip) {
    std::istringstream iss(ip);
    std::string token;
    std::uint32_t result = 0;

    for(std::size_t i = 0; i < 4; ++i) {
      if(!std::getline(iss, token, '.')) {
        throw std::runtime_error("Invalid IPv4 format");
      }
      
      std::int32_t octet = std::stoi(token);
      if(octet < 0 || octet > std::numeric_limits<std::uint8_t>::max()) {
        throw std::runtime_error("Invalid IPv4 octect");
      }

      result = (result << 8) | static_cast<std::uint32_t>(octet);
    }

    return IPv4(result);
  }


}