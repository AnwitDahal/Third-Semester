#include <stdio.h>
#include <math.h>
#define f(x) (x*x-3*x+2)
#define g(x) (2*x-3)
int main(){
	float x0,x1,e;
	printf("Enter initial points=");
	scanf("%f",&x0);
	printf("Enter error value=");
	scanf("%f",&e);
	do {
        x1=x0-(f(x0)/g(x0));
        x0=x1;
    } while(fabs((x1-x0)/x1)>e);
    printf("The root of the equation is: %f\n", x1);
    return 0;
}
