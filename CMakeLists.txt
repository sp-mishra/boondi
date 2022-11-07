cmake_minimum_required(VERSION 3.15)
project(boondi)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED OFF)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_VERBOSE_MAKEFILE OFF)

#if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#  set(CMAKE_CXX_FLAGS_DISTRIBUTION "-E -i")
#  set(CMAKE_C_FLAGS_DISTRIBUTION "-E -i")
#  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -save-temps")

#  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
##  set(CMAKE_CXX_FLAGS_DISTRIBUTION
##    "-march=native -O3 -Wall -Wpedantic -Wfatal-errors -Wno-missing-braces -std=c++14 -stdlib=libc++"
##  )
##  set(CMAKE_CXX_FLAGS_RELEASE
###		"-march=native -O3 -Wall -Wpedantic -Wfatal-errors -Wno-missing-braces -std=c++14 -stdlib=libc++"
##    ${CMAKE_CXX_FLAGS_DISTRIBUTION}
##  )
##  set(CMAKE_CXX_FLAGS_DEBUG
##    "-g -Wfatal-errors -O0 -std=c++14 -stdlib=libc++"
##  )
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#  set(CMAKE_CXX_FLAGS_DISTRIBUTION "-E -i")
#  set(CMAKE_C_FLAGS_DISTRIBUTION "-E -i")
#  set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -save-temps")

#  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
##  set(CMAKE_CXX_FLAGS_DISTRIBUTION
##    "-O3 -s -static-libstdc++ -fPIC -fopenmp -pthread -Wall -Wpedantic -Wfatal-errors -std=c++14"
##  )
##  set(CMAKE_CXX_FLAGS_RELEASE
##    "-O3 -fopenmp -pthread -fPIC -Wall -Wpedantic -Wfatal-errors -std=c++14"
##  )
##  set(CMAKE_CXX_FLAGS_DEBUG
##    "-g -Wfatal-errors -O0 -fPIC -fopenmp -pthread -std=c++14"
##  )
#endif()
set(CMAKE_CXX_FLAGS_DISTRIBUTION "-E")
set(CMAKE_C_FLAGS_DISTRIBUTION "-E")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -save-temps")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")


#set(CMAKE_CXX_FLAGS_DISTRIBUTION "-E")
#set(CMAKE_C_FLAGS_DISTRIBUTION "-E")

#add_compile_definitions(FMT_CONSTEVAL= )
add_definitions(-DFMT_CONSTEVAL= )
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
add_compile_definitions(BOOST_ALL_NO_LIB)
add_compile_definitions(Boost_USE_STATIC_LIBS)
set(Boost_USE_STATIC_LIBS ON)

set(PROJECT_NAME boondi)
include(CMakePrintHelpers)
include_directories(/usr/local/include)
include_directories(src/main/)
include_directories(src/third_party/)
include_directories(src/third_party/nanobench/src/include)
include_directories(src/third_party/doctest)
include_directories(src/third_party/libsimdpp)
#include_directories(src/third_party/mnist/include)
#include_directories(src/third_party/raylib/src/)
#include_directories(src/third_party/raylib/src/extras)
include_directories(src/third_party/json/single_include/nlohmann/)
include_directories(src/third_party/rayutils)
include_directories(src/third_party/argh)
include_directories(src/third_party/csv2/single_include/csv2)
#include_directories(src/third_party/box2d-lite/include)
include_directories(src/third_party/spdlog/include)
include_directories(src/third_party/fmt/include)
#include_directories(src/third_party/imgui)
#include_directories(src/third_party/imgui/misc/fonts)
#include_directories(src/third_party/imgui/misc/cpp/)
#include_directories(src/third_party/imgui/backends)
#include_directories(src/third_party/imgui-impl-raylib)
include_directories(src/third_party/bitsery/include/bitsery)
#include_directories(src/third_party/soci/include/soci)
#include_directories(src/third_party/soci/include)
include_directories(src/third_party/hash-library)
include_directories(src/third_party/nameof/include)
include_directories(src/third_party/refl-cpp/include)
include_directories(src/third_party/Linq)
include_directories(src/third_party/boolinq/include/boolinq)
include_directories(src/third_party/sql-parser/src)
include_directories(src/third_party/Catch2/single_include/catch2)
include_directories(src/third_party/PEGTL/include)
#include_directories(/usr/local/Cellar/soci/4.0.2/include)

