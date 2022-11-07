#pragma once
#ifndef HYRISESQLPARSER_HPP
#define HYRISESQLPARSER_HPP
#include "utils/Log.hpp"
#include <SQLParser.h>

namespace grkl {
class HyriseSQLParser {
 public:
  void execute() {
    valid();
    invalid();
  }

 private:
  void invalid() {
    using namespace std;
    using namespace hsql;
    info("===SQLParser In-Valid===");
    const string query = "(SELECT * students INTERSECT SELECT * FROM students_2) UNION SELECT * FROM students_3 ORDER BY grade ASC";
    SQLParserResult result;
    SQLParser::parse(query, &result);
    if(!result.isValid()) {
      error("Line: {}, Column: {}", result.errorLine(), result.errorColumn());
    }
  }

  void valid() {
    using namespace std;
    using namespace hsql;
    info("===SQLParser Valid===");
    const string query = "(SELECT * FROM students INTERSECT SELECT * FROM students_2) UNION SELECT * FROM students_3 ORDER BY grade ASC";
    SQLParserResult result;
    SQLParser::parse(query, &result);

    if (result.isValid() && result.size() > 0) {
      const SQLStatement* statement = result.getStatement(0);
      if (statement->isType(hsql::kStmtSelect)) {
        const auto* select = static_cast<const SelectStatement*>(statement);
        if(select->selectList != nullptr) {
          std::vector<Expr*> expressions = *select->selectList;
          for(auto expression : expressions) {
            if(expression) {
              auto e = *expression;
              info("Expression name: {}", e.getName());
            }
          }
        }
        info("length: {}", select->stringLength);
      }
    }
  }
};
}
#endif // HYRISESQLPARSER_HPP
