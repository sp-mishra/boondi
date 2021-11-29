#pragma once

#ifndef BOONDI_SOCIEXAMPLES_HPP
#define BOONDI_SOCIEXAMPLES_HPP

#include "soci/soci.h"
#include "soci/sqlite3/soci-sqlite3.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <exception>
#include "utils/Log.hpp"

namespace grkl {
  using namespace soci;
  using namespace std;

  class SOCIExamples {
  private:
  public:
    void execute() {
      try {
        session sql(sqlite3, "bun.db");
        vector<string> names = {"test1", "test2", "test3"};
        int count;
        sql << "CREATE TABLE IF NOT EXISTS phonebook (name TEXT PRIMARY KEY, phone TEXT)";
        for(auto name : names) {
          sql << "INSERT INTO phonebook (name, phone) VALUES (:name, :phone)", use(name), use(name);
        }
        sql << "select count(*) from phonebook", into(count);

        info("We have {} entries in the phonebook", count);

        for (auto name : names) {
          string phone;
          indicator ind;
          sql << "select phone from phonebook where name = :name",
            into(phone, ind), use(name);

          if (ind == i_ok) {
            info("The phone number is {}", phone);
          } else {
            info("There is no phone for {}", name);
          }
        }
      } catch (exception const &e) {
        error("Error: {}", e.what());
      }
    }
  };
}
#endif //BOONDI_SOCIEXAMPLES_HPP
