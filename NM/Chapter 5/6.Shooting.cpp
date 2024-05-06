#include <stdio.h>
#include <math.h>
#define N 4
double solve(double h,double y0,double yp0){
	double y=y0;
	double yp=yp0;
	for(int i=0;i<=N;i++){
		double x=1.0+i*h;
		double yp0=6*x;
		yp=yp0*h;
		y+=yp*h;
	}
	return y;
}
double shooting(double B,double k_guess){
	double k=k_guess;
	double k_min=0.0;
	double k_max=10.0;
	double y_final;
	for (int iter=0;iter<100;iter++){
		double y1=solve(0.5,1.0,k);
		double y2=solve(0.5,2.0,0.0);
		y_final=y1+(B-y2)*(y1-y2)/(y1-y2);
		printf("Iteration %d=k=%lf,y(2)=%lf\n",iter+1,k,y_final);
		if(fabs(B-y_final)<1e-6){
			break;
		}
		if(y_final<B){
			k_min=k;
		}
		else{
			k_max=k;
		}
		k=0.5*(k_min+k_max);
	}
	return y_final;
}
int main(){
	double B=9.0;
	double k_guess=3.0;
	double result=shooting(B,k_guess);
	printf("\nSolution at x=2:y(2)=%lf\n",result);
	return 0;
}
