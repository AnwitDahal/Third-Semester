
#include<stdio.h>
#include<math.h>

#define MAX 10

int main() {
    int i, n;
    float a, b;
    float x[MAX], y[MAX], sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_xsq = 0.0;

    printf("Linear Least Squares Method\n");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the data sets (x, y) one after another:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);

        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_xsq += pow(x[i], 2);
    }

    // Calculation of coefficients (a and b)
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_xsq - pow(sum_x, 2));
    a = (sum_y - b * sum_x) / n;

    printf("Equation of the line: y = %.2fx + %.2f\nA=%.2f\nB=%.2f", b, a,a,b);

    return 0;
}

