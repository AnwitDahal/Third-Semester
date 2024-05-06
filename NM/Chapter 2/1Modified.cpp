#include <stdio.h>

int main() {
    int n;
    float val = 0;
    printf("How many data points?=");
    scanf("%d", &n);
    float xData[n], yData[n];
    printf("Enter the data points and corresponding values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f%f", &xData[i], &yData[i]);
    }
    float x;
    printf("Enter the point at which value is needed=");
    scanf("%f", &x);
    float l[n];
    for (int i = 0; i < n; i++) {
        float prod = 1;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                prod *= (x - xData[j]) / (xData[i] - xData[j]);
            }
        }
        l[i] = prod;
    }
    for (int i = 0; i < n; i++) {
        val += yData[i] * l[i];
    }
    printf("The interpolated value at x=%.3f is %.3f\n", x, val);
    return 0;
}

