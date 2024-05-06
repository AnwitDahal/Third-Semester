#include <stdio.h>
#include <stdlib.h>
#define MAX_COLUMNS 4

void displayMatrix(double coefficients[][MAX_COLUMNS], int rows, int cols){
	int i, j;
	for (i = 0; i < rows; i++){
		for(j = 0; j < cols; j++){
			printf("%f\t", coefficients[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void exchangeRows(double coefficients[][MAX_COLUMNS], int row1, int row2, int cols){
	for (int j = 0; j < cols; j++){
		double temp = coefficients[row2][j];
		coefficients[row1][j] = coefficients[row2][j];
		coefficients[row2][j] = temp;
	}
}

void gaussianElimination(double coefficients[][MAX_COLUMNS], int rows, int cols){
	for(int i = 0; i < rows; i++){
		int maxRow = i;
		double maxValue = coefficients[i][i];
		for (int k = i + 1; k < rows; k++){
			double factor = coefficients[k][i] / coefficients[i][i];
			for(int j = 0; j < cols; j++){
				coefficients[k][j] -= factor * coefficients[i][j];
			}
		}
	}
}

void backwardSubstitution(double coefficients[][MAX_COLUMNS], int rows, int cols, double result[]){
	for (int i = rows - 1; i >= 0; i--){
		double sum = coefficients[i][cols - 1];
		for(int j = i + 1; j < cols - 1; j++){
			sum -= coefficients[i][j] * result[j];
		}
		result[i] = sum / coefficients[i][i];
	}
}

int main(){
	int rows, cols;
	printf("Enter the number of equations: ");
	scanf("%d", &rows);
	cols = rows + 1;
	double coefficients[100][MAX_COLUMNS];
	printf("Enter the augmented matrix:\n");
	for (int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			scanf("%lf", &coefficients[i][j]);
		}
	}
	printf("Original matrix:\n");
	displayMatrix(coefficients, rows, cols);
	gaussianElimination(coefficients, rows, cols);
	printf("Row Echelon form:\n");
	displayMatrix(coefficients, rows, cols);
	double solutions[100];
	backwardSubstitution(coefficients, rows, cols, solutions);
	printf("Solutions:\n");
	for(int i = 0; i < rows; i++){
		printf("x%d = %f\n", i+1, solutions[i]);
	}
	return 0;
}

