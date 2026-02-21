
#include "learn_cpp/poc/subnet_ipv4//unit_test/ipv4.test.h"
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include <string>
#include <unordered_map>
#include <utility>
#include "learn_cpp/poc/subnet_ipv4/unit_test/subnet_calc.test.h"
#include "learn_cpp/poc/subnet_ipv4/unit_test/util/Command.h"

namespace subnet_ipv4 {
  namespace unit_test = learn_cpp::poc::subnet_ipv4::unit_test;
}

typedef subnet_ipv4::unit_test::util::Command Command_t;

int main(int arg_c, char **arg_v) {
  char option[100];

  if (arg_c != 2) {
    std::cout << "::: Warning: option not specified, default to (" << Command_t::Compact << ")\n";
    std::cout << "::: " << subnet_ipv4::unit_test::util::all_option_str() << "\n";
    strcpy_s(option, cmd_option_str(Command_t::Compact));
  } else {
    strcpy_s(option, arg_v[1]);
  }

  std::unordered_map<std::string, Command_t>::const_iterator const it =
      subnet_ipv4::unit_test::util::CMD_MAP.find(option);
  Command_t cmd = (it != subnet_ipv4::unit_test::util::CMD_MAP.end()) ? it->second : Command_t::Invalid;

  // switch (cmd) {
  // case Command_t::Compact:
  //   // REM: TODO
  //   subnet_ipv4::unit_test::test_ipv4();
  //   subnet_ipv4::unit_test::test_ipv4_ii();
  //   break;
  // case Command_t::IPv4TestI:
  //   subnet_ipv4::unit_test::test_ipv4();
  //   break;
  // case Command_t::IPv4TestII:
  //   subnet_ipv4::unit_test::test_ipv4_ii();
  //   break;
  // case Command_t::SubnetCalcI:
  //   subnet_ipv4::unit_test::subnet_calc_test_i();
  //   break;
  // default:
  //   throw std::runtime_error(
  //       "::: Invalid options. " + std::string(option_str()));
  // }

  if(Command_t::Compact == cmd || Command_t::IPv4TestI == cmd) {
    subnet_ipv4::unit_test::test_ipv4();
  }
  if(Command_t::Compact == cmd || Command_t::IPv4TestII == cmd) {
    subnet_ipv4::unit_test::test_ipv4_ii();
  }
  if(Command_t::Compact == cmd || Command_t::SubnetCalcI == cmd) {
    subnet_ipv4::unit_test::subnet_calc_test_i();
  }
  else{
    throw std::runtime_error(
        "::: Invalid options. " + std::string(subnet_ipv4::unit_test::util::all_option_str()));
  }

  return 0;
}