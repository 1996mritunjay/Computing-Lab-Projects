
#include<stdio.h>
#include<math.h>
#define f(x) x-pow(29,-1)
#define df(x) 1
#define TOL pow(10,-5)
int main()
{
FILE *op;
op=fopen("output_Problem_2.txt","w");
float x0,x1,f0,f1,df0,e;
int i=0,N;
printf("Enter The initial guess for x0:");
scanf("%f",&x0);
printf("Enter max no. of iterations:");
scanf("%d",&N);
fprintf(op,"Iteration\tRoot\t\tError");
fprintf(op,"\n");
do
{
f0=f(x0);
df0=df(x0);
x1=x0-(f0/df0);
e=x1-x0;
x0=x1;
f1=f(x1);
i++;
fprintf(op,"%d\t\t%f\t%f\n",i,x1,e);
if(i>N)
{
printf("Solution will not Converge!");
exit(0);
}
}
while(fabs(f1)>TOL);
fprintf(op,"\n");
fprintf(op,"Root is:%f",x1);
printf("\n");
printf("output has been saved in output_Problem_2.txt!");
printf("\n");
return 0;


}
