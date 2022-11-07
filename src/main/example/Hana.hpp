#pragma once
#ifndef HANA_HPP
#define HANA_HPP
#include <boost/hana.hpp>
#include "utils/Log.hpp"
#include <cassert>
#include <iostream>
#include <string>

namespace grkl {
class Hana {
 public:
  void execute() {
    info("{} Start", "Hana");
    struct Fish { std::string name; };
    struct Cat  { std::string name; };
    struct Dog  { std::string name; };

    namespace hana = boost::hana;
    using namespace std;
    using namespace hana::literals;
    const auto animals = hana::make_tuple(Fish{"Nemo"}, Cat{"Garfield"}, Dog{"Snoopy"});
    // Access tuple elements with operator[] instead of std::get.
    Cat garfield = animals[1_c];
    // Perform high level algorithms on tuples (this is like std::transform)
    auto names = hana::transform(animals, [](auto a) {
      return a.name;
    });
    auto has_name = hana::is_valid([](auto&& x) -> decltype((void)x.name) { });
    info("has_name(garfield): {}", has_name(garfield));
    info("has_name(1): {}", has_name(1));
    info("{} End", "Hana");
  }
};
}
#endif // HANA_HPP
