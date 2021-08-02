#pragma once

#ifndef BOONDI_SRC_MAIN_UTILS_SINGLETON_HPP_
#define BOONDI_SRC_MAIN_UTILS_SINGLETON_HPP_

///////////////////////////////////////////////////////////////////////////////
/// @file Singleton.hpp
/// @author BrainlessLabs
/// @version 0.1
/// @brief Helper class for creating a singleton.
///////////////////////////////////////////////////////////////////////////////

#include <boost/core/noncopyable.hpp>

namespace grkl {
/////////////////////////////////////////////////
/// @class Singleton
/// @brief Helper class to create a singleton.
/// @details Example usage:
///          struct MakeMeSingleton : public ::grkl::Singleton<MakeMeSingleton>
///          {};
/////////////////////////////////////////////////
template<class T>
class Singleton : public boost::noncopyable {
 public:
  static T &i() {
    static T _me;
    return _me;
  }
};
}

#endif //BOONDI_SRC_MAIN_UTILS_SINGLETON_HPP_
