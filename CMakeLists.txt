cmake_minimum_required(VERSION 2.6)
project(libmozart-experiments)

# Configure paths
set(MOZART_DIR "/home/sjrd/projets/mozart")

# Configure compiler
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -O3 -DNDEBUG")


# Mozart VM library

add_library(mozartvm STATIC IMPORTED)
set_property(TARGET mozartvm PROPERTY
             IMPORTED_LOCATION "${MOZART_DIR}/build/vm/main/libmozartvm.a")

include_directories("${MOZART_DIR}/vm/main" "${MOZART_DIR}/build/vm/main")


# Compile the executable

add_executable(libmozart-experiments main.cc)
target_link_libraries(libmozart-experiments mozartvm)
