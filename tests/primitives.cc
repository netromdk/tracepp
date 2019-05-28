#include "gtest/gtest.h"
#include "testutil.h"

#include "tracepp.h"

#include <utility>

using TraceppPrimitives = TraceppTest;

TEST_F(TraceppPrimitives, stdString)
{
  TRACE(std::string("hello"));
  EXPECT_EQ(last, "\"hello\"");
}

TEST_F(TraceppPrimitives, bool)
{
  TRACE(true);
  EXPECT_EQ(last, "true");

  TRACE(false);
  EXPECT_EQ(last, "false");
}

TEST_F(TraceppPrimitives, int)
{
  int i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, unsignedInt)
{
  unsigned int i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, short)
{
  short i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, unsignedShort)
{
  unsigned short i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, char)
{
  char c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");

  c = -3;
  TRACE(c);
  EXPECT_EQ(last, "-3");
}

TEST_F(TraceppPrimitives, unsignedChar)
{
  unsigned char c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");

  c = '\n';
  TRACE(c);
  EXPECT_EQ(last, "10");
}

TEST_F(TraceppPrimitives, wchar_t)
{
  wchar_t c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");
}

TEST_F(TraceppPrimitives, long)
{
  long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, unsignedLong)
{
  unsigned long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, longLong)
{
  long long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, unsignedLongLong)
{
  unsigned long long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, float)
{
  float i = 42.0f;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, double)
{
  double i = 42.0;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppPrimitives, longDouble)
{
  long double i = 42.0;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}
