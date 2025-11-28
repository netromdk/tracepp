#include "tracepp.h"

int main()
{
  int val = 0;
  for (int i = 10; TRACE(i < 13); ++i) {
    val += TRACE(i);
  }
  return TRACE(val - 33);
}
