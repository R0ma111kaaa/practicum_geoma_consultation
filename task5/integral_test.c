#include "integral.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double parabol(double x) { return pow(x, 2); }

void test_parabol_1() {
  double res = integral(1, 2, parabol);
  double correct_answer = 2.33333;
  assert(fabs(res - correct_answer) <= correct_answer * 1e-5);
}

void test_parabol_2() {
  double res = integral(17, 87, parabol);
  double correct_answer = 217863.33333;
  assert(fabs(res - correct_answer) <= correct_answer * 1e-5);
}

int main() {
  test_parabol_1();
  test_parabol_2();
  return 0;
}