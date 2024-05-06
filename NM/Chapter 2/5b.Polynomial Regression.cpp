#include <stdio.h>

int main() {
    int n, i;
    double a, b, res = 0, res2 = 0, res3 = 0, res4 = 0;
    int x[20], y[20], x2[20], xy[20];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the array for x:");
    for (i = 0; i < n; i++) {
        scanf("%d", &x[i]);
        res += x[i];
    }

    printf("Enter the array for y:");
    for (i = 0; i < n; i++) {
        scanf("%d", &y[i]);
        res2 += y[i];
    }

    for (i = 0; i < n; i++) {
        x2[i] = x[i] * x[i];
        res3 += x2[i];
        xy[i] = x[i] * y[i];
        res4 += xy[i];
    }

    b = ((n * res4) - (res * res2)) / ((n * res3) - (res * res));
    a = ((res2 / n) - b * (res / n));

    printf("The linear eqn is y = %.2lf + %.2lf x\n", a, b);

    return 0;
}

