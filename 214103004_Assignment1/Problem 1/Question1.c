#include<stdio.h>
#include<math.h>
int main()
{
int m,n,i,j,p,q,k,sum=0;
int A[10][10],B[10][10],C[10][10];
printf("Enter the no. of rows and columns of A:\n");
scanf("%d%d",&m,&n);
printf("Enter the Elements in Matrix A:\n");
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
printf("A[%d][%d]=",i+1,j+1);
scanf("%d",&A[i][j]);
}
}
printf("Enter the no. of rows and columns of B:\n");
scanf("%d%d",&p,&q);
printf("Enter the Elements in Matrix A:\n");
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
printf("B[%d][%d]=",i+1,j+1);
scanf("%d",&B[i][j]);
}
}
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{
for(k=0;k<p;k++)
{
sum=sum+A[i][k]*B[k][j];
}
C[i][j] = sum;
sum = 0;}
}
printf("Product of entered matrices:-\n");
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
printf("%d\t", C[i][j]);
printf("\n");}
return 0;
}




