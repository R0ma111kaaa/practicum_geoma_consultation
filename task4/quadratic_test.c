#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include "quadratic.h"

// функция для округления до нескольких знаков после запятой как указано в
// задании
double roundX(double value, int precision) {
  double delta = pow(10.0, precision);
  return round(value * delta) / delta;
}

void test_quadratic_zero_a() {
  double *res = solve_quadratic(0, 1, 1);
  assert(res == NULL);
}

void test_quadratic_1_0_m1() {
  double *res = solve_quadratic(1, 0, -1);
  double correct_answer[2] = {1.0, -1.0};
  assert(res[0] == correct_answer[0] && res[1] == correct_answer[1] ||
         res[0] == correct_answer[1] && res[1] == correct_answer[0]);
}

void test_quadratic_1_0_0() {
  double *res = solve_quadratic(1, 0, 0);
  double correct_answer[1] = {0};
  assert(res[0] == correct_answer[0]);
}

void test_quadratic_1_0_1() {
  double *res = solve_quadratic(1, 0, 1);
  assert(res == NULL);
}

void test_quadratic_zero_1_0_m1em7() {
  double *res = solve_quadratic(1, 0, -1e-7);
  double correct_answer[2] = {-3E-4, 3E-4};
  assert(roundX(res[0], 4) == correct_answer[0] &&
             roundX(res[1], 4) == correct_answer[1] ||
         roundX(res[0], 4) == correct_answer[1] &&
             roundX(res[1], 4) == correct_answer[0]);
}

void test_quadratic_zero_1_m1e10_m1() {
  double *res = solve_quadratic(1, -1E+10, -1);
  double correct_answer[2] = {-1E-10, 1E+10};
  assert(roundX(res[0], 11) == correct_answer[0] &&
             roundX(res[1], 11) == correct_answer[1] ||
         roundX(res[0], 11) == correct_answer[1] &&
             roundX(res[1], 11) == correct_answer[0]);
}

void test_quadratic_zero_1_0_m1em8() {
  double *res = solve_quadratic(1, 0, -1E-8);
  double correct_answer[2] = {1E-4, -1E-4};
  assert(roundX(res[0], 7) == correct_answer[0] &&
             roundX(res[1], 7) == correct_answer[1] ||
         roundX(res[0], 7) == correct_answer[1] &&
             roundX(res[1], 7) == correct_answer[0]);
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