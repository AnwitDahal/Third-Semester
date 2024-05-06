#include <stdio.h>
#include <stdlib.h>

float compute_derivative(float xs[], float ys[], int num_pts, float x_val) {
    float h = xs[1] - xs[0];
    int idx = -1;

    for (int i = 0; i < num_pts - 1; i++) {
        if (xs[i] <= x_val && xs[i + 1] >= x_val) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Error!The value of x is not within the range of data points.\n");
        exit(1);
    }

    return (ys[idx + 1] - ys[idx]) / h;
}

int main() {
    int num_pts;
    printf("Input the number of data points: ");
    scanf("%d", &num_pts);

    float xs[num_pts], ys[num_pts], x_val, derivative;

    printf("Input the data points and corresponding values:\n");
    for (int i = 0; i < num_pts; i++) {
        scanf("%f%f", &xs[i], &ys[i]); 
    }

    printf("Input the value of x: ");
    scanf("%f", &x_val);

    derivative = compute_derivative(xs, ys, num_pts, x_val);
    printf("The derivative at x = %.2f is: %.2f\n", x_val, derivative);

    return 0;
}

