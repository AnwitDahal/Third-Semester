#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("derivative using forward divided difference formula\n\n");
    int i,n;
    printf("Enter number of data points: ");
    scanf("%d", &n);
    float x[n], y[n], xp, h, derivative;


    printf("Enter data points:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]); 
        printf("y[%d] = ", i);
        scanf("%f", &y[i]); 
    }
    printf("Enter the value of x at which derivative is to be calculated: ");
    scanf("%f", &xp);
    //9
    h = x[1] - x[0];
    int index = -1;
    for (i = 0; i < n - 1; i++) {
        if (x[i] <= xp && x[i + 1] >= xp) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Error: The value of x is not within the range of data points.\n");
        exit(1);
    }

    
    derivative = (y[index + 1] - y[index]) / h;
    printf("The derivative at x = %0.2f is: %0.2f\n", xp, derivative);

    return 0;
}
