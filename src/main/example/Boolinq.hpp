#pragma once
#ifndef BOOLINQ_HPP
#define BOOLINQ_HPP
#include <boolinq.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

#include "utils/Log.hpp"
#include "utils/StringUtils.hpp"

namespace grkl {
using namespace std;
using namespace boolinq;
class Boolinq {
 private:
  template <class T>
  string getResults(T& src) {
    auto dest = from(src)
                    .where([](auto a) { return a % 2 == 1; })       // 1,3,5,7
                    .select([](auto a) { return a * 2; })           // 2,6,10,14
                    .where([](auto a) { return a > 2 && a < 12; })  // 6,10
                    .toStdVector();
    return toString(dest);
  }

  template <typename T, size_t N>
  string getResults(T (&src)[N]) {
    auto dest = from(src)
                    .where([](auto a) { return a % 2 == 1; })       // 1,3,5,7
                    .select([](auto a) { return a * 2; })           // 2,6,10,14
                    .where([](auto a) { return a > 2 && a < 12; })  // 6,10
                    .toStdVector();
    return toString(dest);
  }

  template <class T>
  string toString(T const& dest) {
    string result;
    for (auto d : dest) {
      result += fmt::format(", {}", d);
    }
    return result;
  }

 public:
  void execute() {
    int src1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> src2 = {1, 2, 3, 4, 5, 6, 7, 8};
    auto dest = from(src1)
                    .where([](int a) { return a % 2 == 1; })       // 1,3,5,7
                    .select([](int a) { return a * 2; })           // 2,6,10,14
                    .where([](int a) { return a > 2 && a < 12; })  // 6,10
                    .toStdVector();

    // dst items: 6,10
    // Now add the last element with no delimiter
    auto dest2 = from(src2)
                     .where([](int a) { return a % 2 == 1; })       // 1,3,5,7
                     .select([](int a) { return a * 2; })           // 2,6,10,14
                     .where([](int a) { return a > 2 && a < 12; })  // 6,10
                     .toStdVector();

    info("dest1: {}", getResults(src1));
    info("dest2: {}", getResults(src2));
  }
};
}  // namespace grkl
#endif  // BOOLINQ_HPP
