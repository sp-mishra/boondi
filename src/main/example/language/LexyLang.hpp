#pragma once
#include "lexy/input/string_input.hpp"
#ifndef LEXYLANG_HPP
#define LEXYLANG_HPP
#include "utils/Log.hpp"
#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cstdint>
#include <lexy/action/parse.hpp>
#include <lexy/callback.hpp>
#include <lexy/dsl.hpp>
#include <lexy/input/string_input.hpp>
#include <lexy_ext/compiler_explorer.hpp>
#include <lexy_ext/report_error.hpp>

namespace grkl {
namespace dsl = lexy::dsl;
using namespace std;
struct Color {
  uint8_t r, g, b;
};

struct channel {
  static constexpr auto rule =
      dsl::integer<std::uint8_t>(dsl::n_digits<2, dsl::hex>);
  static constexpr auto value = lexy::forward<std::uint8_t>;
};

struct color {
  static constexpr auto rule = dsl::hash_sign + dsl::times<3>(dsl::p<channel>);
  static constexpr auto value = lexy::construct<Color>;
};

using production = color;

}  // namespace grkl

TEST_CASE("Check the language strings", "[lang]") {
  using namespace grkl;

  auto good = lexy::zstring_input("#FF00FF");
  REQUIRE(lexy::match<grkl::color>(good) == true);

  auto bad = lexy::zstring_input("#FFF");
  REQUIRE(lexy::match<grkl::color>(bad) == false);

//  auto bad_result = lexy::validate<grkl::color>(bad, lexy_ext::report_error);

  auto good_result = lexy::parse<grkl::color>(good, lexy_ext::report_error);
  if (good_result.has_value()) {
    auto color = good_result.value();
    std::printf("#%02x%02x%02x\n", color.r, color.g, color.b);
  }

  //  error("Errors: {}", result.errors());
}

#endif  // LEXYLANG_HPP
