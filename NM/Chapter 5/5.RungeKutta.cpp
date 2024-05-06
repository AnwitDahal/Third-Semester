#include <stdio.h>
#include <math.h>
double f(double x,double y){
	return x*2+y;
}
void runge_kutta(double x0,double y0,double h,double x_end){
	double x=x0;
	double y=y0;
	while(x<x_end){
	double k1=h*f(x,y);
	double k2=h*f(x+h/2,y+k1/2);
	double k3=h*f(x+h/2,y+k2/2);
	double k4=h*f(x+h,y+k3);
	y+=(k1+2*k2+2*k3+k4)/6;
	x+=h;
	printf("x=%f,y=%f\n",x,y);
	}
}
int main(){
	double x0,y0,h,x_end;
	printf("Enter value of x0,y0,h and x=");
	scanf("%lf%lf%lf%lf",&x0,&y0,&h,&x_end);
//	printf("Enter value of  y0=");
//	scanf("%lf",&y0);	
//	printf("Enter value of h=");
//	scanf("%lf",&h);
//	printf("Enter final value of x for the solution=");
//	scanf("%lf",&x_end);
	runge_kutta(x0,y0,h,x_end);
	return 0;
}
