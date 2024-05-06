#include <stdio.h>
#include <math.h>
double f(double x,double y){
	return x-y;
}
double heun(double x0,double y0,double h,double x){
	double y=y0;
	double y_pred;
	for (double xi=x0;xi<x;xi+=h){
		y_pred=y+h*f(xi,y);
		y+=h/2.0*(f(xi,y)+f(xi+h,y_pred));
	}
	return y;
}
int main(){
	double x0,y0,h,x;
	printf("Enter value of x0=");
	scanf("%lf",&x0);
	printf("Enter value of  y0=");
	scanf("%lf",&y0);	
	printf("Enter value of h=");
	scanf("%lf",&h);
	printf("Enter value of x for which you want to find y=");
	scanf("%lf",&x);
	double eulerresult=heun(x0,y0,h,x);
	printf("Heun method result at x=%.2f:y=%f\n",x,eulerresult);
	return 0;
}
