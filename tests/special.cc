#include "testutil.h"
#include "gtest/gtest.h"

#include "tracepp.h"

using Special = TraceppTest;

/// Uses overload:
/** template <typename T, std::size_t N> std::string toString(const T (&val)[N]) */
//@{

TEST_F(Special, charArray)
{
  char c[3] = {'a', '\n', 'c'};
  TRACE(c);
  EXPECT_EQ(last, "['a' (97), 10, 'c' (99)]");
}

TEST_F(Special, floatArray)
{
  float f[3] = {1, 2, 3};
  TRACE(f);
  EXPECT_EQ(last, "[1.000000, 2.000000, 3.000000]");
}

TEST_F(Special, stdStringArray)
{
  std::string s[3] = {"1", "2", "3"};
  TRACE(s);
  EXPECT_EQ(last, "[\"1\", \"2\", \"3\"]");
}

//@}
