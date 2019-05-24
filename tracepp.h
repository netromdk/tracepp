/***************************************************************************************************
tracepp

C++ tracing library for debugging with ease.

MIT License

Copyright (c) 2019 Morten Kristensen, me AT mortens DOT dev

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
***************************************************************************************************/

#ifndef TRACEPP_DEBUGGING_H
#define TRACEPP_DEBUGGING_H

#include <cstddef>
#include <iostream>
#include <sstream>
#include <utility>

#ifndef NDEBUG

namespace tracepp {

void print(const std::string &file, const int line, const std::string &func,
           const std::string &expr, const std::string &value)
{
  std::cout << file << ":" << line << ":" << func << "(): " << expr << " = " << value << std::endl;
}

template <typename T>
std::string toString(const T &val)
{
  std::ostringstream oss;
  oss << "[";
  for (auto it = val.cbegin(); it != val.cend(); ++it) {
    oss << toString(*it);
    if (it + 1 != val.cend()) {
      oss << ", ";
    }
  }
  oss << "]";
  return oss.str();
}

template <>
inline std::string toString(const std::string &val)
{
  return val;
}

template <>
inline std::string toString(const bool &val)
{
  return (val ? "true" : "false");
}

template <>
inline std::string toString(const int &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const unsigned int &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const short &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const unsigned short &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const char &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const unsigned char &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const wchar_t &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const long &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const unsigned long &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const long long &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const unsigned long long &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const float &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const double &val)
{
  return std::to_string(val);
}

template <>
inline std::string toString(const long double &val)
{
  return std::to_string(val);
}

} // namespace tracepp

#define TRACE(x) tracepp::print(__FILE__, __LINE__, __func__, #x, tracepp::toString(x)), x

#else

#define TRACE(x) x

#endif

#endif // TRACEPP_DEBUGGING_H
