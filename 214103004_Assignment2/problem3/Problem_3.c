#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
FILE *ip;
FILE *op;
ip=fopen("input_3.txt","r");
op=fopen("output_3.txt","w");
int i,j,n;
float A[30][30],temp,c,X[10];
for(i=1;i<=4;i++)
{
for(j=1;j<=5;j++)
{
fscanf(ip,"%f",&A[i][j]);    //Program to take input from input_3.txt file
}
}

printf("Input matrix is\n");
for(int x=1;x<=4;x++)
{
for(int y=1;y<=5;y++)
{
printf("%.3f\t",A[x][y]);
}
printf("\n");
}

//partial Pivoting
for(i=1;i<4;i++)
{
for(int k=i+1;k<4;k++)
{
if(fabs(A[i][i])<fabs(A[k][i]))
{
for(j=1;j<5;j++)
{
temp=A[i][j];
A[i][j]=A[k][j];
A[k][j]=temp;
}
}
}
//gauss elimination
for(j=1;j<=4;j++)
{
for(i=1;i<=4;i++)
{
if(i>j)
{
c=A[i][j]/A[j][j];
for(int k=1;k<=5;k++)
{
A[i][k]=A[i][k]-c*A[j][k];
}
}
}
}
printf("\n");
}
fprintf(op,"Augmented Matrix After Forward Substitution:\n");
for(int p=1;p<=4;p++)
{
for(int q=1;q<=5;q++)
{
fprintf(op,"%.3f\t\t",A[p][q]);
}
fprintf(op,"\n");
}

//Back Substitution
X[4]=A[4][5]/A[4][4];
for(i=2;i>=1;i--)
{
int sum=0;
for(j=i+1;j<=4;j++)
{
sum=sum+A[i][j]*X[j];
}
X[i]=(A[i][5]-sum)/A[i][i];
}
fprintf(op,"\nThe solution is: \n");
for(i=1;i<=4;i++)
{
fprintf(op,"\nX%d=%f\t",i,X[i]);          //printing Solution
}
printf("Output has been saved in output_3.txt file!");
printf("\n");
}
