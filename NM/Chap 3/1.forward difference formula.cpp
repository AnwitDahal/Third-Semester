#include <stdio.h>

#define f(x) ((x)*(x))

float calculate_derivative(float x, float h) {
    return (f(x+h) - f(x)) / h;
}

int main() {
    int num_points;
    printf("Please input the number of data points: ");
    scanf("%d", &num_points);

    float intervals[num_points], derivatives[num_points];

    float input_x;
    printf("Please input the value of x: ");
    scanf("%f", &input_x);

    printf("\nInput the intervals (h):");
    for (int i = 0; i < num_points; i++) {
        printf("\nEnter the value of interval %d: ", i + 1);
        scanf("%f", &intervals[i]);
        derivatives[i] = calculate_derivative(input_x, intervals[i]);
        printf("Derivative of f(%.2f) = %.2f\n", input_x, derivatives[i]);
    }

    return 0;
}

