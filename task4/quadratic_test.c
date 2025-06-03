#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "quadratic.h"

#define DEFAULT_EPSILON 1e-7

bool is_doubles_the_same(long double a, long double b, long double eps) {
  return fabs(a - b) < eps;
}

void test_quadratic_zero_a() {
  long double *res = solve_quadratic(0, 1, 1);
  assert(res == NULL);
}

void test_quadratic_1_0_m1() {
  long double *res = solve_quadratic(1, 0, -1);
  long double correct_answer[2] = {-1.0, 1.0};
  assert(is_doubles_the_same(res[0], correct_answer[0], DEFAULT_EPSILON) &&
         is_doubles_the_same(correct_answer[1], res[1], DEFAULT_EPSILON));
}

void test_quadratic_1_0_0() {
  long double *res = solve_quadratic(1, 0, 0);
  long double correct_answer[1] = {0};
  assert(is_doubles_the_same(res[0], correct_answer[0], DEFAULT_EPSILON));
}

void test_quadratic_1_0_1() {
  long double *res = solve_quadratic(1, 0, 1);
  assert(res == NULL);
}

void test_quadratic_zero_1_0_m1em7() {
  long double local_epsilon = 1e-4;
  long double *res = solve_quadratic(1, 0, -1e-7);
  long double correct_answer[2] = {-3E-4, 3E-4};
  assert(is_doubles_the_same(res[0], correct_answer[0], local_epsilon) &&
         is_doubles_the_same(correct_answer[1], res[1], local_epsilon));
}

void test_quadratic_zero_1_m1e10_m1() {
  long double local_epsilon = 1e-11;
  long double *res = solve_quadratic(1, -1E+10, -1);
  long double correct_answer[2] = {-1E-10, 1E+10};
  assert(is_doubles_the_same(res[0], correct_answer[0], local_epsilon) &&
         is_doubles_the_same(correct_answer[1], res[1], local_epsilon));
}

void test_quadratic_zero_1_0_m1em8() {
  long double local_epsilon = 1e-7;
  long double *res = solve_quadratic(1, 0, -1E-8);
  long double correct_answer[2] = {-1E-4, 1E-4};
  assert(is_doubles_the_same(res[0], correct_answer[0], local_epsilon) &&
         is_doubles_the_same(correct_answer[1], res[1], local_epsilon));
}

int main() {
  test_quadratic_zero_a();
  test_quadratic_1_0_m1();
  test_quadratic_1_0_0();
  test_quadratic_1_0_1();
  test_quadratic_zero_1_0_m1em7();
  test_quadratic_zero_1_m1e10_m1();
  test_quadratic_zero_1_0_m1em8();
  return 0;
}
