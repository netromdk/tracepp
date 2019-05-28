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

#ifndef NDEBUG

#include <bitset>
#include <cctype>
#include <cstddef>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <tuple>
#include <unordered_map>
#include <utility>

namespace tracepp {

/// Type of a print function to use for tracing.
using PrintFunc = std::function<void(const std::string &, const int, const std::string &,
                                     const std::string &, const std::string &)>;

[[maybe_unused]] static void stdoutPrint(const std::string &file, const int line,
                                         const std::string &func, const std::string &expr,
                                         const std::string &value)
{
  std::cout << file << ":" << line << ":" << func << "(): " << expr << " = " << value << std::endl;
}

[[maybe_unused]] static void stderrPrint(const std::string &file, const int line,
                                         const std::string &func, const std::string &expr,
                                         const std::string &value)
{
  std::cerr << file << ":" << line << ":" << func << "(): " << expr << " = " << value << std::endl;
}

namespace detail {

/// Active print function.
static PrintFunc PRINT_FUNC = stdoutPrint;

} // namespace detail

[[maybe_unused]] static void setPrintFunc(const PrintFunc &func)
{
  detail::PRINT_FUNC = func;
}

/// Prototype of general toString function.
template <typename T>
std::string toString(const T &val);

/* Special cases */

template <typename T1, typename T2>
inline std::string toString(const std::pair<T1, T2> &val)
{
  return "(" + toString(val.first) + ", " + toString(val.second) + ")";
}

template <typename... T>
std::string toString(const std::tuple<T...> &val)
{
  std::ostringstream oss;
  oss << "(";
  std::apply(
    [&](T... args) {
      char comma[3] = {'\0', ' ', '\0'};
      ((oss << comma << toString(args), comma[0] = ','), ...);
    },
    val);
  oss << ")";
  return oss.str();
}

template <std::size_t N>
inline std::string toString(const std::bitset<N> &val)
{
  return val.to_string();
}

template <std::size_t N>
inline std::string toString(const char (&val)[N])
{
  return {val};
}

template <typename T, std::size_t N>
std::string toString(const T (&val)[N])
{
  std::ostringstream oss;
  oss << "[";
  char comma[3] = {'\0', ' ', '\0'};
  for (decltype(N) i = 0; i < N; ++i) {
    oss << comma << toString(val[i]);
    comma[0] = ',';
  }
  oss << "]";
  return oss.str();
}

namespace detail {

template <typename T>
std::string mapToString(const T &map)
{
  std::ostringstream oss;
  oss << "{";
  char comma[3] = {'\0', ' ', '\0'};
  for (auto it = map.cbegin(); it != map.cend(); ++it) {
    oss << comma << toString(it->first) << " -> " << toString(it->second);
    comma[0] = ',';
  }
  oss << "}";
  return oss.str();
}

} // namespace detail

template <typename K, typename V>
std::string toString(const std::map<K, V> &val)
{
  return detail::mapToString(val);
}

template <typename K, typename V>
std::string toString(const std::multimap<K, V> &val)
{
  return detail::mapToString(val);
}

template <typename K, typename V>
std::string toString(const std::unordered_map<K, V> &val)
{
  return detail::mapToString(val);
}

template <typename T>
std::string toString(const std::queue<T> &val)
{
  std::ostringstream oss;
  oss << "[";

  auto copy = val;
  while (!copy.empty()) {
    oss << toString(copy.front());
    copy.pop();
    if (!copy.empty()) {
      oss << ", ";
    }
  }

  oss << "]";
  return oss.str();
}

/* General container solution */

template <typename T>
std::string toString(const T &val)
{
  std::ostringstream oss;
  oss << "[";
  char comma[3] = {'\0', ' ', '\0'};
  for (auto it = val.cbegin(); it != val.cend(); ++it) {
    oss << comma << toString(*it);
    comma[0] = ',';
  }
  oss << "]";
  return oss.str();
}

/* Specializations */

template <>
inline std::string toString(const std::string &val)
{
  return "\"" + val + "\"";
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

namespace detail {

std::string charToString(const char &val)
{
  if (std::isprint(val)) {
    return "'" + std::string(1, val) + "' (" + std::to_string(val) + ")";
  }
  return std::to_string(val);
}

} // namespace detail

template <>
inline std::string toString(const char &val)
{
  return detail::charToString(val);
}

template <>
inline std::string toString(const unsigned char &val)
{
  return detail::charToString(val);
}

template <>
inline std::string toString(const wchar_t &val)
{
  return detail::charToString(val);
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

#define TRACE(x)                                                                                   \
  tracepp::detail::PRINT_FUNC(__FILE__, __LINE__, __func__, #x, tracepp::toString(x)), x

#else

#define TRACE(x) x

#endif

#endif // TRACEPP_DEBUGGING_H
