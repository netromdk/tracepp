include_directories(
  SYSTEM
  gtest/
  gtest/include
  )

add_executable(
  tests

  gtest/src/gtest_main.cc
  gtest/src/gtest-all.cc

  testutil.h

  general.cc
  primitives.cc
  container.cc
  std.cc
  special.cc
  )

add_test(
  NAME tests
  COMMAND tests
  )
