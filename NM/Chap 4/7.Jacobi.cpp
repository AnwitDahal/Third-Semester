#include <stdio.h>
#include <math.h>

#define MATRIX_SIZE 3
#define MAX_ITER 30
#define TOL 0.00001

void gaussSeidelSolver(double A[MATRIX_SIZE][MATRIX_SIZE], double B[MATRIX_SIZE], double X[MATRIX_SIZE]) {
    int i, j, k;
    double sum, newX[MATRIX_SIZE];

    for (k = 0; k < MAX_ITER; k++) {
        for (i = 0; i < MATRIX_SIZE; i++) {
            sum = 0.0;
            for (j = 0; j < MATRIX_SIZE; j++) {
                if (i != j) {
                    sum += A[i][j] * X[j];
                }
            }
            newX[i] = ((B[i] - sum) / A[i][i]);
        }

        int converged = 1;
        for (i = 0; i < MATRIX_SIZE; i++) {
            if (fabs(X[i] - newX[i]) > TOL) {
                converged = 0;
                break;
            }
        }

        for (i = 0; i < MATRIX_SIZE; i++) {
            X[i] = newX[i];
        }

        if (converged) {
            printf("Solution after %d iterations:\n", k + 1);
            for (i = 0; i < MATRIX_SIZE; i++) {
                printf("Variable X%d = %f\n", i + 1, X[i]);
            }
            return;
        }
    }
    printf("Solution did not converge within %d iterations.\n", MAX_ITER);
}

int main() {
    double A[MATRIX_SIZE][MATRIX_SIZE], B[MATRIX_SIZE], X[MATRIX_SIZE];

    printf("Enter the coefficients of the matrix A:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Enter the right-hand side vector B:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        scanf("%lf", &B[i]);
    }

    printf("Enter the initial guess vector X:\n");
    for (int i = 0; i < MATRIX_SIZE; i++) {
        scanf("%lf", &X[i]);
    }

    gaussSeidelSolver(A, B, X);

    return 0;
}


