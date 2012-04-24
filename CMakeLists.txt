cmake_minimum_required(VERSION 2.6)
project(libmozart-experiments)


# Configure paths
set(MOZART_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../mozart2"
    CACHE PATH "Path to Mozart2 source directory")
set(MOZART_BUILD_DIR "${MOZART_DIR}/build"
    CACHE PATH "Path to Mozart2 build directory")

set(DEFAULT_LLVM_BUILD_DIR "${MOZART_BUILD_DIR}/externals/Build/llvm")
set(LLVM_BUILD_DIR ${DEFAULT_LLVM_BUILD_DIR}
    CACHE PATH "Path to LLVM build (with Clang)")


# Configure compiler
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -O3 -DNDEBUG")


# Import Mozart VM library

add_library(mozartvm STATIC IMPORTED)
set_property(TARGET mozartvm PROPERTY
             IMPORTED_LOCATION "${MOZART_DIR}/build/vm/main/libmozartvm.a")

include_directories("${MOZART_DIR}/vm/main" "${MOZART_DIR}/build/vm/main")


# Run the generator on "customlib.hh"

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/customlib.hh.gen
  COMMAND ${LLVM_BUILD_DIR}/bin/clang++ -std=c++0x -femit-ast
    -o ${CMAKE_CURRENT_BINARY_DIR}/customlib.hh.ast
    -I "${MOZART_DIR}/vm/main"
    -DMOZART_GENERATOR
    ${CMAKE_CURRENT_SOURCE_DIR}/customlib.hh
  COMMAND ${MOZART_BUILD_DIR}/generator/main/generator
    ${CMAKE_CURRENT_BINARY_DIR}/customlib.hh.ast
    ${CMAKE_CURRENT_BINARY_DIR}/
  COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_BINARY_DIR}/customlib.hh.gen
  IMPLICIT_DEPENDS CXX "${CMAKE_CURRENT_SOURCE_DIR}/customlib.hh"
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMENT Processing customlib.hh
  VERBATIM)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_custom_target(gensources
  DEPENDS customlib.hh.gen
  VERBATIM)


# Compile the executable

add_executable(libmozart-experiments main.cc)
target_link_libraries(libmozart-experiments mozartvm)
add_dependencies(libmozart-experiments gensources)
