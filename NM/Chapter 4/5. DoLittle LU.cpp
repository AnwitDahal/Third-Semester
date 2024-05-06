#include <stdio.h>
#define MAX_COLS 3
void printmatrix(double matrix[][MAX_COLS],int rows,int cols){
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		printf("%f\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void dolittle_LU(double matrix [][MAX_COLS],double L[][MAX_COLS],double U[][MAX_COLS],int rows,int cols){
	for (int i=0;i<rows;i++){
		U[i][i]=matrix[i][i];
		L[i][i]=1.0;
	for (int j=i+1;j<rows;j++){
		L[j][i]=matrix[j][i]/U[i][i];
		U[i][j]=matrix[i][j];
	}
	for(int j=i+1;j<rows;j++){
		for(int k=0;k<cols;k++){
			matrix[j][k]-=L[j][i]*U[i][k];
		}
	}
}
}

int main(){
	int rows=3;
	int cols=3;
	double matrix[3][3]={{3,2,1},{2,3,2},{1,2,3}};
	printf("Original matrix:\n");
	printmatrix(matrix,rows,cols);
	double L[3][3],U[3][3];
	dolittle_LU(matrix,L,U,rows,cols);
	printf("Lower triangular matrix=\n");
	printmatrix(L,rows,cols);
	printf("Upper triangular matrix=\n");
	printmatrix(U,rows,cols);
	return 0;
}
