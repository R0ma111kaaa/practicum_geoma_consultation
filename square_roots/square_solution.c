#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define EPSILON 1E-7  

int find_roots(double a, double b, double c, double result[2]) {

    double discriminant = b * b - 4 * a * c;
    
    if (discriminant > 0) {
        double sqrt_discriminant = sqrt(discriminant);
        result[0] = (-b - sqrt_discriminant) / (2 * a);
        result[1] = (-b + sqrt_discriminant) / (2 * a);

        if (result[0] > result[1]) {
            double temp = result[0];
            result[0] = result[1];
            result[1] = temp;
        }
        return 2;
    } else if (discriminant == 0) {
        result[0] = -b / (2 * a);
        return 1;
    } else {
        return 0;
    }
}
