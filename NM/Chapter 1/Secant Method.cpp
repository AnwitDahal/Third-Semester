#include <stdio.h>
#include <math.h>
#define f(x) (x*x*x+4*x-9)
int main(){
	float x1,x2,x3,y1,y2,y3,e;
	int i=0,n;
	printf("Enter the initial root of the eqn=");
	scanf("%f%f",&x1,&x2);
	printf("Enter the no. of iteration =");
	scanf("%d",&n);
	printf("Enter the tolerance value=");
	scanf("%f",&e);
	while(i<n){
		y1=f(x1);
		y2=f(x2);
		x3=x2-((y2*(x2-x1))/(y2-y1));
		y3=f(x3);
		if(fabs(y3)<e){
			printf("The required root of the soln of given eqn is=%f\n",x3);
			return 0;
		}
		x1=x2;
		x2=x3;
		i++;
	}
	printf("Solution not found with %d iteration.\n");
	return 0;
}

