#ifndef EXT_FORMAT_HPP__
#define EXT_FORMAT_HPP__

#include <string>
#include <regex>
#include <sstream>
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
inline std::string format(const char *s, Args&&... args) {
  std::string str{s};
  format_helper(1, str, std::forward<Args>(args)...);
  return str;
}

} // namespace ext

#endif
