#ifndef __LEARNCPP_POC_SUBNETIPV4_UNITTEST_UTIL_COMMAND_H
#define __LEARNCPP_POC_SUBNETIPV4_UNITTEST_UTIL_COMMAND_H

#include <ostream>
#include <sstream>
#include <unordered_map>

namespace learn_cpp::poc::subnet_ipv4::unit_test::util {

  enum class Command : unsigned int {
    Invalid,
    Compact,
    IPv4TestI,
    IPv4TestII,
    SubnetCalcI,
  };

  [[nodiscard]] char const *cmd_option_str(Command const &cmd) {
    switch(cmd) {
      case Command::Compact: return "--compact";
      case Command::IPv4TestI: return "--ipv4-test-i";
      case Command::IPv4TestII: return "--ipv4-test-ii";
      case Command::SubnetCalcI: return "--subnet-calc-test-i";
      default: return "Invalid";
    }
  }

  std::ostream &operator<<(std::ostream &os, Command const &cmd) {
    return os << cmd_option_str(cmd);
  }

  std::unordered_map<std::string, Command> const CMD_MAP = {
  {cmd_option_str(Command::Compact),  Command::Compact},
  {cmd_option_str(Command::IPv4TestI), Command::IPv4TestI},
  {cmd_option_str(Command::IPv4TestII), Command::IPv4TestII},
  {cmd_option_str(Command::SubnetCalcI), Command::SubnetCalcI}
  };

  [[nodiscard]] std::string all_option_str() {
    std::ostringstream oss;
    oss << "Options: ";
    for(std::pair<std::string const,Command> cmd_pair : CMD_MAP) {
      oss <<  cmd_pair.first << " | ";
    }
    return oss.str();
  }
}
#endif