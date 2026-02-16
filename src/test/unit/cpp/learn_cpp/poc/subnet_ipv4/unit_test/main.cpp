
#include "learn_cpp/poc/subnet_ipv4//unit_test/ipv4.test.h"
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>
#include <unordered_map>
#include <utility>
#include "learn_cpp/poc/subnet_ipv4/unit_test/util/Command.h"

namespace subnet_ipv4 {
  namespace unit_test = learn_cpp::poc::subnet_ipv4::unit_test;
}

typedef subnet_ipv4::unit_test::util::Command Command_t;

std::unordered_map<std::string, Command_t> const cmd_map = {
{cmd_option_str(Command_t::Compact),  Command_t::Compact},
{cmd_option_str(Command_t::IPv4TestI), Command_t::IPv4TestI},
{cmd_option_str(Command_t::IPv4TestII), Command_t::IPv4TestII}
};

[[nodiscard]] std::string option_str() {
  std::ostringstream oss;
  oss << "Options: ";
  for(std::pair<std::string const,Command_t> cmd_pair : cmd_map) {
    oss <<  cmd_pair.first << " | ";
  }
  return oss.str();
}

int main(int arg_c, char **arg_v) {
  char option[100];

  if (arg_c != 2) {
    std::cout << "::: Warning: option not specified, default to (" << Command_t::Compact << ")\n";
    std::cout << "::: " << option_str() << "\n";
    strcpy_s(option, cmd_option_str(Command_t::Compact));
  } else {
    strcpy_s(option, arg_v[1]);
  }

  std::unordered_map<std::string, Command_t>::const_iterator const it =
      cmd_map.find(option);
  Command_t cmd = (it != cmd_map.end()) ? it->second : Command_t::Invalid;

  switch (cmd) {
  case Command_t::Compact:
    // REM: TODO
    subnet_ipv4::unit_test::test_ipv4();
    subnet_ipv4::unit_test::test_ipv4_ii();
    break;
  case Command_t::IPv4TestI:
    subnet_ipv4::unit_test::test_ipv4();
    break;
  case Command_t::IPv4TestII:
    subnet_ipv4::unit_test::test_ipv4_ii();
    break;
  default:
    throw std::runtime_error(
        "::: Invalid options. " + std::string(option_str()));
  }
  return 0;
}