#include<stdio.h>
#include<math.h>
#define f(x) (x*x*x+1)
int main()
{
 float lower, upper, integ=0.0, h, k;
 int i,n;
 printf("Enter lower limit of integration: ");
 scanf("%f", &lower);
 printf("Enter upper limit of integration: ");
 scanf("%f", &upper);
 printf("Enter number of sub intervals: ");
 scanf("%d", &n);
 h=(upper-lower)/3;
  integ= f(lower)+f(upper);
 for(i=1; i<= n-1; i++)
 {
  k = lower + i*h;
  if(i%3 == 0)
  {
   integ=integ+2*f(k);
  }
  else
  {
   integ=integ+3*f(k);
  }
 }
 integ=integ*h*3/8;
 printf("\nRequired value of integration is: %.3f", integ);
 return 0;
}
