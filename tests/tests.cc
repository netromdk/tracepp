#include "gtest/gtest.h"

#include "tracepp.h"

#include <string>
#include <utility>

class TraceppTest : public ::testing::Test {
protected:
  void SetUp()
  {
    printFunc = [this](const std::string & /*file*/, const int /*line*/,
                       const std::string & /*func*/, const std::string & /*expr*/,
                       const std::string &value) { last = value; };
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

TEST(tracepp, test)
{
  const int n = 42;
  TRACE(n);
}

TEST_F(TraceppTest, stdString)
{
  TRACE(std::string("hello"));
  EXPECT_EQ(last, "\"hello\"");
}

TEST_F(TraceppTest, bool)
{
  TRACE(true);
  EXPECT_EQ(last, "true");

  TRACE(false);
  EXPECT_EQ(last, "false");
}

TEST_F(TraceppTest, int)
{
  int i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, unsignedInt)
{
  unsigned int i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, short)
{
  short i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, unsignedShort)
{
  unsigned short i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, char)
{
  char c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");

  c = -3;
  TRACE(c);
  EXPECT_EQ(last, "-3");
}

TEST_F(TraceppTest, unsignedChar)
{
  unsigned char c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");

  c = '\n';
  TRACE(c);
  EXPECT_EQ(last, "10");
}

TEST_F(TraceppTest, wchar_t)
{
  wchar_t c = 'Q';
  TRACE(c);
  EXPECT_EQ(last, "'Q' (81)");
}

TEST_F(TraceppTest, long)
{
  long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, unsignedLong)
{
  unsigned long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, longLong)
{
  long long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, unsignedLongLong)
{
  unsigned long long i = 42;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, float)
{
  float i = 42.0f;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, double)
{
  double i = 42.0;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}

TEST_F(TraceppTest, longDouble)
{
  long double i = 42.0;
  TRACE(i);
  EXPECT_EQ(last, std::to_string(i));
}