#find_library(OpenGL REQUIRED)
#find_package(GLEW REQUIRED)
find_package(OpenCL REQUIRED)
#include_directories(${OPENGL_INCLUDE_DIRS})
#include_directories(${GLEW_INCLUDE_DIRS})

#add_subdirectory(src/third_party/raylib)
add_subdirectory(src/third_party/spdlog)
add_subdirectory(src/third_party/sqlite)
#set(SOCI_SHARED OFF)
#set(SOCI_TESTS OFF)
#set(SOCI_ODBC OFF)
#set(SQLITE3_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/third_party/sqlite/)
##set(SQLITE3_LIBRARIES ${CMAKE_BINARY_DIR})
#add_subdirectory(src/third_party/soci)
add_subdirectory(src/third_party/Linq)
add_subdirectory(src/third_party/lexy)
add_subdirectory(src/third_party/PEGTL)

#find_library(SOCI_LIB soci)
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

file(GLOB
  BOOLINQ_SRC
  "src/third_party/boolinq/include/boolinq/boolinq.h"
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

#file(GLOB
#        RAYLIB_EXTRA_SOURCE_FILES
#        src/third_party/raylib/src/extras/*.h
#        )

#file(GLOB
#        RAYLIB_UTILS_SOURCE_FILES
#        src/third_party/rayutils/*.h
#        )

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

#file(GLOB
#        IMGUI_SOURCE_FILES
#        src/third_party/imgui/*.cpp
#        src/third_party/imgui/*.h
#        src/third_party/imgui/misc/cpp/*.h
#        src/third_party/imgui/misc/cpp/*.cpp
##        src/third_party/imgui/misc/fonts/*.cpp
##        src/third_party/imgui/misc/fonts/*.h
#        src/third_party/imgui/backends/imgui_impl_glfw.cpp
#        src/third_party/imgui/backends/imgui_impl_glfw.h
#        src/third_party/imgui/backends/imgui_impl_metal.h
##        src/third_party/imgui/misc/freetype/*.cpp
##        src/third_party/imgui/misc/freetype/*.h
#        )

#file(GLOB
#        IMGUI_RAYLIB_SOURCE_FILES
#        src/third_party/imgui-impl-raylib/*.cpp
#        src/third_party/imgui-impl-raylib/*.h
#        )

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

file(GLOB_RECURSE
  LINQ_SRC
  src/third_party/Linq/*.h
  src/third_party/Linq/*.hpp
  )

#file(GLOB
#        SQLITE_SOURCE_FILES
#        src/third_party/sqlite/sqlite3.c
#        src/third_party/sqlite/sqlite3.h
#        src/third_party/sqlite/sqlite3ext.h
#        )

file(GLOB
  SQL_PARSER_SRC
  src/third_party/sql-parser/src/parser/bison_parser.cpp
  src/third_party/sql-parser/src/parser/bison_parser.h
  src/third_party/sql-parser/src/parser/flex_lexer.cpp
  src/third_party/sql-parser/src/parser/flex_lexer.h
  src/third_party/sql-parser/src/parser/parser_typedef.h
  src/third_party/sql-parser/src/sql/*.h
  src/third_party/sql-parser/src/sql/*.cpp
  src/third_party/sql-parser/src/util/sqlhelper.cpp
  src/third_party/sql-parser/src/util/sqlhelper.h
  src/third_party/sql-parser/src/SQLParser.cpp
  src/third_party/sql-parser/src/SQLParser.h
  src/third_party/sql-parser/src/SQLParserResult.cpp
  src/third_party/sql-parser/src/SQLParserResult.h
)

file(
  GLOB
  CATCH2_SRC
  src/third_party/Catch2/single_include/catch2/*.hpp
)

file(GLOB_RECURSE
        MAIN_SRC
        src/main/*.cpp
        src/main/*.hpp
        )

add_executable(${PROJECT_NAME}
        ${LIBSIMD_CPP_SRC}
        ${ARGH_SRC}
        ${NANO_BENCHMARK_SRC}
        ${LINQ_SRC}
        ${BOOLINQ_SRC}
        ${SQL_PARSER_SRC}
#        ${TINYGEOM2D_SOURCE_FILES}
#        ${RAYLIB_EXTRA_SOURCE_FILES}
#        ${RAYLIB_UTILS_SOURCE_FILES}
#        ${IMGUI_SOURCE_FILES}
#        ${IMGUI_RAYLIB_SOURCE_FILES}
        ${JSON_SOURCE_FILES}
        ${CSV2_SOURCE_FILES}
        ${BITSERY_SOURCE_FILES}
#        ${SQLITE_SOURCE_FILES}
        ${NAMEOF_SOURCE_FILES}
        ${REFlCPP_SOURCE_FILES}
#        ${HASHLIBRARY_SOURCE_FILES}
#        ${BOX2D_LITE_SOURCE_FILES}
#        ${MNIST_READER_SRC}
#        ${DOCTEST_SRC}
        ${BOOST_SOURCE_FILES}
        ${CATCH2_SRC}
        ${MAIN_SRC}
        )

find_package(spdlog QUIET)
#find_library(SQLITE3_LIB sqlite3)
#find_package(raylib 3.0 QUIET) # Let CMake search for a raylib-config.cmake
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
message("sqlite_SOURCE_DIR: ${sqlite_SOURCE_DIR}")
message("sqlite_BINARY_DIR: ${sqlite_BINARY_DIR}")
message("LIBRARY_OUTPUT_PATH: ${LIBRARY_OUTPUT_PATH}")
message("soci_INCLUDE_DIR: ${soci_INCLUDE_DIR}")
message("GLEW::GLEW: ${GLEW_BINARY_DIR}")
message("LINQ_SRC::LINQ_SRC: ${LINQ_SRC_DIR}")
message("MAIN_SRC: ${MAIN_SRC}")
message("CMAKE_C_FLAGS: ${CMAKE_C_FLAGS}")
message("CMAKE_CXX_FLAGS_DISTRIBUTION: ${CMAKE_CXX_FLAGS_DISTRIBUTION}")
message("CMAKE_C_FLAGS_DISTRIBUTION: ${CMAKE_C_FLAGS_DISTRIBUTION}")
#message("soci_SOURCE_DIR: ${soci_SOURCE_DIR}")
#message("CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
#message("LIBSIMD_CPP_SRC: ${LIBSIMD_CPP_SRC}")
link_directories(/usr/local/lib/)
#find_library(libuv PRIVATE)
#target_link_libraries(rabri PRIVATE fmt::fmt-header-only)
#target_link_libraries(rabri PRIVATE spdlog::spdlog_header_only)
#target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
#target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
#find_library(USOCKET_LIB uSockets.a /usr/local/lib/)
if(CMAKE_SYSTEM_NAME MATCHES "Linux")
#    LINK_DIRECTORIES(/usr/lib/x86_64-linux-gnu/)
#    TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} dl)
    target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
endif()
target_link_libraries(${PROJECT_NAME}
#        ${OPENGL_LIBRARIES}
#        GLEW::GLEW
#        raylib
#        glfw
#        sqlite3
#        soci_core_static
#        soci_sqlite3_static
#        soci_empty_static
        OpenCL::OpenCL
        spdlog::spdlog
        linq::linq
        foonathan::lexy
        taocpp::pegtl
        )
