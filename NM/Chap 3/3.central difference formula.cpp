#include <stdio.h>
#include <stdlib.h>

#define f(x) ((x)*(x))

float compute_derivative(float x, float h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    int num_points;
    printf("Please enter the number of data points:");
    scanf("%d", &num_points);

    float steps[num_points], derivatives[num_points];

    int input_x;
    printf("Enter the value of x:");
    scanf("%d", &input_x);

    printf("\nFor the value of h:");
    for (int i = 0; i < num_points; i++) {
        printf("\nEnter the value of step %d: ", i + 1);
        scanf("%f", &steps[i]);
        derivatives[i] = compute_derivative(input_x, steps[i]);
        printf("Derivative of f(%d) = %.2f", input_x, derivatives[i]);
    }
    return 0;
}

