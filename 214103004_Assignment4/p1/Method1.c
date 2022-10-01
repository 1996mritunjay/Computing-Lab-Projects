#include<stdio.h>
#include<math.h>
#define f(x) 2*pow((1-x*x),0.5) //function definition

float trapezoidal(float a,float b,int n) //program for trapezoidal rule
{
float sum=0,x,integral,h;
h=(b-a)/(n*6);             //(n*6) for 6n division
for(int i=1;i<(n*6);i++)
    {
        x=a+i*h;
        sum=sum + f(x);
    }
    integral=(h/2)*(f(a)+2*sum+f(b)); //formula for trapezoidal rule
    printf("Value of Pi From Method-1 using trapezoidal rule with n=%d is: %f",n,integral);
}

float midpoint(float a,float b, int n) //program for mid-point rule
{
float x,integral,y,h;
h=(b-a)/(n*6);     //(n*6) for 6n division
for(int i=0;i<(6*n);i++)
{
x=a+(i*h);
y=x/2;
integral=integral+(h*f(y));   //formula for mid-point rule
}
printf("Value of Pi From Method-1 using midpoint rule with n=%d is: %f",n,integral);
}

float simpson1by3(float a,float b,int n)  //program for simpson-1/3 rule
{
float integral,sum1=0,sum2=0,h,x;
h=(b-a)/(6*n);            //(n*6) for 6n division
for(int i=1;i<(n*6);i++)
    {
    if(i%2==0)
    {
        x=a+i*h;
        sum1=sum1 + 2*f(x);
   }
   else
   {
        x=a+i*h;
        sum2=sum2 + 4*f(x);
    }
    }
    integral=(h/3)*(f(a)+sum1+sum2+f(b)); ////formula for simpson-1/3 rule
    printf("Value of Pi From Method-1 using simpson's 1/3rd rule with n=%d is: %f",n,integral);
}

float simpson3by8(float a,float b,int n) ////program for simpson-3/8 rule
{
int i;
float integral,sum1=0,sum2=0,h,x;
h=(b-a)/(6*n);           //(n*6) for 6n division

for(int i=1;i<(n*6);i++)
    {
    if(i%3==0)
    {
        x=a+i*h;
        sum1=sum1 + 2*f(x);
   }
   else
   {
        x=a+i*h;
        sum2=sum2 + 3*f(x);
    }
    }
    integral=(3*h/8)*(f(a)+sum1+sum2+f(b));     //formula for simpson-3/8 rule
    printf("Value of Pi From Method-1 using simpson's 3/8th rule with n=%d is: %f",n,integral);
}

int main()
{
    float a,b,integral,h,x,sum=0;
    int n,i;
    printf("Enter the lower limit");
    scanf("%f",&a);
    printf("Enter the upper limit");
    scanf("%f",&b);
    for(n=1;n<=20;n++)
    {
    trapezoidal(a,b,n); //various function calling
    printf("\n");
    midpoint(a,b,n);
    printf("\n");
    simpson1by3(a,b,n);
    printf("\n");
    simpson3by8(a,b,n);
    printf("\n");
    printf("\n");
    }
    return 0;
}
