
#include <stdio.h>
//#include <math.h>
#include  <conio.h>
#include <graphics.h>
//#include <stdlib.h>
void drawpoints(int,int,int,int);
void drawcircle(int,int,int);
int BoundaryFill(int x,int y,int colorfill,int bdcolor);
int main(){
	int gd=DETECT,gm;
	int h,k,r;
	initgraph(&gd,&gm,"");
	printf("Enter center corrdinates=");
	scanf("%d%d",&h,&k);
	printf("Enter radius=");
	scanf("%d",&r);
	drawcircle(h,k,r);
	BoundaryFill(h,k,4,15);
	getch();
	closegraph();
}
void drawpoints(int x,int y,int xc,int yc){
	putpixel(xc+x,yc+y,WHITE);
	putpixel(xc-x,yc+y,WHITE);
	putpixel(xc+x,yc-y,WHITE);
	putpixel(xc-x,yc-y,WHITE);
	putpixel(xc+y,yc+x,WHITE);
	putpixel(xc-y,yc+x,WHITE);
	putpixel(xc+y,yc-x,WHITE);
	putpixel(xc-y,yc-x,WHITE);
}
void drawcircle(int xc,int yc,int r){
	int x=0,y=r,p=1-r;
	drawpoints(x,y,xc,yc);
	while(x<y){
		x++;
		if(p<0)
		p+=2*x+1;
		else{
			y--;
			p+=2*(x-y)+1;
		}
		drawpoints(x,y,xc,yc);
		delay(100);
	}
}
int BoundaryFill(int x,int y,int colorfill,int bdcolor){
	if (getpixel(x,y)!=bdcolor&&getpixel(x,y)!=colorfill){
		putpixel(x,y,colorfill);
		BoundaryFill(x+1,y,colorfill,bdcolor);
		BoundaryFill(x,y+1,colorfill,bdcolor);
		BoundaryFill(x-1,y,colorfill,bdcolor);
		BoundaryFill(x,y-1,colorfill,bdcolor);
	}
}
