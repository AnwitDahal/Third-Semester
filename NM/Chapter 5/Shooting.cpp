#include<stdio.h>
#include<math.h>
#define f1(x,y,z) (z)
#define f2(x,y,z) 6*(z)

int main()
{
    int i;
    float xa, ya, xb, yb, x0, y0, x, y, z, xn, h, sln, yn, zn, error, E, G[2], V[2], Gs;
    printf("Enter the boundary condition: ");
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb);
    printf("\nEnter value of x to calculate value: ");
    scanf("%f", &xn);
    printf("\nEnter the step size: ");
    scanf("%f", &h);
    printf("\nEnter the accuracy limit: ");
    scanf("%f", &E);
    x = xa;
    y = ya;
    z = (yb-ya)/(xb-xa);
    G[0] = z;
    //printf("G = %f \n", G[0]);
    while(x<xb)
    {
        yn = y+(f1(x,y,z))*h;
        zn = z+(f2(x,y,z))*h;
        x = x+h;
        y=yn;
        z=zn;
        if(x==xn)
            sln =y;
    }
    V[0]=y;
    if(y<yb)
    {
        z = 2*G[0];
        G[1]=z;
    }
    else
    {
        z = 1/2.0*G[0];
        G[1] = z;
        //printf("G = %f \n", G[1]);
    }
    while(x<xb)
        {
            yn = y+(f1(x,y,z))*h;
            zn = z+(f2(x,y,z))*h;
            x = x+h;
            y = yn;
            z = zn;
            if(x==xn)
                sln = y;
        }
    while(1)
    {
        x = xa;
        y = ya;
        z = G[1] - (V[1]-yb)/(V[1] - V[0])*(G[1]-G[0]);
        Gs = z;
        while(x<xb)
        {
            yn = y+(f1(x,y,z))*h;
            zn = z+(f2(x,y,z))*h;
            x = x+h;
            y = yn;
            z = zn;
            if(x==xn)
                sln = y;
        }
        error = fabs(y - yb)/y;
        V[0] = V[1];
        V[1] = y;
        G[0] = G[1];
        G[1] = Gs;
        if(error<E)
        {
            printf("\ny(%.3f) = %f", xn, sln);
            break;
        }
    }
    return 0;
}
