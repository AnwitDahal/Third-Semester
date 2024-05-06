#include <stdio.h>
#include <math.h>
#define f(x) (exp(x))

float CompTrapezodial(float initx,float finalx,int n){
    float seg_wid,sum=0.0,int_val=0.0;
    seg_wid= (finalx - initx) / n;
    sum = (seg_wid / 2) * (f(initx) + f(finalx));

     for (int i = 1; i <= n - 1; i++) {
        sum += f(initx + i * seg_wid);
    }

    int_val = sum * seg_wid;
    return int_val;
    
}

int main() {
    int i, num_segments;
    float initial_x, final_x,integration_value;

    printf("Input the initial value of x: ");
    scanf("%f", &initial_x);
    printf("Input the final value of x: ");
    scanf("%f", &final_x);
    printf("Enter the number of segments: ");
    scanf("%d", &num_segments);
    integration_value=CompTrapezodial(initial_x,final_x,num_segments);
    

    // segment_width = (final_x - initial_x) / num_segments;
    // sum = (segment_width / 2) * (function(initial_x) + function(final_x));

    // for (i = 1; i <= num_segments - 1; i++) {
    //     sum += function(initial_x + i * segment_width);
    // }

    // integration_value = sum * segment_width;

    printf("\nIntegration value of function = %.2f\n", integration_value);

    return 0;
}

