#pragma once

#ifndef BOONDI_SRC_MAIN_EXAMPLE_REFLECTION_REFL_HPP_
#define BOONDI_SRC_MAIN_EXAMPLE_REFLECTION_REFL_HPP_
#include <boost/pfr.hpp>
#include <string>
#include <vector>
#include "utils/Log.hpp"
namespace grkl {
class C1 {
  int i;
  float* j;
  std::string k;
};

class C2 {
  std::vector<int> v;
};

class Refl {
inline static void boostPfr() {

}
};
}
#endif //BOONDI_SRC_MAIN_EXAMPLE_REFLECTION_REFL_HPP_
