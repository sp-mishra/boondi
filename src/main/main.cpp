#include "OpenGLUtils.hpp"
#include "example/OpenCLExamples.hpp"
#include "example/reflection/refl.hpp"
#include <argh.h>
#include "utils/Log.hpp"
#include "bun/DBConstants.hpp"
#include "constants/GeneralConstants.hpp"

int main(int argc, char **argv) {
//  argh::parser cmdl(argv);
  grkl::Refl::boostPfr();
//  grkl::OpenCLExamples::runExamples();
  return 0;
}