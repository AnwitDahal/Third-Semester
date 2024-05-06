#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x+1)

float calculate_integral(float l, float u, int n) {
    float h = (u - l) / 3;
    float integral = f(l) + f(u);

    for (int i = 1; i <= n - 1; i++) {
        float k = l + i * h;
        if (i % 3 == 0) {
            integral += 2 * f(k);
        } else {
            integral += 3 * f(k);
        }
    }

    integral *= h * 3 / 8;
    return integral;
}

int main() {
    float a, b, int_val;
    int n;

    printf("Input value of 'a': ");
    scanf("%f", &a);
    printf("Input value of 'b': ");
    scanf("%f", &b);
    printf("Input number of sub intervals: ");
    scanf("%d", &n);

    int_val = calculate_integral(a, b, n);

    printf("\nValue of integration is= %.3f\n", int_val);

    return 0;
}

