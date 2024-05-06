#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) (x*x*x+4*x-9)
int main(){
	float x1,x2,e,y1,y2,y3,mid;
	printf("Enter the inital root of the eqn:");
	scanf("%f%f",&x1,&x2);
	printf("Enter the tolerance value=");
	scanf("%f",&e);
	y1=f(x1);
	y2=f(x2);
	if(y1*y2>0){
		printf("Roots are incomparible\n");
		exit(0);
	}
	while(fabs(x2-x1)>e){
		mid=(x1+x2)/2;
		y3=f(mid);
		if(y1*y3>0){
			x1=mid;
			y1=y3;
		}
		else{
			x2=mid;
			y2=y3;
		}
	}
	printf("The required roots of the solution of given eqn is %f\n",mid);
	return 0;
}
