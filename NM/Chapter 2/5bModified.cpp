#include <math.h>
#include <stdio.h>

int main() {
    int i, j, k, m, n;

    printf("Enter no. of data points= ");
    scanf("%d", &n);

    float x[n], y[n], a[n], c[n][n], power, r;

    printf("Enter order of polynomial: ");
    scanf("%d", &m);

    printf("Enter the value of x and y:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    // Calculation of coefficient matrix
    for (j = 0; j <= m; j++) {
        for (k = 0; k <= m; k++) {
            c[j][k] = 0;
            for (i = 0; i < n; i++) {
                power = pow(x[i], j + k);
                c[j][k] += power;
            }
        }
    }

    // Calculation of right-hand side vector
    for (j = 0; j <= m; j++) {
        c[j][m + 1] = 0;
        for (i = 0; i < n; i++) {
            r = pow(x[i], j);
            c[j][m + 1] += y[i] * r;
        }
    }

    // Gaussian elimination to solve the system of linear equations
    for (k = 0; k <= m; k++) {
        for (i = k + 1; i <= m; i++) {
            float factor = c[i][k] / c[k][k];
            for (j = k; j <= m + 1; j++) {
                c[i][j] -= factor * c[k][j];
            }
        }
    }
    printf("\n");

    // Back substitution to find the coefficients
    for (i = m; i >= 0; i--) {
        a[i] = c[i][m + 1];
        for (j = i + 1; j <= m; j++) {
            a[i] -= c[i][j] * a[j];
        }
        a[i] /= c[i][i];
        printf("a[%d] = %.2f\n", i, a[i]);
    }

    return 0;
}

