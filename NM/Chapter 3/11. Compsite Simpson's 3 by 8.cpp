#include <stdio.h>
#include <math.h>

double func(double a, double x[], int de) {
    double result = 0;
    int i = 0;
    while (de >= 0) {
        result = result + (x[i] * pow(a, de));
        de--;
        i++;
    }
    return result;
}

int main() {
    int de, i, n;
    double a, b, f1, f2, res, x[10], h, res2 = 0.00, res3 = 0.00;
    printf("Implementation of composite Simpson's 3/8 rule\n\n");
    printf("Enter the limits of integration (a and b): ");
    scanf("%lf %lf", &a, &b);
    //1 2
    printf("Enter the highest degree of the polynomial: ");
    //3
    scanf("%d", &de);
    printf("Enter the coefficients of the polynomial (in descending order of degree):\n");
    //1 0 0 1
    for (i = 0; i < de + 1; i++) {
        scanf("%lf", &x[i]);
    }
    printf("Enter the number of partitions (must be a multiple of 3): ");
    //3
    scanf("%d", &n);
    if (n % 3 != 0) {
        printf("Number of partitions must be a multiple of 3.\n");
        //3
        return 1;
    }
    h = (b - a) / n;
    f1 = func(a, x, de);
    f2 = func(b, x, de);
    res2 = f1 + f2;
    for (i = 1; i < n; i++) {
        if (i % 3 == 0) {
            res2 += 2 * func(a + i * h, x, de);
        } else {
            res2 += 3 * func(a + i * h, x, de);
        }
    }
    res = (3.0 / 8.0) * h * res2;
    printf("The result of the integration is: %lf\n", res);
    return 0;
}

