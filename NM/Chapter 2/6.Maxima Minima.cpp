#include <stdio.h>

void findMaximaMinima(int n, double x[], double y[]) {
    int i;
    printf("Maxima:\n");
    for (i = 1; i < n - 1; i++) {
        if (y[i] > y[i - 1] && y[i] > y[i + 1]) {
            printf("x = %.2lf, y = %.2lf\n", x[i], y[i]);
        }
    }
    printf("Minima:\n");
    for (i = 1; i < n - 1; i++) {
        if (y[i] < y[i - 1] && y[i] < y[i + 1]) {
            printf("x = %.2lf, y = %.2lf\n", x[i], y[i]);
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    printf("Enter the x-axis values:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
    }
    printf("Enter the y-axis values:\n");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }

    findMaximaMinima(n, x, y);

    return 0;
}

