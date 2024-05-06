#include <stdio.h>

// Function to compute factorial
int fact(int x) {
    if (x == 0 || x == 1) {
        return 1;
    } else {
        return x * fact(x - 1);
    }
}

int main() {
    int n;
    printf("How many data points? = ");
    scanf("%d", &n);

    // Arrays to store x and f(x) values
    float xi[n], fi[n];

    // Input data points
    printf("Enter the data points and corresponding values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &xi[i], &fi[i]);
    }

    float val;
    printf("Enter the value at which value is needed = ");
    scanf("%f", &val);

    // Compute step size
    float h = xi[1] - xi[0];

    // Compute normalized x value
    float x = (val - xi[n - 1]) / h;

    // Array to store backward differences
    float bd[n];

    // Initialize bd array with initial function values
    for (int i = 0; i < n; i++) {
        bd[i] = fi[i];
    }

    // Calculate backward differences
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            bd[j] = bd[j + 1] - bd[j];
        }
    }

    // Initialize interpolated value with the last function value
    float v = bd[0];
    float s = x;
    float p = 1;

    // Calculate the interpolated value using Newton's backward difference formula
    for (int i = 1; i < n; i++) {
        p *= (s + i - 1);
        v += (bd[i] * p) / fact(i);
    }

    printf("Interpolated value at x = %.3f is %.3f\n", val, v);
    return 0;
}

