#include "gtest/gtest.h"
#include "format.hpp"
#include <iostream>

namespace format_tests {

struct foo {
  int i;
  foo(int i) : i{i} {
  }
};

std::ostream &operator<<(std::ostream &os, const foo &f) {
  os << "foo(" << f.i << ")";
  return os;
}

// Empty string and no arguments, return an empty string
TEST(FormatTest, Empty_String_No_Args_Test) {
  auto s = ext::format("");
  EXPECT_EQ(s, "");
}
 
// Format string contains no arguments, ignore arguments passed
// and return the format string
TEST(FormatTest, Format_String_With_No_Args_Test) {
  auto s = ext::format("", "hello world", 5, 1e-200);
  EXPECT_EQ(s, "");

  s = ext::format("hello world", 88, 'a', "good bye!");
  EXPECT_EQ(s, "hello world");
}

// Just some typical tests - nothing should go wrong!
TEST(FormatTest, Typical_Test) {
  auto s = ext::format("%1 + %2 = %3", 5, 10.5, 5 + 10.5);
  EXPECT_EQ(s, "5 + 10.5 = 15.5");

  s = ext::format("%1%2 %1%2 %1%2 %1%2%3", "foo", "bar", 5);
  EXPECT_EQ(s, "foobar foobar foobar foobar5");
}

// Works with user defined types that have overloaded the 
// ostream operator<<
TEST(FormatTest, User_Type_Test) {
  foo my_foo(10);
  auto s = ext::format("%1", my_foo);
  EXPECT_EQ(s, "foo(10)");

}


} //namespace test_vector
