#ifndef TESTS_TESTUTIL_H
#define TESTS_TESTUTIL_H

#include "gtest/gtest.h"

#include "tracepp.h"

#include <string>

class TraceppTest : public ::testing::Test {
public:
  TraceppTest();

protected:
  void SetUp() override;
  void TearDown() override;

public:
  std::string last;

private:
  tracepp::PrintFunc printFunc;
};

#endif // TESTS_TESTUTIL_H
