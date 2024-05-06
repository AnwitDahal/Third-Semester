#include<stdio.h> 
#include <graphics.h>  
//First matrix
//10 100 0
//10 100 0
//0 0 0
 
void multiply(int a[10][10],int b[10][10],int r,int c){
	int mul[10][10],k,i,j;
//	printf("multiply of the matrix=\n");    
//	for(i=0;i<r;i++)    
//	{    
//		for(j=0;j<c;j++)    
//		{    
//			mul[i][j]=0;    
//			for(k=0;k<c;k++)    
//			{    
//				mul[i][j]+=a[i][k]*b[k][j];    
//			}    
//		}    
//	}  
//	for(i=0;i<r;i++)    
//	{    
//		for(j=0;j<c;j++)    
//		{	    
//			printf("%d\t",mul[i][j]);    
//		}    
//		printf("\n");    
//	}
//	line(mul[0][0],mul[1][0],mul[0][1],mul[1][1]);

}
int main(){  
	int mul[3][3],r,c,i,j,k;  
	int a[3][3]={
	{100,10,0
	},
	{100,10,0
	},
	{0,0,1
	}
	};  
	int b[3][3] = {
    {1, 0, 50},
    {0, 1, 0},
    {0, 0, 1}
};
		int gd=DETECT,gm;
	initgraph(&gd,&gm,"");  
//	printf("enter the number of row=");    
//	scanf("%d",&r);    
//	printf("enter the number of column=");    
//	scanf("%d",&c);    
	printf("enter the Coordinate matrix element=\n"); 
	a[3][3]={
	{100,10,0
	},
	{100,10,0
	},
	{0,0,1
	}
	}   
//	for(i=0;i<r;i++)    
//	{    
//		for(j=0;j<c;j++)    
//		{	    
//			scanf("%d",&a[i][j]);    
//		}    
//	
//	}
	line(a[0][0],a[1][0],a[0][1],a[1][1]);

//	printf("For the Tranformation matrix element=\n");
//		for(i=0;i<r;i++)    
//	{    
//		for(j=0;j<c;j++)    
//		{	    
//			scanf("%d",&b[i][j]);    
//		}    
//	}
int b[3][3] = {
    {1, 0, 50},
    {0, 1, 0},
    {0, 0, 1}
};
	
//	multiply(a,b,r,c);
printf("multiply of the matrix=\n");    
for(i=0;i<3;i++)    
{    
    for(j=0;j<3;j++)    
    {    
        mul[i][j]=0;    
        for(k=0;k<3;k++)    
        {    
            mul[i][j]+=b[i][k]*a[k][j];    
        }    
    }    
}  
for(i=0;i<r;i++)    
{    
    for(j=0;j<c;j++)    
    {	    
        printf("%d\t",mul[i][j]);    
    }    
    printf("\n");    
}
	line(mul[0][0],mul[1][0],mul[0][1],mul[1][1]);
	getch();
	closegraph();
	return 0;  
}  

