#include <stdio.h>
#include <math.h>
#define MAX_COLS 3

void printmatrix(double matrix[][MAX_COLS],int rows,int cols) {
    for (int i = 0; i < rows; i++){
        for(int j=0;j<cols;j++) {
            printf("%f\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose(double matrix[][MAX_COLS],int rows,int cols){
	double transpose[MAX_COLS][MAX_COLS];
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			transpose[i][j]=matrix[j][i];
		}
		printf("\n");
	}
	printf("Lower Triangular Matrix=\n");
    printmatrix(transpose, rows, cols);
}

int main(){
	double matrix[3][3]={{4,10,8},{10,26,26},{8,26,61}};
    printf("Original Matrix=\n");
	int rows=3,cols=3;
    printmatrix(matrix,rows,cols);
    double U[3][3]={0}; 
    for (int i=0;i<rows;i++) {
        for (int j=0;j<=i;j++) {
            double sum = 0.0;
            if (j==i) {
                for (int k = 0; k < j; k++) {
                    sum+=pow(U[j][k],2);
                }
                U[j][j]=sqrt(matrix[j][j]-sum);
            } else {
                for (int k=0;k<j;k++) {
                    sum+=(U[i][k]*U[j][k]);
                }
                U[i][j]=(matrix[i][j]-sum)/U[j][j];
            }
        }
    }
    printf("\n");
    printf("Upper Triangular Matrix=\n");
    printmatrix(U, rows, cols);
    transpose(U,rows,cols);
    return 0;
}

