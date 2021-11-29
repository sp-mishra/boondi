#pragma once

#ifndef BOONDI_LINQ_HPP
#define BOONDI_LINQ_HPP

#include <vector>
#include <string>
#include <linq.h>
#include "utils/Log.hpp"

namespace grkl {
  class Linq {
  public:
    void execute() {
      struct student_t {
        std::string last_name;
        std::vector<int> scores;
      };

      std::vector<student_t> students =
        {
          {"Omelchenko", {97, 72, 81, 60}},
          {"O'Donnell",  {75, 84, 91, 39}},
          {"Mortensen",  {88, 94, 65, 85}},
          {"Garcia",     {97, 89, 85, 82}},
          {"Beebe",      {35, 72, 91, 70}}
        };
      // GRKL: Linq transformation
//      auto scores = LINQ(from(student, students)
//                           from(score, student.scores)
//                           where(score > 90)
//                           select(std::make_pair(student.last_name, score)));

      auto scores = LINQ(from(student, students)
                           from(score, student.scores)
                           where(score > 90)
                           select(std::make_pair(student.last_name, score)));

//      for (const auto& x : scores) {
//        info("{} score: {}", x.first.c_str(), x.second);
//      }
    }
  };
}

#endif //BOONDI_LINQ_HPP
