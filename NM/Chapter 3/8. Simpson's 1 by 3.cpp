#include <stdio.h>
#include <math.h>
#define f(x) (1-exp(-(x)/2.0))
int main() {
    double a, b, h, ifx = 0.0, i;
    int n;
    printf("Input the lower and upper limits of the integral: ");
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("\nInput the number of subintervals(Even No.): ");
    scanf("%d", &n);
    h=fabs((b-a)/n); 
    ifx=ifx+f(a)+f(b);
    for(i=a+h;i<b;i=i+(2*h)) {
        ifx=ifx+(4*f(i));
    }
    for(i=a+(2*h);i<b;i=i+(2*h)){
        ifx=ifx+(2*f(i));
    }
    ifx=ifx*h/3;
    printf("\nThe integral of the eqn using Simpsons 1/3rd Rule is %lf\n",ifx);
    return 0;
}

