#include<stdio.h>
#include<math.h>
int main()
{
float A[10][10 ],c,X[10];
int i,j,k,n,sum;
FILE *op;
FILE *ip;
ip=fopen("input_2.txt","r");
op=fopen("output_2.txt","w");
printf("Enter the size of matrix:\n");
scanf("%d",&n);
printf("Input matrix is:\n");

for(int i=1;i<=n;i++)
{
for(int j=1;j<=n+1;j++)
{
fscanf(ip,"%f",&A[i][j]);
}
}


for(int i=1;i<=n;i++)
{
for(int j=1;j<=n+1;j++)
{
printf("%f\t",A[i][j]);
}
printf("\n");
}

fprintf(ip,"Given Augmented Matrix is:\n");
for(int p=1;p<=n;p++)
{
for(int q=1;q<=(n+1);q++)
{
fprintf(ip,"%0.3f\t",A[p][q]);
}
fprintf(ip,"\n");
}                 //printing given matrix

for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
for(k=j+1;k<=n;k++)
{
if(A[j][j]==0)
{
int temp=A[j][j];
A[j][j]=A[k][j];
A[k][j]=temp;
}
}
if(i>j)
{
c=A[i][j]/A[j][j];
for(k=1;k<=(n+1);k++)
{
A[i][k]=A[i][k]-c*A[j][k];
}
}
}
}
printf("\n");
fprintf(op,"The Augmented matrix After Forward Elimination:\n");
for(int x=1;x<=n;x++)
{
for(int y=1;y<=(n+1);y++)
{
fprintf(op,"%f\t\t",A[x][y]);
}
fprintf(op,"\n");
}
fprintf(op,"\n");             //Printing Augmented Matrix

X[n]=A[n][n+1]/A[n][n];
for(i=2;i>=1;i--)
{
sum=0;
for(j=i+1;j<=n;j++)
{
sum=sum+A[i][j]*X[j];
}
X[i]=(A[i][n+1]-sum)/A[i][i];
}
fprintf(op,"\nThe solution is: \n");
for(i=1;i<=n;i++)
{
fprintf(op,"\nX%d=%f\t\t",i,X[i]);         //printing Solution using back substituion
}
printf("Output has been saved in output_3.txt file!");
printf("\n");
return 0;
}
