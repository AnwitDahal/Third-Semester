#include <stdio.h>
#include <math.h>
#define f(x) (cos(x))

int main(){
    int n;
    float x, h, max_val, min_val;
    printf("Enter number of tabulated points: ");
    scanf("%d", &n);
    printf("Enter value of h: ");
    scanf("%f", &h);

    max_val = min_val = f(0); // Initial value at x=0
    x = 0;
    
    // Iterate over the tabulated points
    for (int i = 1; i <= n; i++) {
        float y = f(x); // Compute function value at x
        
        // Update maximum and minimum values
        if (y > max_val) {
            max_val = y;
        }
        if (y < min_val) {
            min_val = y;
        }
        
        x += h; // Increment x by h
    }

    printf("Maximum Value = %f\nMinimum Value = %f\n", max_val, min_val);
    return 0;
}

