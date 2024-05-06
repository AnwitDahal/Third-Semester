#include <stdio.h>
#include <graphics.h>
#include <math.h>
int main(){
	float x,y,dx,dy,x1,y1,x2,y2;
	int pk,finalx;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	printf("Enter (x1,y1)=");
	scanf("%f%f",&x1,&y1);
	printf("\nEnter (x2,y2)=");
	scanf("%f%f",&x2,&y2);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	pk=2*dx-dy;
	if(x2>x1){
		x=x1;
		y=y1;
		finalx=x2;
	}
	else if(x2==x1){
		x=finalx=x1;
	}
	else{
		x=x2;
		y=y2;
		finalx=x1;
	}
	putpixel(x,y,WHITE);
	while(x<=finalx){
		x=x+1;
		if(pk<=0){
			pk=pk+2*dy;
		}
		else{
			pk=pk+2*dy+2*dx;
			y=y+1;
		}
		putpixel(x,y,WHITE);
	}
	getch();
	closegraph();
	return 0;
}
