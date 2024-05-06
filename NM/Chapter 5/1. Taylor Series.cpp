#include <stdio.h>
#include <math.h>
double f(double x,double y){
	return x+y;
}
int factorial(int n){
	if (n==0||n==1){
		return 1;
	}
	return n*factorial(n-1);
}
double taylor(double x0,double y0,double h,double x){
	double y=y0;
	double term;
	for (double xi=x0;xi<x;xi+=h){
		term=h*f(xi,y)/factorial((int)xi);
		y+=term;
	}
	return y;
}
int main()
{
	double x0,y0,h,x;
	printf("Enter initial value of x(x0)=");
	scanf("%lf",&x0);
	printf("Enter initial value of y(y0)=");
	scanf("%lf",&y0);	
	printf("Enter step size(h)=");
	scanf("%lf",&h);
	printf("Enter the value of x for which we want to find y=");
	scanf("%lf",&x);
	double result=taylor(x0,y0,h,x);
	printf("Approximation solution at x=%.2f:y=%.2f\n",x,result);
	return 0;
}
