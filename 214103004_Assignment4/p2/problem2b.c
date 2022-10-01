#include<stdio.h>
#include<math.h>
#define TOL pow(10,-12)
//#define f0(x) 1
//#define f1(x) x
//#define f2(x) 0.5*(3*x*x-1)
#define f(x) 0.5*(5*x*x*x-3*x)
/*#define f4(x) 0.125*(35*x*x*x*x-30*x*x+3)
#define f5(x) 0.125*(63*x*x*x*x*x-70*x*x*x+15*x)
#define f6(x) 0.0625*(231*x*x*x*x*x*x*-315*x*x*x*+105*x*x-5)
#define f7(x) 0.0625*(429*x*x*x*x*x*x*x-693*x*x*x*x*x+315*x*x*x-35*x)
#define f8(x) 0.0078125*(6435*x*x*x*x*x*x*x*x-12012*x*x*x*x*x*x+6930*x*x*x*x-1260*x*x+35)*/

//#define df0(x) 0
//#define df1(x) 0
//#define df2(x) 1
#define df(x) 0.5*(15*x*x-3)
/*#define df4(x) 0.5*(20*x*x*x-3)
#define df5(x) 0.125*(140*x*x*x-60*x)
#define df6(x) (0.125*(315*x*x*x*x-210*x*x+15)
#define df7(x) (0.0625*(1386*x*x*x*x*x-945*x*x+210*x)
#define df8(x) 0.0078125*(51480*x*x*x*x*x*x*x-72072*x*x*x*x*x+27720*x*x*x-2520*x)*/

int main()
{
float x0,x1,f0,f1,df0,e;
int i=0,N;
printf("\n");
for(x0=-1;x0<=1;x0=x0+.01)
{
do
{
f0=f(x0);
df0=df(x0);
x1=x0-(f0/df0);
e=x1-x0;
x0=x1;
f1=f(x1);
i++;
if(i%10==0)
{
printf("%d\t\t%f\t%f\n",i,x1,e);
}
if(i>10000)
{
printf("Solution will not Converge!");
exit(0);
}
}
while(e>TOL&&fabs(f1)>TOL);
}
printf("\n");
printf("Root is:%17.16f",x1);
return 0;
}

