#include "testutil.h"
#include "gtest/gtest.h"

#include "tracepp.h"

#include <iostream>
#include <sstream>
#include <vector>

TEST(tracepp, value)
{
  const int n = 42;
  TRACE(n);
}

TEST(tracepp, streamOperator)
{
  const int v = 42;
  std::ostringstream oss;
  oss << TRACE(v);
  EXPECT_EQ(oss.str(), "42");
}

TEST(tracepp, loop)
{
  const std::vector<int> v{1, 2, 3};
  std::ostringstream oss;
  for (std::size_t i = 0; TRACE(i < v.size()); ++i) {
    oss << TRACE(i);
  }
  EXPECT_EQ(oss.str(), "012");
}
