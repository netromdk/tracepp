#include "testutil.h"
#include "gtest/gtest.h"

#include "tracepp.h"

#include <array>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using std_ = TraceppTest;

TEST_F(std_, pair)
{
  std::pair<int, double> p{42, 9.87};
  TRACE(p);
  EXPECT_EQ(last, "(42, 9.870000)");
}

TEST_F(std_, bitset)
{
  std::bitset<12> b(1024);
  TRACE(b);
  EXPECT_EQ(last, "010000000000");
}

TEST_F(std_, tuple)
{
  std::tuple<float, bool, std::string> t{4.2f, false, "tuple"};
  TRACE(t);
  EXPECT_EQ(last, "(4.200000, false, \"tuple\")");
}

TEST_F(std_, map)
{
  std::map<std::string, char> m;
  m["hello"] = 'a';
  m["world"] = 'b';
  TRACE(m);
  EXPECT_EQ(last, "{\"hello\" -> 'a' (97), \"world\" -> 'b' (98)}");
}

TEST_F(std_, multimap)
{
  std::multimap<std::string, char> m;
  m.insert({"hello", 'a'});
  m.insert({"hello", 'A'});
  m.insert({"world", 'b'});
  m.insert({"world", 'B'});
  TRACE(m);
  EXPECT_EQ(
    last,
    "{\"hello\" -> 'a' (97), \"hello\" -> 'A' (65), \"world\" -> 'b' (98), \"world\" -> 'B' (66)}");
}

TEST_F(std_, unordered_map)
{
  std::unordered_map<std::string, char> m;
  m["hello"] = 'a';
  m["world"] = 'b';
  TRACE(m);
  EXPECT_EQ(last, "{\"world\" -> 'b' (98), \"hello\" -> 'a' (97)}");
}

TEST_F(std_, queue)
{
  std::queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  TRACE(q);
  EXPECT_EQ(last, "[1, 2, 3]");
}

TEST_F(std_, array)
{
  std::array<int, 3> a{1, 2, 3};
  TRACE(a);
  EXPECT_EQ(last, "[1, 2, 3]");
}

TEST_F(std_, set)
{
  std::set<int> s{1, 2, 3};
  TRACE(s);
  EXPECT_EQ(last, "[1, 2, 3]");
}

TEST_F(std_, multiset)
{
  std::multiset<int> s{1, 2, 3, 1, 2, 3};
  TRACE(s);
  EXPECT_EQ(last, "[1, 1, 2, 2, 3, 3]");
}

TEST_F(std_, unordered_set)
{
  std::unordered_set<int> s{1, 2, 3};
  TRACE(s);
  EXPECT_EQ(last, "[3, 2, 1]");
}

TEST_F(std_, deque)
{
  std::deque<int> d{1, 2, 3};
  TRACE(d);
  EXPECT_EQ(last, "[1, 2, 3]");
}

TEST_F(std_, list)
{
  std::list<int> l{1, 2, 3};
  TRACE(l);
  EXPECT_EQ(last, "[1, 2, 3]");
}
