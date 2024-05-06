#include <stdio.h>
//#include <stdlib.h>

void eliminateForward(float coeffMatrix[][100], int n) {
    int i, j, k;
    float factor;
    for (i = 1; i <= n - 1; i++) {
        if (coeffMatrix[i][i] == 0.0) {
            printf("Error: Pivot element cannot be zero.\n");
            return;
        }
        for (j = i + 1; j <= n; j++) {
            factor = coeffMatrix[j][i] / coeffMatrix[i][i];
            for (k = 1; k <= n + 1; k++) {
                coeffMatrix[j][k] -= factor * coeffMatrix[i][k];
            }
        }
    }
}

void substituteBack(float coeffMatrix[][100], int n, float solution[]) {
    int i, j;
    solution[n] = coeffMatrix[n][n + 1] / coeffMatrix[n][n];
    for (i = n - 1; i >= 1; i--) {
        solution[i] = coeffMatrix[i][n + 1];
        for (j = i + 1; j <= n; j++) {
            solution[i] -= coeffMatrix[i][j] * solution[j];
        }
        solution[i] /= coeffMatrix[i][i];
    }
}

int main() {
    int i, j, n;
    printf("Input the number of unknowns: ");
    scanf("%d", &n);
    float coeffMatrix[100][100], solution[100];
    printf("Enter the augmented matrix coefficients and constants:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            scanf("%f", &coeffMatrix[i][j]);
        }
    }
    eliminateForward(coeffMatrix, n);
    substituteBack(coeffMatrix, n, solution);
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x%d = %0.3f\n", i, solution[i]);
    }
    return 0;
}

