#include <stdio.h>
#define MAX_COLS 4
void printmatrix(double matrix[][MAX_COLS],int rows,int cols){
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		printf("%f\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void gauss_jordan(double matrix[][MAX_COLS],int rows,int cols){
	for (int i=0;i<rows;i++){
		double pivot=matrix[i][i];
		for (int j=0;j<cols;j++){
			matrix[i][j]/=pivot;
		}
		for(int k=0;k<rows;k++){
			if(k!=i){
				double factor=matrix[k][i];
				for (int j=0;j<cols;j++){
					matrix[k][j]-=factor*matrix[i][j];
				}
			}
		}
	}
}
int main(){
	int rows,cols;
	printf("Enter the no. of eqn=");
	scanf("%d",&rows);
	cols=rows+1;
	double matrix[100][MAX_COLS];
	printf("Enter the augumented matrix=\n");
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			scanf("%lf",&matrix[i][j]);
		}
	}
	printf("Original matrix:\n");
	printmatrix(matrix,rows,cols);
	gauss_jordan(matrix,rows,cols);
	for(int i=0;i<rows;i++){
		printf("x%d=%f\n",i+1,matrix[i][cols-1]);
	}
	return 0;
}
