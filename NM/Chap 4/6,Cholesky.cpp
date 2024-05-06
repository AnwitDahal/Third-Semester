#include<stdio.h>
#include<math.h>

int main() {
    int n;
    float Mat[10][10], L[10][10], U[10][10], B[10], sum = 0, Z[10], X[10];
    
    // Input the order of the matrix
    printf("Input the order of the matrix (square): ");
    scanf("%d", &n);
    
    // Input the elements of the matrix
    printf("Input the elements of the matrix\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Mat[%d][%d] = ", i+1, j+1);
            scanf("%f", &Mat[i][j]);
        }
    }
    
    // Input the constants
    printf("Input the constants\n");
    for(int i = 0; i < n; i++) {
        printf("B[%d] = ", i+1);
        scanf("%f", &B[i]);
    }
    
    // Calculate the elements of the Upper Matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            float temp = 0;
            if(i == j) {
                for(int k = 0; k < j; k++) {
                    temp += (U[k][i] * U[k][i]);
                }
                U[i][i] = sqrt(Mat[i][i] - temp);
            } else if(j > i) {
                for(int k = 0; k < i; k++) {
                    temp += (U[k][i] * U[k][j]);
                }
                U[i][j] = (1 / U[i][i]) * (Mat[i][j] - temp);
            } else {
                U[i][j] = 0;
            }
        }
    }

    //Finding Transpose i.e Lower Matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            L[i][j] = U[j][i];
        }
    }

    // Computing Z using forward substitution
    Z[0] = B[0] / L[0][0];
    for(int i = 1; i < n; i++) {
        sum = 0;
        for(int j = 0; j < i; j++) {
            sum += (L[i][j] * Z[j]);
        }
        Z[i] = (B[i] - sum) / L[i][i];
    }

    // Computing solution matrix
    X[n - 1] = Z[n - 1] / U[n - 1][n - 1];
    for(int i = n - 2; i >= 0; i--) {
        sum = 0;
        for(int j = i + 1; j < n; j++) {
            sum += (U[i][j] * X[j]);
        }
        X[i] = (Z[i] - sum) / U[i][i];
    }

    // Output Lower Triangular Matrix
    printf("\nLower Triangular Matrix\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", L[i][j]);
        }
        printf("\n");
    }

    // Output Upper Triangular Matrix
    printf("\nUpper Triangular Matrix\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%.2f\t", U[i][j]);
        }
        printf("\n");
    }

    // Output solution
    printf("\nSolution:\n");
    for(int i = 0; i < n; i++) {
        printf("x%d = %.3f\n", i + 1, X[i]);
    }

    return 0;
}

