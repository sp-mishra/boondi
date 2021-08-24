#pragma once
#ifndef BOONDI_SRC_MAIN_UTILS_LOG_HPP_
#define BOONDI_SRC_MAIN_UTILS_LOG_HPP_

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace grkl {
/////////////////////////////////////////////////
/// @fn l
/// @brief Returns the logger
///        This will be logging to the logs. It uses spdlog to log to file
/// @return Returns the logger.
/////////////////////////////////////////////////
inline spdlog::logger &l() {
//  static const std::size_t q_size = 1048576; //queue size must be power of 2
  //spdlog::set_async_mode( q_size );
//        static const auto ret = spdlog::basic_logger_mt( "bun_logger",
//                                                   "query_log.txt" );
  // create color multi threaded logger
  static auto console = spdlog::stdout_color_mt("console");
  static auto err_logger = spdlog::stderr_color_mt("stderr");
  static bool initialized = false;
  if (!initialized) {
    spdlog::set_pattern("***[%l] [%H:%M:%S %z] [thread %t] %v ***");
    initialized = true;
  }

  return *spdlog::get("console");
}

template<typename T>
inline static void info(const T &msg) {
  l().info(msg);
}

template<typename FormatString, typename... Args>
inline void info(FormatString &fmt, const Args &... args) {
  l().info(fmt, args...);
}

template<typename T>
inline static void warn(const T &msg) {
  l().warn(msg);
}

template<typename FormatString, typename... Args>
inline void warn(const FormatString &fmt, const Args &... args) {
  l().warn(fmt, args...);
}

template<typename T>
inline static void debug(const T &msg) {
  l().debug(msg);
}

template<typename FormatString, typename... Args>
inline void debug(const FormatString &fmt, const Args &... args) {
  l().debug(fmt, args...);
}

template<typename T>
inline static void error(const T &msg) {
  l().error(msg);
}

template<typename FormatString, typename... Args>
inline void error(const FormatString &fmt, const Args &... args) {
  l().error(fmt, args...);
}

template<typename T>
inline static void critical(const T &msg) {
  l().critical(msg);
}

template<typename FormatString, typename... Args>
inline void critical(const FormatString &fmt, const Args &... args) {
  l().critical(fmt, args...);
}
}
#endif //BOONDI_SRC_MAIN_UTILS_LOG_HPP_
