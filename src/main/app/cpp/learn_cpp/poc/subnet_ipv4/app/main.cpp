
#include <cstdio>
#include <cinttypes>

#include "learn_cpp/poc/subnet_ipv4/app/engine.h"

namespace subnet_ipv4 {
  namespace app = learn_cpp::poc::subnet_ipv4::app;
}

int main(int arg_c, char **arg_v) {
  subnet_ipv4::app::Engine::test();

  std::printf("::: 0x%0*" PRIXPTR ",\n",
    static_cast<int>(sizeof(std::uintptr_t)*2),
    reinterpret_cast<std::uintptr_t>(static_cast<int (*)(int,char**)>(main)));
  return 0;
}