cmake_minimum_required(VERSION 3.0)
project(tracepp)

# Exports the "compile_commands.json" file when the generator is Ninja or Makefile.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(compilation)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

include_directories(${CMAKE_SOURCE_DIR})

#add_subdirectory(examples)

enable_testing()
add_subdirectory(tests)
