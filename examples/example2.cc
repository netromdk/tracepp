#include "tracepp.h"
#include <vector>

int main()
{
  std::vector<std::vector<int>> vec{{1, 2, 3}, {4, 5}, {6, 7, 8}};
  TRACE(vec);
  if (TRACE(vec.size() >= 2)) {
    TRACE(vec[1]);
  }
  return 0;
}
