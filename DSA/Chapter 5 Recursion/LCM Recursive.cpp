#include <stdio.h>
int findGCD(int num1,int num2);
int main(){
	int num1,num2,gcd,lcm;
	printf("Input 1st number:");
	scanf("%d",&num1);
	printf("Input 2nd number:");
	scanf("%d",&num2);
	gcd=findGCD(num1,num2);
	lcm=(num1*num2)/gcd;
	printf("\nThe LCM of %d and %d is: %d\n\n",num1,num2,lcm);
	return 0;
}

int findGCD(int a,int b){
	if(b!=0)
	return findGCD(b,a%b);
	else
	return a;
}
