#include<stdio.h>
#include<conio.h>
#include<math.h>
#define f(x) (1-exp(-(x)/2.0))
int main()
{
	float a,b,is1,h;
	int n;
	printf("Enter the limits of integration(a and b)=");
	scanf("%f%f",&a,&b);
	printf("\nEnter positive number n i.e. the number of segments to be made(Even Numbers)=");
	scanf("%d",&n);
	h=(b-a)/n;
	float x,y;
	for(int i=1;i<=(n/2);i++)
	x+=f(a+(2*i-1)*h);
	x*=4;
	for(int i=1;i<=((n/2)-1);i++)
	y+=f(a+(2*i)*h);
	y*=2;
	is1=f(a)+f(b)+x+y;
	is1*=(h/3);
	printf("The value of integration obtained is=%f",is1);
	return 0;
}
