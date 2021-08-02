#pragma once

#ifndef BOONDI_SRC_MAIN_UTILS_TYPEUTILS_HPP_
#define BOONDI_SRC_MAIN_UTILS_TYPEUTILS_HPP_
#include <type_traits>
namespace grkl {
/////////////////////////////////////////////////
/// @class remove_cvref
/// @brief Strip all the qualifiers like const, volatile, removes reference.
/////////////////////////////////////////////////
template< class T >
struct remove_cvref {
  using type = std::remove_cv_t<std::remove_reference_t<T>>;
};

/////////////////////////////////////////////////
/// @class StripQualifiersAndMakePointer
/// @brief Strip all the qualifiers like const, volatile, removes reference and adds a pointer.
/////////////////////////////////////////////////
template<typename T>
struct StripQualifiersAndMakePointer {
  using type = typename std::add_pointer<typename remove_cvref<T>::type>::type;
};
}
#endif //BOONDI_SRC_MAIN_UTILS_TYPEUTILS_HPP_
