#include <stdio.h>
#include <stdlib.h>
#define f(x) ((x)*(x))
int main(){
	int n;
	printf("Enter the no. of data points:");
	scanf("%d",&n);
	float h[n],d[n],e[n];
	int x;
	printf("Enter the value of x=");
	scanf("%d",&x);
	printf("\nFor the value of h:");
	for (int i=0;i<n;i++){
		printf("\nEnter the value of h%d: ",i+1);
		scanf("%f",&h[i]);;
		d[i]=(f(x+h[i])-f(x-h[i]))/(2*h[i]);
		printf("Value of derivate of f(%d) = %.2f",x,d[i]);
	}
	return 0;
}

