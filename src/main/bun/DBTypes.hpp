#pragma once

#ifndef BOONDI_SRC_MAIN_BUN_DBTYPES_HPP_
#define BOONDI_SRC_MAIN_BUN_DBTYPES_HPP_
#include "DBConstants.hpp"
/// @class DBPrimitiveTypes
/// @brief This Enum gives all the types that are supported as of now.
/// @details For any C++ type that needs to be supported it has to be
///          added here and then the Class specialization needs to be
///          done.
namespace grkl {
template<typename T>
struct DBTypes {
  inline static std::string const TypeName = DBConstants::UNKNOWN;
};

template<>
struct DBTypes<int> {
  inline static std::string const TypeName = DBConstants::INTEGER;
};

template<>
struct DBTypes<unsigned int> {
  inline static std::string const TypeName = DBConstants::INTEGER;
};

template<>
struct DBTypes<char> {
  inline static std::string const TypeName = DBConstants::INTEGER;
};

template<>
struct DBTypes<unsigned char> {
  inline static std::string const TypeName = DBConstants::INTEGER;
};

template<>
struct DBTypes<long long > {
  inline static std::string const TypeName = DBConstants::INTEGER;
};

template<>
struct DBTypes<float> {
  inline static std::string const TypeName = DBConstants::REAL;
};

template<>
struct DBTypes<double> {
  inline static std::string const TypeName = DBConstants::REAL;
};

template<>
struct DBTypes<std::string> {
  inline static std::string const TypeName = DBConstants::VARCHAR;
};

template<>
struct DBTypes<std::wstring> {
  inline static std::string const TypeName = DBConstants::VARCHAR;
};
}
#endif //BOONDI_SRC_MAIN_BUN_DBTYPES_HPP_
