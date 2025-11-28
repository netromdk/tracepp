#include "tracepp.h"
#include <vector>

int main()
{
  std::vector<std::vector<int>> vec{{1, 2, 3}, {0, 5}, {6, 7, 8}};
  const auto copy = TRACE(vec);
  if (TRACE(vec.size() >= 2)) {
    return TRACE(vec[1])[0];
  }
  return static_cast<int>(TRACE(copy.size() - 3));
}
