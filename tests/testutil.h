#ifndef TESTS_TESTUTIL_H
#define TESTS_TESTUTIL_H

#include "gtest/gtest.h"

#include "tracepp.h"

#include <string>

class TraceppTest : public ::testing::Test {
public:
  TraceppTest()
  {
    printFunc = [this](const std::string & /*file*/, const int /*line*/,
                       const std::string & /*func*/, const std::string & /*expr*/,
                       const std::string &value) { last = value; };
  }

  void SetUp()
  {
    tracepp::setPrintFunc(printFunc);
  }

  void TearDown()
  {
    tracepp::setPrintFunc(tracepp::stdoutPrint);
  }

public:
  std::string last;

private:
  tracepp::PrintFunc printFunc;
};

#endif // TESTS_TESTUTIL_H
