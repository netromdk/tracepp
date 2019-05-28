#include "testutil.h"

TraceppTest::TraceppTest()
{
  printFunc = [this](const std::string & /*file*/, const int /*line*/, const std::string & /*func*/,
                     const std::string & /*expr*/, const std::string &value) { last = value; };
}

void TraceppTest::SetUp()
{
  tracepp::setPrintFunc(printFunc);
}

void TraceppTest::TearDown()
{
  tracepp::setPrintFunc(tracepp::stdoutPrint);
}
