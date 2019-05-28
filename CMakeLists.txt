cmake_minimum_required(VERSION 3.0)
project(tracepp)

option(ADDRESS_SANITIZER "Use memory error detector (clang only and implies debug mode!)" OFF)

# Exports the "compile_commands.json" file when the generator is Ninja or Makefile.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

include(compilation)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

if (ADDRESS_SANITIZER)
  if (NOT "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    message(FATAL_ERROR "Clang is required to use address sanitizer to detect memory errors!")
  endif()

  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -g -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls")
  set(CMAKE_BUILD_TYPE Debug)
endif()

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(examples)

enable_testing()
add_subdirectory(tests)

message(STATUS "--------------------------------------------------")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER} (${CMAKE_CXX_COMPILER_ID})")

message(STATUS "Address sanitizer: ${ADDRESS_SANITIZER}")

message(STATUS "--------------------------------------------------")
