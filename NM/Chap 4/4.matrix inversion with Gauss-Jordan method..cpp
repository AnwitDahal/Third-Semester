#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void matrixInversion(float matrix[][2 * MAX_SIZE], int n) {
    float ratio;
    int i, j, k;

    // Applying Gauss-Jordan elimination
    for (i = 0; i < n; i++) {
        if (matrix[i][i] == 0.00) {
            printf("Mathematical error: Division by zero!\n");
            exit(0);
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = matrix[j][i] / matrix[i][i];
                for (k = 0; k < 2 * n; k++) {
                    matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
                }
            }
        }
    }
    
    // Normalizing each row
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            matrix[i][j] = matrix[i][j] / matrix[i][i];
        }
    }
}

int main() {
    float matrix[MAX_SIZE][2 * MAX_SIZE];
    int i, j, n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);
    printf("Enter the coefficients of the matrix:\n");
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter coefficient a[%d][%d]: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }
    
    // Augmenting the matrix with identity matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j + n] = 1;
            } else {
                matrix[i][j + n] = 0;
            }
        }
    }

    // Perform matrix inversion
    matrixInversion(matrix, n);

    printf("\nInverse Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = n; j < 2 * n; j++) {
            printf("%.3f\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

