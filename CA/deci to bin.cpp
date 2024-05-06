#include <stdio.h>
int main(){
	int i,h,s=0,a=1;
	printf("Enter the number in decimal=");
	scanf("%d",&i);
	while(i!=0){
		h=i%2;
		s=s+a*h;
		i=i/2;
		a=a*10;
	}
	printf("Binary equilvalent=%d",s);
	return 0;
}

