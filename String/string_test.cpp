#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

#include "string.cpp"

TEST(CustomStringOperators, emptyString) {
  CustomStringOperators<char> str;
  EXPECT_EQ(str, "");
}

TEST(CustomStringOperators, init_from_const_char) {
  CustomStringOperators<char> str{"this is a char"};
  EXPECT_EQ(str, "this is a char");
}

TEST(CustomStringOperators, init_from_basic_string) {
  CustomStringOperators<char> str{"this is a char"};
  EXPECT_EQ(str, "this is a char");
}

TEST(CustomStringOperators, plus_assign_operator) {
  CustomStringOperators<char> str{"t"};
  str += CustomStringOperators<char> { "i"};
  EXPECT_EQ(str, "ti");
}
TEST(CustomStringOperators, copyctor) {
  CustomStringOperators<char> str{"this is a str"};
  auto k = str;
  EXPECT_EQ(k, "this is a str");
}

TEST(CustomStringOperators, comparisonOperator) {
  CustomStringOperators<char> str1{"compared string"};
  std::string str2{"compared string"};
    EXPECT_TRUE( str1 == str2 );
}



