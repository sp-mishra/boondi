#include "OpenGLUtils.hpp"
#include "example/OpenCLExamples.hpp"
#include <argh.h>

#include "bun/DBConstants.hpp"
#include "constants/GeneralConstants.hpp"

int main(int argc, char **argv) {
  argh::parser cmdl(argv);
  grkl::OpenCLExamples::runExamples();
  return 0;
}