#include <stdio.h>
#include <math.h>
int main(){
	int i,j=0,k=0,m;
	printf("Enter any number in binary=");
	scanf("%d",&i);
	while(i!=0){
		m=i%10;
		i=i/10;
		j=j+m*pow(2,k);
		k++;
	}
	printf("Decimal equivalent=%d",j);
	return 0;
}

