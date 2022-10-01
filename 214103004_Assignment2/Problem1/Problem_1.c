#include<stdio.h>
#include<math.h>
int main()
{
FILE *op;
FILE *ip;
ip=fopen("input_1a.txt","w");
op=fopen("output_1a.txt","w");
float A[10][10 ],c,X[10];
int i,j,k,n,sum;
printf("Enter the Size of Square Matrix:\n");
scanf("%d",&n);
printf("Enter the elements of Augmented matrix A in Row-wise manner: \n");
for(i=1;i<=n;i++)
{
for(j=1;j<=(n+1);j++)
{
printf("A[%d][%d]=",i,j);
scanf("%f",&A[i][j]);
}
}
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
printf("\n");               //forward Elimination


if(A[n][n]!=0)
fprintf(op,"Unique Solution!\n");

else if(A[n][n+1]==0)
{fprintf(op,"Multiple Solution!");
goto end;
}

else
{fprintf(op,"No Solution");
goto end;
}
                            //Checking Consistency

fprintf(op,"The Augmented matrix After Forward Elimination:\n");
for(int x=1;x<=n;x++)
{
for(int y=1;y<=(n+1);y++)
{
fprintf(op,"%0.3f\t",A[x][y]);
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
fprintf(op,"\nX%d=%f\t",i,X[i]);          //printing Solution
}
end:
printf("Output hasbeen saved in corresponding output file!\n\n");
return 0;
}

