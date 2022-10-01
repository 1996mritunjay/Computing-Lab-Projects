#include<stdio.h>
#include<math.h>

float P0(float  x)  //function to return value of 0th legendre polynomial
{
return 1;
}

float P1(float x)   //function to return value of 1st legendre polynomial
{
return x;
}
float P(float x, int n)   //function to return value of nth legendre polynomail of given value of x between [-1,1]
{
if(n==0)
{
return P0(x);
}
else if(n==1)
{
return P1(x);
}
else
{
return (float)((2*n-1)*x*P(x,n-1)-(n-1)*P(x,n-2))/n;  //legendre polynomial equation
}
}
int main()
{
int n;
float x;
printf("Enter the value of x between [-1,1]:");  //user defind inputs
scanf("%f",&x);
printf("Enter No. of qudrature points,(n):");
scanf("%d",&n);
printf("\nFor the value of x=%3.4f\n",x);
printf("Values of legendre polynomials for %d quadrature points are\n",n);
for(int i=0;i<=n;i++)
{
printf("P%d=%f\n",i,P(x,i));    //function calling and printing the desired result
}
return 0;
}
