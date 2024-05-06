#include <stdio.h>
#include <math.h>
#include <graphics.h>
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	float x1,x2,y1,y2;
	int xin,yin;
	printf("Enter x and y of initial point=");
	scanf("%f%f",&x1,&y1);
	printf("Enter x and y of end point=");
	scanf("%f%f",&x2,&y2);
	putpixel(round(x1),round(y1),WHITE);
	float m=((y2-y1)/(x2-x1));
	if (m>1){
		if(y2<y1){
			yin=-1;
		}
		else{
			yin=1;
		}
	}
	while(x1!=x2&&y1!=y2){
		x1=x1+1/m;
		y1=y1+yin;
		putpixel(round(x1),round(y1),WHITE);
	}
	if(m<=1){
		if(x2<x1)
			xin=-1;
		else
			xin=1;
	}
	while(x1!=x2&&y1!=y2){
		x1=x1+xin;
		y1=y1+y1/m;
		putpixel(round(x1),round(y1),WHITE);
	}
	getch();
	closegraph();
}
