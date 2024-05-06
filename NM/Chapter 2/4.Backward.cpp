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
    float x = (val - xi[0]) / h;

    float fd[n];
    for (int i = 0; i < n; i++) {
        fd[i] = fi[i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            fd[j] = fd[j] - fd[j - 1];
        }
    }

    float v = fi[0];
    float s = x;
    float p = 1;

    for (int i = 1; i < n; i++) {
        p *= (s - i + 1);
        v += (fd[i] * p) / fact(i);
    }

    printf("Interpolated value at x=%.3f is %.3f\n", val, v);
    return 0;
}

