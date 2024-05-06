#include<math.h>
#include<stdio.h>
#include<conio.h>
main(){
   int i,j,k,m,n;
   float x[20],y[20],u,a[10],c[20][20],power,r;
   printf("enter m,n:");
   scanf("%d%d",&m,&n);
   for(i=1;i<=n;i++){
      printf("enter values of x and y");
      scanf("%f%f",&x[i],&y[i]);
   }
   for(j=1;j<=m+1;j++)
   for(k=1;k<=m+1;k++){
      c[j][k]=0;
      for(i=1;i<=n;i++){
         power=pow(x[i],j+k-2);
         c[j][k]=c[j][k]+power;
      }
   }
   for(j=1;j<=m+1;j++){
      c[j][m+2]=0;
      for(i=1;i<=n;i++){
         r=pow(x[i],j-1);
         c[j][m+2]=c[j][m+2]+y[i]*r;
      }
   }
   for(i=1;i<=m+1;i++){
      for(j=1;j<=m+2;j++){
         printf("%.2f\t",c[i][j]);
      }
   }
   for(k=1;k<=m+1;k++)
      for(i=1;i<=m+1;i++){
         if(i!=k){
            u=c[i][k]/c[k][k];
            for(j=k;j<=m+2;j++){
               c[i][j]=c[i][j]-u*c[k][j];
         }
      }
   }
   for(i=1;i<=m+1;i++){
      a[i]=c[i][m+2]/c[i][i];
      printf("a[%d]=%f",i,a[i]);
   }
   getch();
}
