#pragma once

#ifndef BOONDI_SRC_MAIN_CONSTANTS_DBCONSTANTS_HPP_
#define BOONDI_SRC_MAIN_CONSTANTS_DBCONSTANTS_HPP_
#include <string>
namespace grkl {
using namespace std;
struct DBConstants {
  inline static string const UNKNOWN = "UNKNOWN";
  inline static string const INTEGER = "INTEGER";
  inline static string const NUMERIC = "NUMERIC";
  inline static string const REAL = "REAL";
  inline static string const VARCHAR = "VARCHAR";
  inline static string const COMPOSITE = "__COMPOSITE__";
};
}

#endif //BOONDI_SRC_MAIN_CONSTANTS_DBCONSTANTS_HPP_
