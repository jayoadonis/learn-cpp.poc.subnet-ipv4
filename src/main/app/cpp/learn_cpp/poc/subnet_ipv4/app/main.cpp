
#include <cstddef>
#include <cstdio>
#include <cinttypes>
#include <iostream>
#include <string>
#include <cstring>
#include <limits>

#include "learn_cpp/poc/subnet_ipv4/app/engine.h"

namespace subnet_ipv4 {
  namespace app = learn_cpp::poc::subnet_ipv4::app;
}

void func_one(char *c_str) {
  std::cout << "::: func_one(char*)V: " << c_str << ", sizeof: " << sizeof(c_str) << ", len: " << std::strlen(c_str) << "\n";
}
template<unsigned int N>
void func_two(char (&c_str)[N]) {
  std::cout << "::: func_two<N:unsigned int>(char (&)[N])V: " << c_str << ", sizeof: " << sizeof(c_str) << ", len: " << std::strlen(c_str) << "\n";
}

int main(int arg_c, char **arg_v) {
  subnet_ipv4::app::Engine::test();
  std::string sentence;
  char c_sentence[101];
  std::getline(std::cin, sentence);
  std::cin.get(c_sentence, 101);
  std::cout << "::: " << sentence << ", sizeof: " << sizeof(sentence) << ", len: " << sentence.length() << "\n";
  std::cout << "::: " << c_sentence << ", sizeof: " << sizeof(c_sentence) << ", len: " << std::strlen(c_sentence) << "\n";

  func_one(c_sentence);
  func_two(c_sentence);

  char log[1023 + 1];
  std::int32_t len_log = std::snprintf(log, sizeof(log), "::: %s, len: %zu\n",
    c_sentence, std::strlen(c_sentence));
  if(len_log >= 0 && len_log < static_cast<int>(sizeof(log))) {
    std::fputs(log, stdout);
  }

  // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::printf("::: 0x%0*" PRIXPTR ",\n",
    static_cast<int>(sizeof(std::uintptr_t)*2),
    reinterpret_cast<std::uintptr_t>(static_cast<int (*)(int,char**)>(main)));
  return 0;
}