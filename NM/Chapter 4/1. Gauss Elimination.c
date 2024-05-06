#include <stdio.h>
//#include <stdlib.h>
void forward_elimination(float matrix[][100], int n) {
    int i,j,k;
    float factor;
    for (i=1;i<=n-1;i++) {
        if(matrix[i][i]==0.0) {
            printf("Pivot element cannot be zero\n");
            return;
        }
        for (j=i+1;j<=n;j++) {
            factor=matrix[j][i]/matrix[i][i];
            for (k=1;k<=n+1;k++) {
                matrix[j][k]-=factor*matrix[i][k];
            }
        }
    }
}

void back_substitution(float matrix[][100],int n,float solution[]) {
    int i,j;    
    solution[n]=matrix[n][n+1]/matrix[n][n];    
    for (i=n-1;i>=1;i--) {
        solution[i]=matrix[i][n+1];
        for (j=i+1;j<=n;j++) {
            solution[i]-=matrix[i][j]*solution[j];
        }
        solution[i]/=matrix[i][i];
    }
}

int main() {
    int i,j,k,n;
    printf("Enter number of unknowns:");
    scanf("%d",&n);    
    float matrix[100][100],solution[100];    
    printf("Enter the augmented matrix coefficients and constants:\n");
    for (i=1;i<=n;i++){
        for(j=1;j<=n+1;j++) {
            scanf("%f",&matrix[i][j]);
        }
    } 
    forward_elimination(matrix,n);
    back_substitution(matrix,n,solution);
    printf("\nSolution:\n");
    for(i=1;i<=n;i++){
        printf("x%d=%0.3f\n",i,solution[i]);
    } 
    return 0;
}

