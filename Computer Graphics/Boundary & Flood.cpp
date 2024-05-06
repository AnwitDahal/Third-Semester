#include <stdio.h>
#include <graphics.h>
#include <conio.h>
int BoundaryFill(int x,int y,int colorfill,int bdcolor){
	if (getpixel(x,y)!=bdcolor&&getpixel(x,y)!=colorfill){
		putpixel(x,y,colorfill);
		BoundaryFill(x+1,y,colorfill,bdcolor);
		BoundaryFill(x,y+1,colorfill,bdcolor);
		BoundaryFill(x-1,y,colorfill,bdcolor);
		BoundaryFill(x,y-1,colorfill,bdcolor);
	}
}
int FloodFill(int x,int y,int prev_color,int next_color){
	if(getpixel(x,y)==prev_color){
		putpixel(x,y,next_color);
		FloodFill(x+1,y,prev_color,next_color);
		FloodFill(x,y+1,prev_color,next_color);
		FloodFill(x-1,y,prev_color,next_color);
		FloodFill(x,y-1,prev_color,next_color);
	}
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	rectangle(100,100,250,300);
	BoundaryFill(150,200,4,15);
	FloodFill(150,190,4,8);
	//delay(1000);
	getch();
	closegraph();
}
