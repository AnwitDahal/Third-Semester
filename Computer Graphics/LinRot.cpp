
#include<stdio.h> 
#include <graphics.h> 
#include<math.h> 
double rad(double x){
  double rad = x * (M_PI / 180.0);
  return rad;
}
//First matrix
//10 100 0
//10 100 0
//0 0 0
 
void multiply(double a[3][3],double b[3][3],double c[3][3],int r,int co){
//	double mul[10][10];
	int k,i,j;
//	printf("multiply of the matrix=\n");    
	for(i=0;i<r;i++)    
	{    
		for(j=0;j<co;j++)    
		{    
			c[i][j]=0;    
			for(k=0;k<co;k++)    
			{    
				c[i][j]+=a[i][k]*b[k][j];    
			}    
		}    
	}  
}
//	void printmatrix(double mat[][3]){
//	
//	for(int i=0;i<3;i++)    
//	{    
//		for(int j=0;j<3;j++)    
//		{	    
//			printf("%lf\t",mat[i][j]);    
//		}    
//		printf("\n");    
//	}
//	
//}

int main(){  
	int i,j,k;
	double a[3][3];
	printf("Enter the elements in the coordinates matrix:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%lf", &a[i][j]);
        }
    }
	double angle;
    printf("Enter the angle of rotation in degrees: ");
    scanf("%lf", &angle);
	double de = rad(angle);
	double b[3][3] = {
    	{cos(de), -sin(de), 0},
    	{sin(de), cos(de), 0},
    	{0, 0, 1}
	};
	double c[3][3];

	int gd = DETECT, gm;
	initgraph(&gd, &gm, "");  

	// Draw the original line
	line(round(a[0][0]), round(a[1][0]), round(a[0][1]), round(a[1][1]));
    outtextxy(round(a[0][1] - 10), round(a[1][1] - 10), "original line");

	// Apply rotation transformation
	multiply(b,a, c, 3, 3);
//	printmatrix(c);

	// Draw the rotated line
	line(round(c[0][0]), round(c[1][0]), round(c[0][1]), round(c[1][1]));
    outtextxy(round(c[0][1] + 4), round(c[1][1] + 4), "rotated line");

	getch();
	closegraph();
	return 0;  
}

