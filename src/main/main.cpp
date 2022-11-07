#include "OpenGLUtils.hpp"
#include "example/OpenCLExamples.hpp"
#include "example/Linq.hpp"
#include "example/Boolinq.hpp"
#include "example/reflection/refl.hpp"
#include "example/SOCIExamples.hpp"
#include "example/HyriseSQLParser.hpp"
#include <argh.h>
#include "utils/Log.hpp"
#include "bun/DBConstants.hpp"
#include "constants/GeneralConstants.hpp"
#include "example/Hana.hpp"
#include "example/BoostYap.hpp"
#include "example/language/LexyLang.hpp"

int main(int argc, char **argv) {
  using namespace grkl;
  info("===Main Start===");
//  argh::parser cmdl(argv);
//  grkl::Refl::boostPfr();
//  grkl::Linq linq;
////  linq.execute();

//  grkl::Boolinq boolinq;
////  boolinq.execute();

//  grkl::HyriseSQLParser hyriseSqlParser;
////  hyriseSqlParser.execute();

//  grkl::Hana hana;
//  hana.execute();

//  grkl::BoostYap boostYap;
//  boostYap.execute();

//  int result = Catch::Session().run( argc, argv );

//  grkl::SOCIExamples sociExamples;
//  sociExamples.execute();

  grkl::OpenCLExamples::runExamples();
  info("===Main End===");
  return result;
}
