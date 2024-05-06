#include <stdio.h>
#include <math.h>
#define N 3
#define MAX_ITERATION 30
#define TOLERANCE 0.00001
void Jacobi(double A[N][N],double B[N],double x[N]){
	int i,j,k;
	double sum,x_new[N];
	for (k=0;k<MAX_ITERATION;k++){
		for(i=0;i<N;i++){
		sum=0.0;
		for(j=0;j<N;j++){
			if(i!=j){
				sum+=A[i][j]*x[j];
			}
		}
		x_new[i]=((B[i]-sum)/A[i][i]);
	}
	int converged=1;
	for(i=0;i<N;i++){
		if(fabs(x[i]-x_new[i])>TOLERANCE){
			converged=0;
			break;
		}
	}
	for(i=0;i<N;i++){
		x[i]=x_new[i];
	}
	if(converged){
		printf("Solution after %d iterations=\n",i+1);
		for(i=0;i<N;i++){
			printf("x%d=%f\n",i+1,x[i]);
		}
		return;
	}
}
printf("Solution did not converge within %d iterations.\n", MAX_ITERATION);
}
int main(){
	double A[N][N],b[N],x[N];
	printf("Enter coefficient of matrix A=\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%lf",&A[i][j]);
		}
	}
	printf("Enter right hand side vector=\n");
	for(int i=0;i<N;i++){
			scanf("%lf",&b[i]);
	}
	printf("Enter the initial guess vector x=\n");
	for(int i=0;i<N;i++){
		scanf("%lf",&x[i]);
	}
	Jacobi(A,b,x);
	return 0;
}
