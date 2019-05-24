#include "tracepp.h"

int main()
{
  tracepp::setPrintFunc([](const std::string &file, const int line, const std::string &func,
                           const std::string &expr, const std::string &value) {
    std::cout << "[CUSTOM] " << file << ":" << line << ":" << func << "(): " << expr << " = "
              << value << std::endl;
  });

  const char s[] = "Hello, World!";
  TRACE(s);
  const double d[] = {0, 1, 2};
  TRACE(d);
  return 0;
}
