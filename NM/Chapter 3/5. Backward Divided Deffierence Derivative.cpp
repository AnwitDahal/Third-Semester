#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("derivative using backward divided difference formula\n\n");
    float x[20], y[20], xp, h, derivative;
    int i, n;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    printf("Enter data points:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i]);
    }

    printf("Enter the value of x at which derivative is to be calculated: ");
    scanf("%f", &xp);

    h = x[1] - x[0];
    int index = -1;
    for (i = 1; i < n; i++) {
        if (x[i] >= xp) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Error: The value of x is not within the range of data points.\n");
        exit(1);
    }
    derivative = (y[index] - y[index - 1]) / (x[index] - x[index - 1]);
    printf("The derivative at x = %0.2f is: %0.2f\n", xp, derivative);

    return 0;
}
