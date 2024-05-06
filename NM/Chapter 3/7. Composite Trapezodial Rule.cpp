#include <stdio.h>
#include <math.h>

#define f(x) exp(x)

int main() {
    int i, n;
    float a, b, h, sum = 0.0, ict = 0.0;
    printf("\nEnter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);
    printf("Enter the number of segments: ");
    scanf("%d", &n);
    h = (b - a) / n;
    sum = (h / 2) * (f(a) + f(b));
    for (i = 1; i <= n - 1; i++) {
        sum =sum+ f(a + i * h);
    }
    ict = sum * h;
    printf("\nThe integration value of the function = %f\n", ict);
	return 0;
}

