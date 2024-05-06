#include<stdio.h>
#include<math.h>

#define f(x) (1 - exp(-(x) / 2.0))

float integrate(float ll, float ul, int n) {
    float h = (ul - ll) / n;
    float x = 0, y = 0;

    for (int i = 1; i <= (n / 2); i++) {
        x += f(ll + (2 * i - 1) * h);
    }
    x *= 4;

    for (int i = 1; i <= ((n / 2) - 1); i++) {
        y += f(ll + (2 * i) * h);
    }
    y *= 2;

    float i_val = f(ll) + f(ul) + x + y;
    i_val *= (h / 3);

    return i_val;
}

int main() {
    float a, b, i_val;
    int n;

    printf("Input lower limit 'a'=");
    scanf("%f", &a);
	printf("Input upper limit 'b'=");
    scanf("%f", &b);

    printf("\nInput no. of segments (Even Number)=");
    scanf("%d", &n);

    i_val = integrate(a, b, n);

    printf("The value of integration obtained is: %f\n", i_val);

    return 0;
}

