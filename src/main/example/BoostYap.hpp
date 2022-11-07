#pragma once
#ifndef BOOSTYAP_HPP
#define BOOSTYAP_HPP
#include "utils/Log.hpp"
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

TEST_CASE("vectors can be sized and resized", "[vector]") {
  std::vector<int> v(5);

  REQUIRE(v.size() == 5);
  REQUIRE(v.capacity() >= 5);

  SECTION("resizing bigger changes size and capacity") {
    v.resize(10);

    REQUIRE(v.size() == 10);
    REQUIRE(v.capacity() >= 10);
  }
  SECTION("resizing smaller changes size but not capacity") {
    v.resize(0);

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() >= 5);
  }
  SECTION("reserving bigger changes capacity but not size") {
    v.reserve(10);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 10);
  }
  SECTION("reserving smaller does not change size or capacity") {
    v.reserve(0);

    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() >= 5);
  }
}

TEST_CASE("General Test", "[general]") {
  std::vector<int> v(5);
  REQUIRE(v.size() == 5);
}

namespace grkl {
class BoostYap {
 public:
  void execute() { info("{}", "BoostYap"); }
};
}  // namespace grkl
#endif  // BOOSTYAP_HPP
