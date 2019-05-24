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
