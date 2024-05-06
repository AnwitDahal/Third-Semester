#include <stdio.h>
int main(){
	int d,i,x;
	printf("Enter highest degree of eqn=");
	scanf("%d",&d);
	printf("Enter value at which polynomial to be evaluated=");
	scanf("%d",&x);
	int a[d+1],b[d+1];
	for (i=0;i<=d;i++){
		printf("Enter the coefficient of x^%d=",i);
		scanf("%d",&a[i]);
	}
	printf("Given polynomial eqn is=");
	for (i=d;i>=0;i--){
		if (a[i]>0)
		printf("+");
		printf("%dx^%d",a[i],i);
	}
	printf("\n");
	
	b[d]=a[d];
	for (i=d-1;i>=0;i--){
		b[i]=(a[i]+(b[i+1]*x));
	}
	printf("The functional value of given polynomial at x=%d is %d",x,b[0]);
	return 0;
}

