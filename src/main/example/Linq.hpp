#pragma once

#ifndef BOONDI_LINQ_HPP
#define BOONDI_LINQ_HPP

#include <linq.h>

#include <string>
#include <vector>

#include "utils/Log.hpp"

namespace grkl {
class Linq {
 public:
  void execute() {
    using namespace linq;
    using namespace std;
    struct student_t {
      string last_name;
      vector<int> scores;
    };

    vector<student_t> students = {{"Omelchenko", {97, 72, 81, 60}},
                                  {"O'Donnell", {75, 84, 91, 39}},
                                  {"Mortensen", {88, 94, 65, 85}},
                                  {"Garcia", {97, 89, 85, 82}},
                                  {"Beebe", {35, 72, 91, 70}}};
    // GRKL: Linq transformation
    //      auto scores = LINQ(from(student, students)
    //                           from(score, student.scores)
    //                           where(score > 90)
    //                           select(std::make_pair(student.last_name,
    //                           score)));

    auto scores =
        LINQ(from(student, students) from(score, student.scores)
                 where(score > 90) select(make_pair(student.last_name, score)));

    auto scores1 =
        students |
        linq::query::select_many() + [&](decltype(linq::query::make_const(
                                         *(boost::begin(students)))) student) {
          return (student.scores |
                  linq::where([&](decltype(linq::query::make_const(
                                  *(boost::begin(student.scores)))) score) {
                    return (score > 90);
                  }) |
                  linq::select([&](decltype(linq::query::make_const(
                                   *(boost::begin(student.scores)))) score) {
                    return (make_pair(student.last_name, score));
                  }));
        };

    for (const auto& x : scores) {
      info("{} score: {}", x.first.c_str(), x.second);
    }

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};
    auto r = numbers | linq::where([](int x) { return x > 2; }) |
             linq::select([](int x) { return x * x; });
    info("Value of: {}", r);

    struct person {
      string name;
      int age;

      person() {}

      person(string name, int age) : name(name), age(age) {}
    };

    vector<person> people = {person("Tom", 25), person("Bob", 22),
                             person("Terry", 37), person("Jerry", 22)};
    //  { "Jerry", "Bob", "Tom", "Terry" }
    auto q =
        LINQ(from(p, people) orderby(ascending p.age, descending p.name) select(p.name));

    auto q1 =
        people |
        linq::order_by([&](decltype(linq::query::make_const(
                           *(boost::begin(people)))) p) { return (p.age); }) |
        linq::then_by_descending(
            [&](decltype(linq::query::make_const(*(boost::begin(people)))) p) {
              return (p.name);
            }) |
        linq::select([&](decltype(linq::query::make_const(
                         *(boost::begin(people)))) p) { return (p.name); });
    info("q: {}", q);
    info("Execution finished");
  }
};
}  // namespace grkl

#endif  // BOONDI_LINQ_HPP
