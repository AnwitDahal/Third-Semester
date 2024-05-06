#include <stdio.h>
#include <stdlib.h>
#define MAX_COLS 4
void printmatrix(double matrix[][MAX_COLS],int rows,int cols){
	int i,j;
	for ( i=0;i<rows;i++){
		for(j=0;j<cols;j++){
		printf("%f\t",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void swapRows(double matrix[][MAX_COLS],int row1,int row2,int cols){
	for (int j=0;j<cols;j++){
		double temp=matrix[row2][j];
		matrix[row1][j]=matrix[row2][j];
		matrix[row2][j]=temp;
	}
}
void gauss_elimination(double matrix[][MAX_COLS],int rows,int cols){
	for(int i=0;i<rows;i++){
		int max_row=i;
		double max_value=matrix[i][i];
		for (int k=i+1;k<rows;k++){
			double factor=matrix[k][i]/matrix[i][i];
			for(int j=0;j<cols;j++){
				matrix[k][j]-=factor*matrix[i][j];
			}
		}
	}
}
void back_substitution(double matrix[][MAX_COLS],int rows,int cols,double solution[]){
	for (int i=rows-1;i>=0;i--){
		double sum=matrix[i][cols-1];
		for(int j=i+1;j<cols-1;j++){
			sum-=matrix[i][j]*solution[j];
		}
		solution[i]=sum/matrix[i][i];
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
	gauss_elimination(matrix,rows,cols);
	printf("Row Echeloen form=\n");
	printmatrix(matrix,rows,cols);
	double solutions[100];
	back_substitution(matrix,rows,cols,solutions);
	printf("Solutions=\n");
	for(int i=0;i<rows;i++){
		printf("x%d=%f\n",i+1,solutions[i]);
	}
	return 0;
}
