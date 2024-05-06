#include <stdio.h>

int fact(int x) {
    if (x == 0 || x == 1) {
        return 1;
    } else {
        return x * fact(x - 1);
    }
}

int main() {
    int n;
    printf("How many data points?=");
    scanf("%d", &n);

    float xi[n], fi[n];
    printf("Enter the data points and corresponding values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f%f", &xi[i], &fi[i]);
    }

    float val;
    printf("Enter the value at which value is needed=");
    scanf("%f", &val);

    float h = xi[1] - xi[0];
    float x = (val - xi[n - 1]) / h;

    float bd[n];
    for (int i = 0; i < n; i++) {
        bd[i] = fi[i];
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            bd[j] = bd[j + 1] - bd[j];
        }
    }

    float v = fi[n - 1];
    float s = x;
    float p = 1;

    for (int i = 1; i < n; i++) {
        p *= (s + i - 1);
        v += (bd[i] * p) / fact(i);
    }

    printf("Interpolated value at x=%.3f is %.3f\n", val, v);
    return 0;
}

