#include "quadratic.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double *solve_quadratic(double a, double b, double c) {
  if (a == 0) {
    return (double *)NULL;
  }

  double d = b * b - 4 * a * c;

  if (d < 0) {
    return (double *)NULL;
  }

  if (fabs(d) < 1e-10) {
    double *roots = (double *)malloc(sizeof(double));
    roots[0] = -b / (2 * a);
    return roots;
  } else {
    double *roots = (double *)malloc(2 * sizeof(double));
    if (b > 0) {
      roots[0] = (-b - sqrt(d)) / (2 * a);
      roots[1] = c / (a * roots[0]);
    } else {
      roots[0] = (-b + sqrt(d)) / (2 * a);
      roots[1] = c / (a * roots[0]);
    }
    return roots;
  }
}
