#include "gtest/gtest.h"
#include "testutil.h"

#include "tracepp.h"

TEST(tracepp, test)
{
  const int n = 42;
  TRACE(n);
}
