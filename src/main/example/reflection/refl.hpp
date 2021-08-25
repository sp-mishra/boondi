#pragma once

#ifndef BOONDI_SRC_MAIN_EXAMPLE_REFLECTION_REFL_HPP_
#define BOONDI_SRC_MAIN_EXAMPLE_REFLECTION_REFL_HPP_
#include <boost/pfr.hpp>
#include <nameof.hpp>
#include <string>
#include <vector>
#include "utils/Log.hpp"

namespace grkl {
  class C1 {
  public:
    int i;
    float *j;
    std::string k;
  };

  class C2 {
  public:
    std::vector<int> v;
  };

  class Refl {
  public:
    inline static void boostPfr() {
      C1 *c1;
      C2 *c2;
      grkl::info("NAMEOF(c1->i): {}", NAMEOF(c1->i));
      grkl::info("NAMEOF(c1->j): {}", NAMEOF(c1->j));
      grkl::info("NAMEOF(c1->k) : {}", NAMEOF(c1->k));
      grkl::info("NAMEOF(c1) {}", NAMEOF(c1));
      grkl::info("NAMEOF_TYPE_EXPR(C1::i): {}", NAMEOF_TYPE_EXPR(C1::i));
      grkl::info("NAMEOF_TYPE_EXPR(C1::j) : {}", NAMEOF_TYPE_EXPR(C1::j));
      grkl::info("NAMEOF_TYPE_EXPR(C1::k)  {}", NAMEOF_TYPE_EXPR(C1::k));
      grkl::info("NAMEOF_TYPE_EXPR(C1::k)  {}", NAMEOF_TYPE_EXPR(C1::k));
      grkl::info("NAMEOF_TYPE_EXPR(c1): {}", NAMEOF_TYPE_EXPR(c1));
      grkl::info("NAMEOF_FULL(C1::i) : {}", NAMEOF_FULL(C1::i));
      grkl::info("NAMEOF_FULL(C1::j) : {}", NAMEOF_FULL(C1::j));
      grkl::info("NAMEOF_FULL(C1::k) {}",  NAMEOF_FULL(C1::k));
      grkl::info("NAMEOF_FULL(C2::v): {}", NAMEOF_FULL(C2::v));
      grkl::info("NAMEOF_FULL(c1) : {}", NAMEOF_FULL(c1));
    }
  };
}
#endif //BOONDI_SRC_MAIN_EXAMPLE_REFLECTION_REFL_HPP_