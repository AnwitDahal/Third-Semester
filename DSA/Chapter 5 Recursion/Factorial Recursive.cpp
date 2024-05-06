#include <stdio.h>
long factorial(long);
int main()
{
	long n,fact;
	printf("Input a positive number=");
	scanf("%ld",&n);
	fact=factorial(n);
	printf("%ld!=%ld",n,fact);
	return 0;
}

long factorial(long n){
	if (n==0||n==1){
		return 1;
	}
	else
	{
		return n*factorial(n-1);
	}
}
