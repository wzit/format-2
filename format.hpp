#ifndef EXT_FORMAT_HPP__
#define EXT_FORMAT_HPP__
/*
The MIT License (MIT)

Copyright (c) 2013 justinls

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include <regex>
#include <sstream>
#include <string>
#include <utility>

namespace {

inline void format_helper(size_t, std::string &) {
  return;
}

template <typename T, typename... Args>
inline void format_helper(size_t arg_index, std::string &str, T &&val, Args &&...args) {
  str = std::regex_replace(str, std::regex{"%" + std::to_string(arg_index)}, (std::ostringstream{} << val).str());
  format_helper(++arg_index, str, std::forward<Args>(args)...);
}

} // namespace


namespace ext {

template <typename... Args>
inline const char *format(const char *s, Args &&...args) {
  std::string str{s};
  format_helper(1, str, std::forward<Args>(args)...);
  return str.c_str();
}

} // namespace ext

#endif
