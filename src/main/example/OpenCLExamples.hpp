#pragma once
#ifndef BOONDI_SRC_MAIN_EXAMPLE_OPENCLEXAMPLES_HPP_
#define BOONDI_SRC_MAIN_EXAMPLE_OPENCLEXAMPLES_HPP_

#include <boost/compute/algorithm/transform.hpp>
#include <boost/compute/container/vector.hpp>
#include <boost/compute/functional/math.hpp>
#include <boost/compute/core.hpp>

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

namespace grkl {
namespace compute = boost::compute;
class OpenCLExamples {
 private:
  compute::device _device;
  std::unique_ptr<compute::context> _context;
  std::unique_ptr<compute::command_queue> _commandQueue;
  std::unique_ptr<std::vector<float>>  _input;
  std::unique_ptr<std::vector<float>> _output;
  std::unique_ptr<compute::vector<float>> _deviceVector;
  const std::size_t inputSize = 100000;

 public:
  OpenCLExamples() {
    _device = compute::system::default_device();
    _context = std::make_unique<compute::context>(_device);
    _commandQueue = std::make_unique<compute::command_queue>(*_context, _device);
    _input = std::make_unique<std::vector<float>>(inputSize);
    _output = std::make_unique<std::vector<float>>(inputSize);
    // create a vector on the device
    _deviceVector = std::make_unique<compute::vector<float>>(inputSize, *_context);
    // transfer data from the host to the device
    compute::copy(
        _input->begin(), _input->end(), _deviceVector->begin(), *_commandQueue
    );
    // generate random data on the host
    std::generate(_input->begin(), _input->end(), rand);
  }

  void printOpenClVersions() {
    // print the device's name and platform
    std::cout << "hello from " << _device.name() << " (platform: " << _device.platform().name() << ")" << std::endl;
  }

  void computeCLSqrRoot() {
    std::vector<float>& host_vector = *_input;
    compute::vector<float>& device_vector = *_deviceVector;
    // calculate the square-root of each element in-place
    compute::transform(
        device_vector.begin(),
        device_vector.end(),
        device_vector.begin(),
        compute::sqrt<float>(),
        *_commandQueue
    );
  }

  void computeSqrRoot() {
    std::vector<float>& input = *_input;
    std::vector<float>& output = *_output;
    // calculate the square-root of each element
    std::transform(input.begin(), input.end(), output.begin(), [](float i) {return std::sqrt(i);});
  }

  void finalize() {
    std::vector<float>& host_vector = *_input;
    compute::vector<float>& device_vector = *_deviceVector;
    // copy values back to the host
    compute::copy(
        device_vector.begin(), device_vector.end(), host_vector.begin(), *_commandQueue
    );
  }
};
}
#endif //BOONDI_SRC_MAIN_EXAMPLE_OPENCLEXAMPLES_HPP_
