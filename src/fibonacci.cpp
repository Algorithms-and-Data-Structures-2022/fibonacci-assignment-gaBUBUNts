#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }
    auto five = sqrt(5);
    auto f = (1 + five)/2;
    auto p = (1 - five)/2;
    auto res = (pow(f, n)-pow(p, n))/five;
    return static_cast<int64_t>(round(res));

  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    for (int i = 2; i <= n; i++) {
      auto temp = fib_curr;
      fib_curr = fib_prev + fib_curr;
      fib_prev = temp;
    }

    return fib_curr;
  }

  int64_t fib_recursive(int n) {

    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return 1;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] == -1) {
      cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
      return cache[n];
    }
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    Matrix2x2 mat;
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;
    mat = matrix_power(mat, n);

    // Tip: используйте реализованную функцию matrix_pow

    return mat[0][1];
  }

}  // namespace assignment
