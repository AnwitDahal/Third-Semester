#include <stdio.h>
void DivDif(double x[], double y[], double dd[][10], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        dd[i][0] = y[i];
    }
    for(j = 1; j < n; j++) {
        for(i = 0; i < n-j; i++) {
            dd[i][j] = (dd[i+1][j-1] - dd[i][j-1]);
        }
    }
}
double Interpolation(double x[], double y[], double dd[][10], int n, double xi,double s) {
    double result = dd[0][0]; // Initialize result with the first divided difference
    double term = s;
    int i, j;

    for(i = 1; i < n; i++) {
    	 int f=1;
    	for(j=1;j<=i;j++){
    		f=f*j;
		}
        result = result + ((dd[0][i] * term)/f);
         term = term * (s-i);
    }

    return result;
}

int main() {
    int n, i;
    double x[10], y[10], xi, result,s,h;
    double dd[10][10];

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the data for x:\n");
    for(i = 0; i < n; i++) {

        scanf("%lf", &x[i]);
    }
    printf("Enter the data for y:\n");
     for(i = 0; i < n; i++) {
        scanf("%lf", &y[i]);
    }
		  printf("Enter the value of xi for interpolation: ");
    scanf("%lf", &xi);
    printf("Enter the difference between two x's: ");
    scanf("%lf", &h);
    s=(xi-x[0])/h;
    	DivDif(x, y, dd, n);


    result = Interpolation(x, y, dd, n, xi,s);
    
    printf("Interpolated value at xi = %.2lf is %.6lf\n", xi, result);

    return 0;
}

