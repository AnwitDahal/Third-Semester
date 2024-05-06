#include <stdio.h>
#include <math.h>
#include <graphics.h>
int BoundaryFill(int x,int y,int colorfill,int bdcolor);
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	int radius,xc,yc;
	printf("Enter radius=");
	scanf("%d",&radius);
	printf("Enter the x and y coordinates of cicle=");
	scanf("%d%d",&xc,&yc);
	for(int theta=0;theta<360;theta++){
		int x=xc+radius*cos(theta*3.14159/180);
		int y=yc+radius*sin(theta*3.14159/180);
		putpixel(x,y,WHITE);
		delay(10);
	}
	//BoundaryFill(xc,yc,4,15);
	getch();
	closegraph();
	return 0;
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
