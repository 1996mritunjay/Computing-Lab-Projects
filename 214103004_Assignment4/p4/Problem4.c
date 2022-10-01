#include<stdio.h>
#include<math.h>
#define Actual 7990
float legendre(float x)
{
    return (5*x*x*x*x+3*x*x);

}

float f(float a,float b,float z)
{
    float x=(b-a)/2*z+(b+a)/2;
    return (5*x*x*x*x+3*x*x);

}

int main()
{
    float a,b,I,Error;
    printf("Enter lower limit:");
    scanf("%f",&a);
    printf("Enter upper limit:");
    scanf("%f",&b);
    I=(b-a)/2*(0.34785*f(a,b,-0.86114)+0.65215*f(a,b,-0.33998)+0.65215*f(a,b,0.33998)+0.34785*f(a,b,0.86114));
    printf("I=%.12f\n",I);
     Error=fabs((Actual-I)/Actual)*100;
     printf("The percentage error is:%f",Error);
return 0;
}
