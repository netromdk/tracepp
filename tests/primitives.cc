#include "gtest/gtest.h"
#include "testutil.h"

#include "tracepp.h"

#include <utility>

using Primitives = TraceppTest;

TEST_F(Primitives, stdString)
{
  TRACE(std::string("hello"));
  EXPECT_EQ(last, "\"hello\"");
}

TEST_F(Primitives, bool)
{
  TRACE(true);
  EXPECT_EQ(last, "true");

  TRACE(false);
  EXPECT_EQ(last, "false");
}

TEST_F(Primitives, int)
{
  int i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, unsignedInt)
{
  unsigned int i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, short)
{
  short i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, unsignedShort)
{
  unsigned short i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, char)
{
  char c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");

  c = -3;
  TRACE(c);
  EXPECT_EQ(last, "-3");
}

TEST_F(Primitives, unsignedChar)
{
  unsigned char c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");

  c = '\n';
  TRACE(c);
  EXPECT_EQ(last, "10");
}

TEST_F(Primitives, wchar_t)
{
  wchar_t c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");
}

TEST_F(Primitives, long)
{
  long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, unsignedLong)
{
  unsigned long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, longLong)
{
  long long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, unsignedLongLong)
{
  unsigned long long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, float)
{
  float i = 42.0f;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, double)
{
  double i = 42.0;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(Primitives, longDouble)
{
  long double i = 42.0;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}
