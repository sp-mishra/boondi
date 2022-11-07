#pragma once
#ifndef STRINGUTILS_HPP
#define STRINGUTILS_HPP
namespace grkl {
class StringUtils {
 public:
  static char intToChar(int i) {
    char r{0};
    switch(i) {
      case 0: r = '0';break;
      case 1: r = '1';break;
      case 2: r = '2';break;
      case 3: r = '3';break;
      case 4: r = '4';break;
      case 5: r = '5';break;
      case 6: r = '6';break;
      case 7: r = '7';break;
      case 8: r = '8';break;
      case 9: r = '9';break;
      default: r = 0;
    }
    return r;
  }
};
}
#endif // STRINGUTILS_HPP
  