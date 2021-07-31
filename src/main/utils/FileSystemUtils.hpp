#pragma once
#ifndef BOONDI_SRC_MAIN_UTILS_FILESYSTEMUTILS_HPP_
#define BOONDI_SRC_MAIN_UTILS_FILESYSTEMUTILS_HPP_
#include <filesystem>
#include <fstream>
#include <sstream>
#include <models/Status.hpp>

namespace grkl {
class FileSystemUtils {
 public:
  static Status readFileToString(filesystem::path const &path, string &content) {
    namespace fs = filesystem;
    Status status;
    if (fs::exists(path) && fs::is_regular_file(path)) {
      const ifstream file(path);
      if (file.good()) {
        auto ss = ostringstream{};
        ss << file.rdbuf();
        content = ss.str();
        status.setMessage(Consts::SUCCESS);
        status.setSuccess(true);
      }
    }
    return status;
  }
};
}
#endif //BOONDI_SRC_MAIN_UTILS_FILESYSTEMUTILS_HPP_
