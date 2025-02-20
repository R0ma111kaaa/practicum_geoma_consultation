#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "square_solution.c"

void test_case(double a, double b, double c, int expected_count, double expected_roots[2]) {
    double result[2];
    int root_count = find_roots(a, b, c, result);
    
    assert(root_count == expected_count);
    
    for (int i = 0; i < root_count; i++) {
        if (fabs(result[i] - expected_roots[i]) > EPSILON) {
            printf("Ошибка! Ожидаемый корень: %.7f, Полученный корень: %.7f\n", expected_roots[i], result[i]);
        }
    }
}

int main() {
    double expected_roots1[2] = {-1, 1};
    test_case(1, 0, -1, 2, expected_roots1);

    double expected_roots2[1] = {0};
    test_case(1, 0, 0, 1, expected_roots2);

    double expected_roots3[0] = {};
    test_case(1, 0, 1, 0, expected_roots3);

    double expected_roots4[2] = {-0.0003, 0.0003};
    test_case(1, 0, -1E-7, 2, expected_roots4);

    double expected_roots5[2] = {-1E-10, 1E+10};
    test_case(1, -1E+10, -1, 2, expected_roots5);

    double expected_roots6[1] = {0};
    test_case(1, 0, -1E-8, 1, expected_roots6);

    printf("Все тесты пройдены успешно.\n");
    return 0;
}
