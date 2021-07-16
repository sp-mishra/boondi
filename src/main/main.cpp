#include "OpenGLUtils.hpp"
#include "example/OpenCLExamples.hpp"
#define ANKERL_NANOBENCH_IMPLEMENT
#include <nanobench.h>
#include <boost/proto/proto.hpp>

int main(int argc, char **argv) {
  grkl::OpenCLExamples openCLExamples;
//  ankerl::nanobench::Bench().minEpochIterations(1085).run("OpenCL: Print Versions", [&] {
//    openCLExamples.printOpenClVersions();
//  });

  const std::size_t numItr = 1085;
//  const std::size_t numItr = 500;
  ankerl::nanobench::Bench().minEpochIterations(numItr*17).run("OpenCL: Compute Sqrt", [&] {
    openCLExamples.computeCLSqrRoot();
  });

  ankerl::nanobench::Bench().minEpochIterations(numItr).run("General: Compute Sqrt", [&] {
    openCLExamples.computeSqrRoot();
  });

  openCLExamples.finalize();
  ankerl::nanobench::Bench().minEpochIterations(numItr).run("General: Some double ops", [&] {
    double d = 1.0;
    d += 1.0 / d;
    if (d > 5.0) {
      d -= 5.0;
    }
    ankerl::nanobench::doNotOptimizeAway(d);
  });

  return 0;
}