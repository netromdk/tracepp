#include "tracepp.h"

int main()
{
  for (int i = 10; TRACE(i < 13); ++i) {
    TRACE(i);
  }
  return 0;
}
