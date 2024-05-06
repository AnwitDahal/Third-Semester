#include <stdio.h>
#include <graphics.h>
int main(){
	int radius=100;
	int gd=DETECT,gm;
	int x,y,x1,y1;
	initgraph(&gd,&gm,"");
	for ( x=200;x<300;x++){
		y=-x+4;
		putpixel(x,y,WHITE);
	}
	return 0;
}
