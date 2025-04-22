#include "quadratic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-10

long double *solve_quadratic(long double a, long double b, long double c) {
  if (a == 0) {
    return (long double *)NULL;
  }

  long double d = b * b - 4 * a * c;

  if (d < -EPSILON) {
    return (long double *)NULL;
  }

  if (fabs(d) < EPSILON) {
    long double *roots = (long double *)malloc(sizeof(long double));
    roots[0] = -b / (2 * a);
    return roots;
  } else {
    long double *roots = (long double *)malloc(2 * sizeof(long double));
    long double sqrt_d = sqrt(d);

    long double q = -0.5 * (b + (b > 0 ? sqrt_d : -sqrt_d));
    roots[0] = q / a;
    roots[1] = c / q;

    if (roots[0] > roots[1]) {
      long double temp = roots[1];
      roots[1] = roots[0];
      roots[0] = temp;
    }

    return roots;
  }
}
