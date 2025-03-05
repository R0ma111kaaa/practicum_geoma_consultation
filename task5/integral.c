#include "integral.h"

#include <math.h>
#include <stdio.h>

double integral(double a, double b, double (*f)(double)) {
  double answer = (f(a) + f(b)) * (b - a) / 2 -
                  second_derivative((a + b) / 2, f) * pow(b - a, 3) / 12;
  return answer;
}

double second_derivative(double e, double (*f)(double)) {
  double h = 0.001;
  return (f(e + h) - 2 * f(e) + f(e - h)) / (h * h);
}