#include <stdio.h>
#include <math.h>
#include <graphics.h>

void drawpoints(int x, int y, int xc, int yc) {
    putpixel(xc + x, yc + y, WHITE);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
}

void makeCircle(int r, int xc, int yc, int color, int pattern) {
    int x = 0, y = r, p = 1 - r;
    drawpoints(x, y, xc, yc);
    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawpoints(x, y, xc, yc);
        delay(10);
    }
    delay(100);
    setfillstyle(pattern, color);
    delay(100);
    floodfill(xc, yc, WHITE);    
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    //setbkcolor(RED);

    makeCircle(230, 300, 235, 1, SOLID_FILL);  
    makeCircle(185, 300, 235, 2, LINE_FILL);   
    makeCircle(140, 300, 235, 3, SLASH_FILL);  
    makeCircle(95, 300, 235, 4, HATCH_FILL);   
    makeCircle(50, 300, 235, 7, XHATCH_FILL);  
    makeCircle(5, 300, 235, 16, INTERLEAVE_FILL); 

    getch();
    closegraph();
    return 0;
}

