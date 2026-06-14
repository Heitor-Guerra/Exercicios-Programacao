#include <boost/algorithm/is_palindrome.hpp>  // algorithms
#include <boost/geometry.hpp>                 // geometry
#include <boost/math/constants/constants.hpp> // math and complex
#include <boost/multiprecision/cpp_int.hpp>   // multiprecision
#include <boost/numeric/ublas/matrix.hpp>     // UBLAS
#include <boost/numeric/ublas/tensor.hpp>     // UBLAS
#include <iostream>

boost::multiprecision::int1024_t boost_product(long long a, long long b) {
  return (boost::multiprecision::int1024_t)a * b;
}

boost::multiprecision::cpp_int boost_factorial(int num) {
  boost::multiprecision::cpp_int result = 1;
  for (int i = 2; i <= num; i++) {
    result *= i;
  }

  return result;
}

double boost_area(float radius) {
  double pi = boost::math::double_constants::pi;
  return pi * radius * radius;
}

bool boost_palindrome(std::string string) {
  return boost::algorithm::is_palindrome(string);
}

boost::geometry::model::point<float, 2, boost::geometry::cs::cartesian>
boost_point() {
  return boost::geometry::model::point<float, 2,
                                       boost::geometry::cs::cartesian>(1, 2);
}

boost::numeric::ublas::matrix<float> boost_ublas_matrix(int size) {
  boost::numeric::ublas::matrix<float> m(size, size);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      std::cin >> m(i, j);
    }
  }

  return m;
}

int main() { return 0; }
