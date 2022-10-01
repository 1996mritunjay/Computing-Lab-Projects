#include<stdio.h>
#include<math.h>

float anat(float x,float L,float N)
{
float h,y;
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
float k,h,a,b,error=0,el2;
a=x;
b=y;
h=(L-a)/N;
while(a<L)
{
b=y+h*function(a,b);
//printf("x=%f\ty=%f\n",a,y);
error=error+pow((y-g(a)),2);
y=b;
a=a+h;
}

printf("%d\t%f\n",N,sqrt(error)/N);
}

float RK2(float x,float y,float L,int N)
{
float h,k1,k2,a,b,error=0;
h=(L-x)/N;
a=x;
b=y;
while(a<L)
{
k1=h*function(a,b);
k2=h*function(a+h,b+k1);
b=y+(k1+k2)*0.5;
//printf("x=%f\ty=%f\n",a,y);
error=error+pow((y-g(a)),2);
y=b;
a=a+h;
}
printf("%d\t%f\n",N,sqrt(error)/N);
}

float midpoint(float x,float y,float L,int N)
{
float h,a,b,c,y1,error=0;
h=(L-x)/N;
a=x;
b=y;
y1=y+h*function(x,y);
while(a<L)
{
y=b+2*h*function(a+h,y1);
//printf("x=%f\ty=%f\n",a,b);
error=error+pow((y-g(a)),2);
b=y1;
y1=y;
a=a+h;
}
printf("%d\t%f\n",N,sqrt(error)/N);
}


float RK4(float x,float y,float L,int N)
{
float h,k1,k2,k3,k4,a,b,error=0;
h=(L-x)/N;
a=x;
b=y;
while(x<L)
{
k1=h*function(x,y);
k2=h*function(x+h/2.0,y+k1/2.0);
k3=h*function(x+h/2.0,y+k2/2.0);
k4=h*function(x+h,y+k3);
//printf("%lf\t%lf\n",x,y);
error=error+pow((y-g(x)),2);
b=y+1/6.0*(k1+2*k2+2*k3+k4);
y=b;
x=x+h;
}
printf("%d\t%f\n",N,sqrt(error)/N);
}


int main()
{
float x0,y0,L,h;
int N;
printf("Enter the intilal value of x0 and y0:");
scanf("%f\t%f",&x0,&y0);
printf("Enter the End Point:");
scanf("%f",&L);
//printf("Enter the No. of interval:");
//scanf("%d",&N);
//printf("Analytical solution:\n");
//anat(x0,L,N);
//printf("Euler method\n");
//printf("Mid-Point Method\n");
printf("Eulers-Method\n");
for(N=1;N<=25;N++)
{
if(N==2||N%5==0)
{
euler(x0,y0,L,N);
}
}
printf("Midpoint-Method\n");
for(N=1;N<=25;N++)
{
if(N==2||N%5==0)
{
midpoint(x0,y0,L,N);
}
}
printf("RK2-Method\n");
for(N=1;N<=25;N++)
{
if(N==2||N%5==0)
{
RK2(x0,y0,L,N);
}
}
printf("RK4-Method\n");
for(N=1;N<=25;N++)
{
if(N==2||N%5==0)
{
RK4(x0,y0,L,N);
}
}

return 0;
}
