include_directories(
  SYSTEM
  gtest/
  gtest/include
  )

add_library(
  gtest
  gtest/src/gtest_main.cc
  gtest/src/gtest-all.cc
  )

# Ignore all warnings from gtest code.
target_compile_options(
  gtest
  PRIVATE
  $<$<CXX_COMPILER_ID:Clang>:-w>
  $<$<CXX_COMPILER_ID:GNU>:-w>
  $<$<CXX_COMPILER_ID:MSVC>:/W0>
  )

add_executable(
  tests

  testutil.h
  testutil.cc

  general.cc
  primitives.cc
  container.cc
  std.cc
  special.cc
  )

target_link_libraries(
  tests
  gtest
  )

add_test(
  NAME tests
  COMMAND tests
  )
