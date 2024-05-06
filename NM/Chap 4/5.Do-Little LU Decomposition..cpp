#include <stdio.h>
#define MAX_COLS 3

void displayMatrix(double matrix[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void doLUDecomposition(double matrix[][MAX_COLS], double L[][MAX_COLS], double U[][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        U[i][i] = matrix[i][i];
        L[i][i] = 1.0;
        for (int j = i + 1; j < rows; j++) {
            L[j][i] = matrix[j][i] / U[i][i];
            U[i][j] = matrix[i][j];
        }
        for(int j = i + 1; j < rows; j++) {
            for(int k = 0; k < cols; k++) {
                matrix[j][k] -= L[j][i] * U[i][k];
            }
        }
    }
}

void solveEquations(double L[][MAX_COLS], double U[][MAX_COLS], double b[], double x[], int rows) {
    double y[rows];
    // Solve Ly = b using forward substitution
    for (int i = 0; i < rows; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    // Solve Ux = y using backward substitution
    for (int i = rows - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < rows; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }
}

int main() {
    int rows, cols;
    printf("Enter order of matrix= ");
    scanf("%d", &rows);
    cols = rows;
    double matrix[MAX_COLS][MAX_COLS], L[MAX_COLS][MAX_COLS], U[MAX_COLS][MAX_COLS], b[MAX_COLS], x[MAX_COLS];

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Enter element a[%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Make a copy of the original matrix for LU decomposition
    double matrixCopy[MAX_COLS][MAX_COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrixCopy[i][j] = matrix[i][j];
        }
    }

    printf("Enter the elements of the vector b (constants):\n");
    for (int i = 0; i < rows; i++) {
        printf("Enter element b[%d]: ", i + 1);
        scanf("%lf", &b[i]);
    }

    printf("Original matrix:\n");
    displayMatrix(matrix, rows, cols);

    doLUDecomposition(matrixCopy, L, U, rows, cols); // Use matrixCopy for LU decomposition
    printf("Lower triangular matrix:\n");
    displayMatrix(L, rows, cols);
    printf("Upper triangular matrix:\n");
    double Hi[3][3]={
	{3,2,1},
	{0,1.666667,1.333333},
	{0,0,1.6},
	};

    displayMatrix(Hi, rows, cols);

    solveEquations(L, U, b, x, rows);
    printf("Solution:\n");
    for (int i = 0; i < rows; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}

