
#include "learn_cpp/poc/subnet_ipv4//unit_test/test_ipv4.h"
#include <cstring>
#include <list>
#include <map>
#include <stdexcept>
#include <string.h>
#include <unordered_map>

namespace subnet_ipv4 {
  namespace unit_test = learn_cpp::poc::subnet_ipv4::unit_test;
}

int main(int arg_c, char **arg_v) {
  char option[12];

  if(arg_c != 2 ) {
    std::cout << "::: Warning: option not specified, default to (--all)\n";
    std::cout << "::: Options: --all | --test-i | --test-ii\n";
    strcpy_s(option, "--all");
  }
  else {
    strcpy_s(option, arg_v[1]);
  }
  
  enum class Command: unsigned int { Invalid, All, TestI, TestII };
  std::unordered_map<std::string,Command> const cmd_map = {
      { "--all", Command::All },
      { "--test-i", Command::TestI },
      { "--test-ii", Command::TestII }
  };

  std::unordered_map<std::string,Command>::const_iterator const it 
    = cmd_map.find(option);
  Command cmd = (it != cmd_map.end()) ? it->second : Command::Invalid;

  switch(cmd) {
    case Command::All:
      //REM: TODO
      subnet_ipv4::unit_test::test_ipv4();
      subnet_ipv4::unit_test::test_ipv4_ii();
      break;
    case Command::TestI:
      subnet_ipv4::unit_test::test_ipv4();
      break;
    case Command::TestII:
      subnet_ipv4::unit_test::test_ipv4_ii();
      break;
    default:
      throw std::runtime_error("::: Invalid options. Options: --all | --test-i | --test-ii");
  }
  return 0;
}