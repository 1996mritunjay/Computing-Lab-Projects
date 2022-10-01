#include<stdio.h>
#include<math.h>

float anat(float x,float y,float L,float N)
{
float h;
h=(L-x)/N;
for(x=1;x<L;x=x+h)
{
y=x*x*x+5*x*x;
printf("x=%f\ty=%f\n",x,y);
}
}

float function(float x,float y)
{
return ((x*x*x+2*y)/x);
}

float g(float x)
{
return (x*x*x+5*x*x);
}

float euler(float x,float y,float L,int N )
{
float k,h,a,b;
a=x;
b=y;
h=(L-a)/N;
while(a<L)
{
b=y+h*function(a,y);
printf("x=%f\ty=%f\n",a,y);
y=b;
a=a+h;
}
}

float RK2(float x,float y,float L,int N)
{
float h,k1,k2,a,b;
h=(L-x)/N;
a=x;
b=y;
while(a<L)
{
k1=h*function(a,b);
k2=h*function(a+h,b+k1);
b=y+(k1+k2)*0.5;
printf("x=%f\ty=%f\n",a,y);
y=b;
a=a+h;
}
}

float midpoint(float x,float y,float L,float N)
{
float h,a,b,c,y1;
h=(L-x)/N;
a=x;
b=y;
y1=y+h*function(x,y);
while(a<L)
{
y=b+2*h*function(a+h,y1);
printf("x=%f\ty=%f\n",a,b);
b=y1;
y1=y;
a=a+h;
}
}


float RK4(float x,float y,float L,int N)
{
float h,k1,k2,k3,k4,a,b;
h=(L-x)/N;
while(x<L)
{
k1=h*function(x,y);
k2=h*function(x+h/2.0,y+k1/2.0);
k3=h*function(x+h/2.0,y+k2/2.0);
k4=h*function(x+h,y+k3);
printf("%lf\t%lf\n",x,y);
b=y+1/6.0*(k1+2*k2+2*k3+k4);
y=b;
x=x+h;
}
}


int main()
{
float x0,y0,L,h;
int N;
printf("Enter the intilal value of x0 and y0:");
scanf("%f\t%f",&x0,&y0);
printf("Enter the End Point:");
scanf("%f",&L);
printf("Enter the No. of interval:");
scanf("%d",&N);
printf("Analytical solution:\n");
anat(x0,y0,L,N);
printf("Euler method\n");
euler(x0,y0,L,N);
printf("Mid-Point Method\n");
midpoint(x0,y0,L,N);
printf("RK2-Method\n");
RK2(x0,y0,L,N);
printf("RK4-Method\n");
RK4(x0,y0,L,N);
return 0;
}
