#include <stdio.h>
int main(){
	int a=1,number;
	long int fact=1;
	printf("Enter a number=");
	scanf("%d",&number);
	for (a=1;a<=number;a++)
	fact=fact*a;
	printf("Factorial of %d is %ld",number,fact);
	return 0;
}
