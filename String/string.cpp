#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>


template <typename Char> struct CustomStringOperators 
{

  template <typename T>
  friend bool operator==(const CustomStringOperators<T> &custom, const std::string &str);

  CustomStringOperators() = default;
  CustomStringOperators(const Char *ptr) 
  {
    for(std::size_t i=0; i<std::strlen(ptr);i++) _data.push_back(*(ptr+i));
  }

  CustomStringOperators(const std::basic_string<Char> &str) 
  {
     for(auto &element:str) _data.push_back(element);
  }

  CustomStringOperators(const CustomStringOperators<Char>& other)
  {
      for(auto &element:other._data) _data.push_back(element);
  }

  CustomStringOperators& operator += (const CustomStringOperators<Char>& other)
  {
      for(auto &element:other._data) _data.push_back(element);
      return *this;
  }

private:
  std::vector<Char> _data;
};

template <typename T>
bool operator==(const CustomStringOperators<T> &custom, const std::string &str) 
{
  std::string temporaryString;
  for(auto &element:str)temporaryString.push_back(element);
  return temporaryString == str;
}