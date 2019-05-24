# tracepp
C++ tracing library, via the `TRACE()` macro, for debugging with ease that is inspired by Rust's `dbg!` macro.

If `NDEBUG` is defined then `TRACE(x) x` in order for the program to function properly in non-debug mode.

## Examples
The following example shows which values are checked in the `for`-loop and the values for each iteration:
```c++
#include "tracepp.h"

int main()
{
  for (int i = 10; TRACE(i < 13); ++i) {
    TRACE(i);
  }
  return 0;
}
```

Output:
```
example.cc:5:main(): i < 13 = true
example.cc:6:main(): i = 10
example.cc:5:main(): i < 13 = true
example.cc:6:main(): i = 11
example.cc:5:main(): i < 13 = true
example.cc:6:main(): i = 12
example.cc:5:main(): i < 13 = false
```

Tracepp supports containers (as long as they have `cbegin()` and `cend()`):
```c++
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
```

Output:
```
example2.cc:7:main(): vec = [[1, 2, 3], [4, 5], [6, 7, 8]]
example2.cc:8:main(): vec.size() >= 2 = true
example2.cc:9:main(): vec[1] = [4, 5]
```

## Adding custom type handling
Tracepp can easily be extended to support custom types:
```c++
#include "tracepp.h"
#include <string>

struct Custom {
  Custom(const std::string &text_) : text(text_) {}
  std::string text;
};

namespace tracepp {

template <>
inline std::string toString(const Custom &val)
{
  return "\"" + val.text + "\"";
}

} // namespace tracepp

int main()
{
  Custom c("Hello, Custom World!");
  TRACE(c);
  return 0;
}
```

Output:
```
custom.cc:22:main(): c = "Hello, Custom World!"
```
