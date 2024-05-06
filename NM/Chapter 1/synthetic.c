#include <stdio.h>
int main(){
	int d,i,x;
	printf("Enter the highest degree of the eqn=");
	scanf("%d",&d);
	printf("Enter the magnitude of divison polynomial=");
	scanf("%d",&x);
	int a[d],b[d];
	for (i=0;i<=d;i++){
		printf("Enter the coefficient of x^%d=",i);
		scanf("%d",&a[i]);
	}
	printf("Given polynomial eqn is=");
	for (i=d;i>=0;i--){	
		if(a[i]>0)
		printf("+");
		printf("%dx^%d",a[i],i);
	}
	b[d]=0;
	for(i=d;i>0;i--){
		b[i-1]=a[i]+x*b[i];
	}
	printf("\n");
	printf("The quotient of polynomial is:");
	for (i=d-1;i>=0;i--){
		if(b[i]>0)
		printf("+");
		printf("%dx^%d",b[i],i);
	}
	return 0;
}
