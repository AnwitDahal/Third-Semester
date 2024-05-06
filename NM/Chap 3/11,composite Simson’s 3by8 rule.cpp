#include<stdio.h>

#define f(x) (x*x*x+1)

float calculate_integral(float l, float u, int n) {
    float h = (u - l) / n;
    float res = f(l) + f(u);

    for (int i = 1; i < n; i++) {
        float x = l + i * h;
        if (i % 3 == 0) {
            res += 2 * f(x);
        } else {
            res += 3 * f(x);
        }
    }
    
    res *= (3.0 * h / 8.0);

    return res;
}

int main() {
    float a, b, int_val;
    int n;

    printf("Input value of 'a': ");
    scanf("%f", &a);
    printf("Input value of 'b': ");
    scanf("%f", &b);
    printf("Input number of sub intervals (must be multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Error: Number of sub intervals must be a multiple of 3.\n");
        return 1;
    }

    int_val = calculate_integral(a, b, n);

    printf("\nValue of integration is= %.3f\n", int_val);

    return 0;
}

