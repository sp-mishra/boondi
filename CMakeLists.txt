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
include_directories(src/third_party/raylib/src/)
include_directories(src/third_party/raylib/src/extras)
include_directories(src/third_party/json/single_include/nlohmann/)
include_directories(src/third_party/rayutils)
include_directories(src/third_party/argh)
include_directories(src/third_party/csv2/single_include/csv2)
include_directories(src/third_party/box2d-lite/include)
include_directories(src/third_party/spdlog/include)
include_directories(src/third_party/fmt/include)
include_directories(src/third_party/imgui)
include_directories(src/third_party/imgui/misc/fonts)
include_directories(src/third_party/imgui/misc/cpp/)
include_directories(src/third_party/imgui/backends)
include_directories(src/third_party/imgui-impl-raylib)
include_directories(src/third_party/bitsery/include/bitsery)
include_directories(src/third_party/soci/include)
include_directories(src/third_party/hash-library)
include_directories(src/third_party/nameof/include)
include_directories(src/third_party/refl-cpp/include)

find_library(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenCL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})

add_subdirectory(src/third_party/raylib)
set(SOCI_SHARED OFF)
set(SOCI_TESTS OFF)
set(SOCI_TESTS OFF)
add_subdirectory(src/third_party/soci)

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
        RAYLIB_EXTRA_SOURCE_FILES
        src/third_party/raylib/src/extras/*.h
        )

file(GLOB
        RAYLIB_UTILS_SOURCE_FILES
        src/third_party/rayutils/*.h
        )

file(GLOB
        JSON_SOURCE_FILES
        src/third_party/json/single_include/nlohmann/json.hpp
        )

file(GLOB
        CSV2_SOURCE_FILES
        src/third_party/csv2/single_include/csv2/*.hpp
        )

file(GLOB
        BOX2D_LITE_SOURCE_FILES
        src/third_party/box2d-lite/src/*.cpp
        src/third_party/box2d-lite/include/box2d-lite/*.h
        )

file(GLOB
        TINYGEOM2D_SOURCE_FILES
        src/third_party/tinygeom2d/tinygeom2d/*.hpp
        src/third_party/tinygeom2d/tinygeom2d/*.cpp
        )

file(GLOB
        IMGUI_SOURCE_FILES
        src/third_party/imgui/*.cpp
        src/third_party/imgui/*.h
        src/third_party/imgui/misc/cpp/*.h
        src/third_party/imgui/misc/cpp/*.cpp
#        src/third_party/imgui/misc/fonts/*.cpp
#        src/third_party/imgui/misc/fonts/*.h
        src/third_party/imgui/backends/imgui_impl_glfw.cpp
        src/third_party/imgui/backends/imgui_impl_glfw.h
        src/third_party/imgui/backends/imgui_impl_metal.h
#        src/third_party/imgui/misc/freetype/*.cpp
#        src/third_party/imgui/misc/freetype/*.h
        )

file(GLOB
        IMGUI_RAYLIB_SOURCE_FILES
        src/third_party/imgui-impl-raylib/*.cpp
        src/third_party/imgui-impl-raylib/*.h
        )

file(GLOB_RECURSE
        BITSERY_SOURCE_FILES
        src/third_party/bitsery/include/bitsery/*.h
        )

file(GLOB
        HASHLIBRARY_SOURCE_FILES
        src/third_party/hash-library/*.cpp
        src/third_party/hash-library/*.h
        )

file(GLOB
        NAMEOF_SOURCE_FILES
        src/third_party/nameof/include/nameof.hpp
        )

file(GLOB
        REFlCPP_SOURCE_FILES
        src/third_party/refl-cpp/include/refl.hpp
        )

file(GLOB
        SQLITE_SOURCE_FILES
        src/third_party/sqlite/sqlite3.c
        src/third_party/sqlite/sqlite3.h
        src/third_party/sqlite/sqlite3ext.h
        )

file(GLOB_RECURSE
        MAIN_SRC
        "src/main/*.cpp"
        "src/main/*.hpp"
#        "src/main/bun/*.hpp"
        )

add_executable(boondi
        ${LIBSIMD_CPP_SRC}
        ${ARGH_SRC}
        ${NANO_BENCHMARK_SRC}
        ${TINYGEOM2D_SOURCE_FILES}
        ${RAYLIB_EXTRA_SOURCE_FILES}
        ${RAYLIB_UTILS_SOURCE_FILES}
        ${IMGUI_SOURCE_FILES}
        ${IMGUI_RAYLIB_SOURCE_FILES}
        ${JSON_SOURCE_FILES}
        ${CSV2_SOURCE_FILES}
        ${BITSERY_SOURCE_FILES}
        ${SQLITE_SOURCE_FILES}
        ${NAMEOF_SOURCE_FILES}
        ${REFlCPP_SOURCE_FILES}
#        ${HASHLIBRARY_SOURCE_FILES}
        ${BOX2D_LITE_SOURCE_FILES}
        ${MNIST_READER_SRC}
        ${DOCTEST_SRC}
        ${BOOST_SOURCE_FILES}
        ${MAIN_SRC}
        src/main/example/reflection/refl.hpp)

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
message("raylib_SOURCE_DIR: ${raylib_SOURCE_DIR}")
message("raylib_BINARY_DIR: ${raylib_BINARY_DIR}")
message("raylib_INCLUDE_DIR: ${raylib_INCLUDE_DIR}")
message("GLEW::GLEW: ${GLEW_BINARY_DIR}")
message("MAIN_SRC: ${MAIN_SRC}")
#message("soci_SOURCE_DIR: ${soci_SOURCE_DIR}")
#message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
#message("LIBSIMD_CPP_SRC: ${LIBSIMD_CPP_SRC}")
target_link_libraries(boondi
        ${OPENGL_LIBRARIES}
        GLEW::GLEW
        raylib
        glfw
        soci_core_static
        soci_sqlite3_static
        soci_empty_static
        OpenCL::OpenCL
        )