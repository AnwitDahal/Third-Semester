#include<stdio.h> 
#include<graphics.h> 
#include<math.h>

void multiply(double a[3][3], double b[3][3], double c[3][3],int r, int co){
    int k, i, j;  
    for(i = 0; i < r; i++) {    
        for(j = 0; j < co; j++) {    
            c[i][j] = 0;    
            for(k = 0; k < co; k++) {    
                c[i][j] += a[i][k] * b[k][j];    
            }    
        }    
    }  
}

void rotate(double a[][3], double c[][3], double angle){
    double radian = angle * (M_PI / 180);
    double b[3][3] = {
        {cos(radian), -sin(radian), 0},
        {sin(radian), cos(radian), 0},
        {0, 0, 1}
    };
    multiply(a, b, c, 3, 3);
}

int main(){  
    double a[3][3], c[3][3];
    int i, j;  

    printf("Enter the elements in the coordinates matrix:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            scanf("%lf", &a[i][j]);
        }
    }

    double angle;
    printf("Enter the angle of rotation in degrees: ");
    scanf("%lf", &angle);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Draw the original line
    line(round(a[0][0]), round(a[1][0]), round(a[0][1]), round(a[1][1]));
    outtextxy(round(a[0][1] - 10), round(a[1][1] - 10), "original line");

    // Rotate the line
    rotate(a, c, angle);

    // Draw the rotated line
    line(round(c[0][0]), round(c[1][0]), round(c[0][1]), round(c[1][1]));
    outtextxy(round(c[0][1] + 4), round(c[1][1] + 4), "rotated line");

    getch();
    closegraph();
    return 0;  
}

