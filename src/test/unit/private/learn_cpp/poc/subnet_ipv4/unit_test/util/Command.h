#ifndef __LEARNCPP_POC_SUBNETIPV4_UNITTEST_UTIL_COMMAND_H
#define __LEARNCPP_POC_SUBNETIPV4_UNITTEST_UTIL_COMMAND_H

#include <ostream>

namespace learn_cpp::poc::subnet_ipv4::unit_test::util {
  enum class Command : unsigned int {
    Invalid,
    Compact,
    IPv4TestI,
    IPv4TestII,
  };
  [[nodiscard]] char const *cmd_option_str(Command const &cmd) {
    switch(cmd) {
      case Command::Compact: return "--compact";
      case Command::IPv4TestI: return "--ipv4-test-i";
      case Command::IPv4TestII: return "--ipv4-test-ii";
      default: return "Invalid";
    }
  }
  std::ostream &operator<<(std::ostream &os, Command const &cmd) {
    return os << cmd_option_str(cmd);
  }
}
#endif