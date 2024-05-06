#include<stdio.h>
//#include<math.h>
#define f(x) x*x*x+1
int main()
{
   float a,b,h,i;
   printf("Input lower limit 'a':");
   scanf("%f",&a);
   printf("\nInput  higher limit 'b':");
   scanf("%f",&b);
   h=(b-a)/2;
   i =h*(f(a)+f(b));
   printf("\nThe integration value of function :%f",i);
   return 0;
}
