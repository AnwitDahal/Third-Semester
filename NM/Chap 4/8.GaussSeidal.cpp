#include<stdio.h>
#include<math.h>

#define MAX_SIZE 3

int main()
{
    int i, j, n;
    float coeffMatrix[MAX_SIZE][MAX_SIZE], constants[MAX_SIZE], errors[MAX_SIZE], previousSol[MAX_SIZE], currentSol[MAX_SIZE], sum, tolerance;

    printf("Enter the number of variables in eqn: ");
    scanf("%d", &n);

    printf("\nEnter the coefficients of the equations:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%f", &coeffMatrix[i][j]);
        }
    }

    printf("\nEnter the values of constants=:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%f", &constants[i]);
    }

    printf("\nEnter the accuracy limit: ");
    scanf("%f", &tolerance);

    for(i = 0; i < n; i++)
    {
        currentSol[i] = 0;
    }

    while(1)
    {
        for(i = 0; i < n; i++)
        {
            sum = constants[i];
            for(j = 0; j < n; j++)
            {
                if(i != j)
                {
                    sum -= coeffMatrix[i][j] * currentSol[j];
                } 
            }
            previousSol[i] = currentSol[i];
            currentSol[i] = sum / coeffMatrix[i][i];
            if(currentSol[i] == 0)
            {
                errors[i] = fabs(previousSol[i]);
            }
            else
            {
                errors[i] = fabs(currentSol[i] - previousSol[i]) / fabs(currentSol[i]);
            }
        }
        for(i = 0; i < n; i++)
        {
            if(errors[i] > tolerance)
            {
                break;
            }
        }
        if(i == n)
        {
            break;
        }
    }

    printf("\nSolution: \n");
    for(i = 0; i < n; i++)
    {
        printf("%.2f\t", currentSol[i]);
    }
    return 0;
}

