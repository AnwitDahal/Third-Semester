#include <stdio.h>

int main() {
    int n;
    printf("How many data points=");
    scanf("%d", &n);
    
    float xData[n], yData[n],val,divided_diff[n][n],term=1,result;

    // Input data points and corresponding values
    printf("Enter the data points and corresponding values=\n");
    for (int i = 0; i < n; i++) {
        scanf("%f%f", &xData[i], &yData[i]);
    }
    

    printf("Enter the point at which value is needed=");
    scanf("%f", &val);

    // Initialize arrays for divided differences
    for (int i = 0; i < n; i++) {
        divided_diff[i][0] = yData[i];
    }

    // Compute divided differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            divided_diff[i][j] = (divided_diff[i + 1][j - 1] - divided_diff[i][j - 1]) / (xData[i + j] - xData[i]);
        }
    }

    // Compute interpolation
    result = divided_diff[0][0];

    for (int j = 1; j < n; j++) {
        term *= (val - xData[j - 1]);
        result += term * divided_diff[0][j];
    }

    printf("Interpolated value at x=%.3f is %.3f\n", val, result);
    
    return 0;
}

