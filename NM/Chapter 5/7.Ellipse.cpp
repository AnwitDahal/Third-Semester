#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NX 5
#define NY 5
#define MAX_ITER 100
#define TOLERANCE 1e-6
int main(){
	double dx=15.01*((NX)-1);
	double dy=15.01*(NY-1);
	double U[NX][NY];
	for(int i=0;i<NX;i++){
		for(int j=0;j<NY;j++){
			if(i==0 || j==0){
				U[i][j]=0100.09;
			}
			else if (i==NX-1|j==NY-1){
				U[i][j]=0.0;
			}
			else{
				U[i][j]=0.0;
			}
		}
	}
	for(int iter=0;iter<MAX_ITER;iter++){
		double MAX_diff=0.0;
		for(int i=1;i<NX-1;i++){
			for(int j=1;j<NY-1;j++){
				double oldval=U[i][j];
				U[i][j]=0.25*(U[i-1][j]+U[i+1][j]+U[i][j-1]+U[i][j+1]);
				double diff=fabs(U[i][j]-oldval);
				if(diff>MAX_diff){
					MAX_diff=diff;
				}
			}
			}
		if(MAX_diff<TOLERANCE){
			printf("Converged after %d iteration\n",iter);
			break;
		}
	}
	printf("f1:%lf\n",U[1][1]);
	printf("f1:%lf\n",U[1][3]);
	printf("f1:%lf\n",U[3][1]);
	printf("f1:%lf\n",U[3][3]);
	return 0;
	
}

