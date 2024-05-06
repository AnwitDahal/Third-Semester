#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double a, b, sum_x = 0.0, sum_y = 0.0, sum_x2 = 0.0, sum_lgy = 0.0, sum_xlgy = 0.0;
    double x[20], y[20];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the value of x and y:\n");
    for (int i = 0; i < n; i++) {
            printf("x[%d]=",i);
            scanf("%lf",&x[i]);
            printf("y[%d]=",i);
            scanf("%lf",&y[i]);
    }
    
    for(int i=0;i<n;i++){
        sum_x += x[i];
        sum_y += log(y[i]);
    }
   

    for (int i = 0; i < n; i++) {
        sum_x2 += x[i] * x[i];
        sum_lgy += log(y[i]);
        sum_xlgy += x[i] * log(y[i]);
    }

    b = ((n * sum_xlgy) - (sum_x * sum_lgy)) / ((n * sum_x2) - (sum_x * sum_x));
    a = exp((sum_lgy / n) - b * (sum_x / n));

    printf("The exponential equation is: y = %.2lf * e^(%.2lf * x)\nwhere,\na=%.2f\nb=%.2f", a, b,a,b);

    return 0;
}

