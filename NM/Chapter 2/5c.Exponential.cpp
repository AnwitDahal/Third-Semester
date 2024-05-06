#include <stdio.h>
#include<math.h>
int main() {
    int n, i;
    double a, b, res = 0, res2 = 0, res3 = 0, res4 = 0,res5=0,ex;
    double x[20], y[20], x2[20], lgy[20],xlgy[20];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the array for x:");
    for (i = 0; i < n; i++) {
        scanf("%lf", &x[i]);
        res += x[i];
    }

    printf("Enter the array for y:");
    for (i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
        res2 += y[i];
    }

    for (i = 0; i < n; i++) {
        x2[i] = x[i] * x[i];
        res3 += x2[i];
        lgy[i] = log(y[i]);
        res4 += lgy[i];
        xlgy[i]=x[i]*log(y[i]);
        res5+=xlgy[i];
    }

    b = ((n * res5) - (res * res4)) / ((n * res3) - (res * res));
    a = ((res4 / n) - b * (res / n));
	ex=exp(a);
    printf("The exp eqn is y = %.2lf e ^ %.2lf x\n", ex, b);

    return 0;
}

