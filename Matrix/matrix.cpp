#include <algorithm>
#include <array>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <functional>

template <std::size_t N, std::size_t M, typename T>
struct Matrix
{
    Matrix()
    {
        if(N==0 || M==0) 
          throw std::underflow_error {"Number of rows and columns must be greater than 0."};
    }
    template <std::size_t N1,std::size_t M1, typename T1>
    Matrix(const Matrix< N1, M1, T1> &copiedMatrix)
    {
         if (N1 > N) {
            throw std::range_error { "number of rows error" };
        }
        if (M1 > M) {
            throw std::range_error { "number of columns error" };
        }
    
        for(std::size_t i=0; i<N1;++i)
        {
          for(std::size_t j=0; j<M1; j++)
          {        
            array[i][j]=copiedMatrix[i][j];
          }
        }
    }
    std::array<T, M> &operator[](std::size_t index)
    {
        return array.at(index);
    }

    const std::array<T, M> &operator[](std::size_t index) const
    {
        return array.at(index);
    }

    template <std::size_t N1,std::size_t M1, typename T1>
    Matrix<N,M,T> &operator+=(Matrix<N1,M1,T1> &object) 
    {
        if (N1 > N) {
            throw std::range_error { "number of rows error" };
        }
        if (M1 > M) {
            throw std::range_error { "number of columns error" };
        }
        
        for(std::size_t i=0; i<N1;++i)
        {
          for(std::size_t j=0; j<M1; j++)
          {        
            array[i][j]=array[i][j]+object[i][j];
          }
        }
        return *this;

    }

    template <std::size_t N1,std::size_t M1, typename T1>
    Matrix<N,M,T> operator+(Matrix<N1,M1,T1> &object) const
    {
        if (N1 > N) {
            throw std::range_error { "number of rows error" };
        }
        if (M1 > M) {
            throw std::range_error { "number of columns error" };
        }
        Matrix<N,M,T> sum;
        for(std::size_t i{0}; i<N1;++i)
        {
            for(std::size_t j{0}; j<M1;j++)
            {
              sum[i][j]=array[i][j]+object[i][j];
            }
        }
        return sum;
    }

    template<std::size_t N1, std::size_t M1, typename T1>
    friend std::ostream &operator<<(std::ostream &ostr, Matrix<N1,M1,T1> &);

private:

std::array<std::array<T,M>,N> array {};
};


template<std::size_t N,std::size_t M, typename T>
std::ostream &operator<<(std::ostream &ostr, Matrix<N,M,T> &object)
{
    for(const auto &row : object.array)
    {
        for(const auto &element : row) ostr<<element;
       
        ostr<<std::endl;
    }
    return ostr;
}



template<std::size_t N, std::size_t M>
struct Matrix<N, M, bool> 
{
    Matrix() {
        throw std::bad_typeid { };
    }
};