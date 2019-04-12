#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <array>
#include <string>

#include "matrix.cpp"


TEST(TemplateMatrix, create) {
    Matrix<3, 5, int> m;
    EXPECT_EQ(m[0][0], 0);
    m[2][1] = 1;
    EXPECT_EQ(m[2][1], 1);
}

TEST(TemplateMatrix, createZero) {
    auto l = []() {
        Matrix<0, 3, int> m;
    };
    EXPECT_THROW(l(), std::underflow_error);

    auto l2 = []() {
        Matrix<3, 0, int> m;
    };
    EXPECT_THROW(l2(), std::underflow_error);
}

TEST(TemplateMatrix, createBool) {
    auto l = []() {
        Matrix<3, 3, bool> m;
    };
    EXPECT_THROW(l(), std::bad_typeid);
}

TEST(TemplateMatrix, copyCtor) {
    int number = 0;
    const int I = 2;
    const int J = 3;

    Matrix<I, J, int> m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }

    Matrix<I, J, int> n = m;

    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}

TEST(TemplateMatrix, copyCtorCopy) {
    int number = 0;
    const int I = 2;
    const int J = 2;

    Matrix<I, J, int> m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            m[i][j] = ++number;
        }
    }
    Matrix<3, 3, int> n = m;
    for (int i = 0; i < I; ++i) {
        for (int j = 0; j < J; ++j) {
            EXPECT_EQ(m[i][j], n[i][j]);
        }
    }
}

TEST(TemplateMatrix, copyCtorExcept) {
    auto l = [&]() {
        Matrix<3, 3, int> m;
        m[1][1] = 5;
        Matrix<2, 3, int> n = m;
    };
    EXPECT_THROW(l(), std::range_error);
    auto o = [&]() {
        Matrix<3, 3, int> m;
        m[1][1] = 5;
        Matrix<3, 2, int> n = m;
    };
    EXPECT_THROW(o(), std::range_error);
}

TEST(TemplateMatrix, operatorForOutputstreams)
{
    auto fourValuesSource = [&]() 
    {
      Matrix<2, 1, int> source;
      source[0][0]=0;
      source[1][0]=1;
      
      std::ostringstream os;
      os<<source[0][0];
      os<<source[1][0];

      return os;
    };

    EXPECT_EQ(fourValuesSource().str(), "01");
}

TEST(TemplateMatrix, AdditionAssignment)
{
      Matrix<2, 2, int> x;
      x[0][0]=0;
      x[1][0]=1;
      x[0][1]=2;
      x[0][1]=3;
      Matrix<2, 2, int> y;
      y[0][0]=4;
      y[1][0]=2;
      y[0][1]=3;
      y[0][1]=4;

      x+=y; 

    EXPECT_EQ(x[0][0], 4);
    EXPECT_EQ(x[0][1], 7);
}

TEST(TemplateMatrix, AdditionAssignmentTooBigElement)
{
      auto l = [&]() {
        Matrix<3, 3, int> x;
      for(int i{0}; i<3; ++i)
        for(int j{0}; j<3; ++j)
            x[i][j]=3;
      Matrix<4, 4, int> y;
      for(int i{0}; i<4; ++i)
        for(int j{0}; j<4; ++j)
            y[i][j]=5;
      x+=y;
    };
    EXPECT_THROW(l(), std::range_error);
  
}
TEST(TemplateMatrix, PlusOperatorTooBigElement)
{
      auto l = [&]() {
        Matrix<3, 3, int> x;
      for(int i{0}; i<3; ++i)
        for(int j{0}; j<3; ++j)
            x[i][j]=3;
      Matrix<4, 4, int> y;
      for(int i{0}; i<4; ++i)
        for(int j{0}; j<4; ++j)
            y[i][j]=5;
      x+=y;
    };
    EXPECT_THROW(l(), std::range_error);
    
}
TEST(TemplateMatrix, PlusOperator)
{
    Matrix<3, 3, int> x;
    for(int i{0}; i<3; ++i)
      for(int j{0}; j<3; ++j)
          x[i][j]=3;
    Matrix<3, 3, int> y;
    for(int i{0}; i<3; ++i)
      for(int j{0}; j<3; ++j)
          y[i][j]=5;
    Matrix<3, 3, int> sum;
    for(int i{0}; i<3; ++i)
      for(int j{0}; j<3; ++j)
          sum[i][j]=0;
    sum=x+y;

    EXPECT_EQ(sum[0][0], 8); 
    EXPECT_EQ(sum[2][2], 8);
}