#include "gtest/gtest.h"
#include "testutil.h"

#include "tracepp.h"

using TraceppContainer = TraceppTest;

TEST_F(TraceppContainer, container)
{
  std::vector<int> vec{1, 2, 3};
  TRACE(vec);
  EXPECT_EQ(last, "[1, 2, 3]");
}

TEST_F(TraceppContainer, nestedContainers)
{
  std::vector<std::tuple<std::pair<int, float>, std::string>> vec{{{42, 0.1f}, "hello"},
                                                                  {{84, 0.2f}, "world"}};
  TRACE(vec);
  EXPECT_EQ(last, "[((42, 0.100000), \"hello\"), ((84, 0.200000), \"world\")]");
}
