#pragma once
#ifndef PEGTLMAIN_HPP
#define PEGTLMAIN_HPP
#include "utils/Log.hpp"
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <tao/pegtl.hpp>

namespace grkl {
class PegMain {
 public:
  void execute() {
    using namespace tao::pegtl;
    namespace gm = tao::pegtl;
  }
};
}

#endif // PEGTLMAIN_HPP
