#include <stdio.h>
#include <math.h>
//#include <stdlib.h>
#define f(x) ((cos(x)+1)/3)
int main(){
	int n,i=1;
	float x0,x1;
	printf("Enter the no. of iteration=");
	scanf("%d",&n);
	printf("Enter the initial guess=");
	scanf("%f",&x0);
	while(i<=n){
		x1=f(x0);
		printf("Approximation %d to the root\n",i);
		printf("%f\n",x1);
		x0=x1;
		i++;
	}
	return 0;
}
