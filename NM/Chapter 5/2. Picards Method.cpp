#include <stdio.h>
#include <math.h>
double f(double x,double y){
	return x-y;
}
double integrate(double x0,double y0,double x,int num_steps){
	double h=(x-x0)/num_steps;
	double integral=0.0;
	int i;
	for (i=0;i<num_steps;i++){
		double t=x0+i*h;
		integral+=h*(f(t,y0)+f(t+h,y0))/2.0;
	}
	return integral;
}
int main()
{
	double x0,y0,x_target,x;
	int num_steps;
	printf("Enter initial value of x(x0)=");
	scanf("%lf",&x0);
	printf("Enter initial value of y(y0)=");
	scanf("%lf",&y0);	
	printf("Enter x_target=");
	scanf("%lf",&x_target);
	printf("Enter num_steps=");
	scanf("%i",&num_steps);
	double yn=y0;
	for (x=x0;x<=x_target;x+=(x_target-x0)/num_steps){
		double integral=integrate(x0,y0,x,num_steps);
		yn+=integral;
	}
	printf("Approximation solution at x=%.2f:y=%.2f\n",x_target,yn);
	return 0;
}
