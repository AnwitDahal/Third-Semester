#include <stdio.h>
#include <stdlib.h>

float calculate_derivative(float x[], float y[], int n, float xp) {
    float h = x[1] - x[0];
    int index = -1;

    for (int i = n - 1; i > 0; i--) {
        if (x[i] <= xp) {
            index = i;
            break;
        }
    }

    if (index == -1 || index == 0) {
        printf("Error: The value of x is not within the range of data points.\n");
        exit(1);
    }

    return (y[index] - y[index - 1]) / h;
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

    derivative = calculate_derivative(xs, ys, num_pts, x_val);
    printf("The derivative at x = %.2f is: %.2f\n", x_val, derivative);

    return 0;
}

