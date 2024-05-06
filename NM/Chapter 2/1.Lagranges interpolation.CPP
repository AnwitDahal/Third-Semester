#include<stdio.h>
#include<math.h>
#define MAX_POINTS 10

int main()
{
    int i, j, n;
    float x_values[MAX_POINTS], y_values[MAX_POINTS], sum = 0, product, specified_x, result;
    
    printf("Enter the number of data points:\n");
    printf("\nn= ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the data points for x_values[%d] and y_values[%d]", i, i);
        printf("\nx_values[%d] = ", i);
        scanf("%f", &x_values[i]);
        printf("\ny_values[%d] = ", i);
        scanf("%f", &y_values[i]);
    }
    
    printf("\nEnter the value of x for interpolation:");
    scanf("%f", &specified_x);
    
    for (i = 0; i < n; i++)
    {
        product = 1;
        for (j = 0; j < n; j++)
        {
            if (i != j)
                product = product * (specified_x - x_values[j]) / (x_values[i] - x_values[j]);
        }
        sum = sum + product * y_values[i];
    }
    
    result = sum;
    printf("\nThe interpolated value at x = %f is %f", specified_x, result);
    
    return 0;
}

