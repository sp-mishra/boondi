cmake_minimum_required(VERSION 3.15)
project(boondi)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(/usr/local/include)
include_directories(src/main/)
include_directories(src/third_party/)
include_directories(src/third_party/nanobench/src/include)
include_directories(src/third_party/doctest)
include_directories(src/third_party/libsimdpp)
include_directories(src/third_party/mnist/include)
include_directories(src/third_party/argh)

find_library(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenCL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

add_subdirectory(src/third_party/raylib)

file(GLOB
        NANO_BENCHMARK_SRC
        "src/third_party/nanobench/src/include/nanobench.h"
        )

file(GLOB
        ARGH_SRC
        "src/third_party/argh/argh.h"
        )

file(GLOB
        MNIST_READER_SRC
        "src/third_party/mnist/include/mnist/*.hpp"
        )

file(GLOB_RECURSE
        LIBSIMD_CPP_SRC
        "src/third_party/libsimdpp/*.h"
        "src/third_party/libsimdpp/*.inl"
#        "src/third_party/libsimdpp/simdpp/core/*.h"
#        "src/third_party/libsimdpp/simdpp/core/*.inl"
#        "src/third_party/libsimdpp/simdpp/core/detail/*.h"
#        "src/third_party/libsimdpp/simdpp/core/detail/*.inl"
#        "src/third_party/libsimdpp/simdpp/detail/*.h"
#        "src/third_party/libsimdpp/simdpp/detail/*.inl"
        "src/third_party/libsimdpp/simdpp/*/*"
        )

file(GLOB
        DOCTEST_SRC
        "src/third_party/doctest/doctest/*.h"
        "src/third_party/doctest/doctest/extensions/*.h"
        "src/third_party/doctest/doctest/parts/*.h"
        "src/third_party/doctest/doctest/parts/*.cpp"
        )

file(GLOB_RECURSE
        BOOST_SOURCE_FILES
        src/third_party/boost/*.h
        src/third_party/boost/*.hpp
        )

file(GLOB
        MAIN_SRC
        "src/main/*.cpp"
        "src/main/*.hpp"
        )

add_executable(boondi
        ${LIBSIMD_CPP_SRC}
        ${ARGH_SRC}
        ${NANO_BENCHMARK_SRC}
        ${MNIST_READER_SRC}
        ${DOCTEST_SRC}
        ${BOOST_SOURCE_FILES}
        ${MAIN_SRC}
        src/main/example/OpenCLExamples.hpp src/main/example/PerfTests.hpp)

find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake
# You could change the QUIET above to REQUIRED and remove this if() clause
# This part downloads raylib and builds it if it's not installed on your system
#if (NOT raylib_FOUND) # If there's none, fetch and build raylib
#    include(FetchContent)
#
#    FetchContent_Declare(
#            raylib
#            URL https://github.com/raysan5/raylib/archive/master.tar.gz
#    )
#
#    FetchContent_GetProperties(raylib)
#    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
#        set(FETCHCONTENT_QUIET NO)
#        FetchContent_Populate(raylib)
#
#        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
#
#        # build raylib
#        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
#    endif ()
#endif ()
#find_library(RAYLIB_LIB raylib)

#find_package(raylib 3.0 REQUIRED) # Let CMake search for a raylib-config.cmake

message("OPENGL_LIBRARIES: ${OPENGL_LIBRARIES}")
message("RAYLIB_LIB: ${RAYLIB_LIB}")
message("GLEW::GLEW: ${GLEW}")
message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("LIBSIMD_CPP_SRC: ${LIBSIMD_CPP_SRC}")
target_link_libraries(boondi
        ${OPENGL_LIBRARIES}
        GLEW::GLEW
        raylib
        glfw
        OpenCL::OpenCL
        )