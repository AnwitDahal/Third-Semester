#include<stdio.h>
#include<math.h>

int main(){
	printf("CHolesky\n");
	int n=3;
	int transpose[3][3];
	int A[][3]={
	{1,4,7},
	{4,80,44},
	{7,44,89}
};
int L[3][3]={0};
int i,j,k;
for(i=0;i<n;i++){
	for(j=0;j<=i;j++){
		int sum=0;
		if(i==j){
			for( k=0;k<j;k++)
				sum+=L[j][k]*L[j][k];
				L[i][j]=sqrt(A[i][j]-sum);
				
				}
				else{
					for(k=0;k<j;k++)
					sum+=L[i][k]*L[j][k];
					L[i][j]=(A[i][j]-sum)/L[j][j];
		}
	}
	}
	printf("Cholensky Lower Triangular Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		printf("%d\t",L[i][j]);
		printf("\n");
	}
		printf("Cholensky UPPER Triangular Matrix: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
		printf("%d\t",L[j][i]);
		printf("\n");
	}
	//return 0;
}
