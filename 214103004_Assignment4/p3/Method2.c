#include<stdio.h>
#include<math.h>

float f(float a,float b,float z)
{
float x;
x=((b-a)*z+(b-a))/2;
return (8/(4+x*x));
}
int main()
{
float I,a,b;
int n;
printf("Enter the value of lower limit:");
scanf("%f",&a);
printf("Enter the upper value of limit:");
scanf("%f",&b);
printf("Choose the no. of Quadrature Points:");
scanf("%d",&n);
switch(n)
{
case 2:
I=(b-a)/2*(f(a,b,-0.57735)+f(a,b,0.57735));
break;

case 3:
I=(b-a)/2*(.55555*f(a,b,-0.77459)+0.88888*f(a,b,0.0)+0.55555*f(a,b,0.77459));
break;

case 4:
I=(b-a)/2*(0.34785*f(a,b,-0.861136)+0.652145*f(a,b,-0.339981)+0.34785*f(a,b,0.861136)+0.652145*f(a,b,0.339981));
break;

case 5:
I=(b-a)/2*(0.23692*f(a,b,-0.90617)+0.478628*f(a,b,-0.538469)+0.56888*f(a,b,0.0)+0.23692*f(a,b,-0.90617)+0.478628*f(a,b,0.538469));
break;

case 6:
I=(b-a)/2*(0.17132*f(a,b,-0.932469)+0.36076*f(a,b,-0.661209)+0.467913*f(a,b,-0.238619)+0.17132*f(a,b,0.932469)+0.36076*f(a,b,0.661209)+0.467913*f(a,b,0.238619));
break;

case 7:
I=(b-a)/2*(0.129489*f(a,b,-0.949107)+0.279705*f(a,b,-0.74153)+0.381830*f(a,b,-0.40584)+0.41759*f(a,b,0.0)+0.129489*f(a,b,0.949107)+0.279705*f(a,b,0.74153)+0.381830*f(a,b,0.40584));
break;

case 8:
I=(b-a)/2*(0.10122*f(a,b,-0.960289)+0.222381*f(a,b,-0.796666)+0.313706*f(a,b,-0.525532)+0.362683*f(a,b,-0.183434)+0.10122*f(a,b,0.960289)+0.222381*f(a,b,0.796666)+0.313706*f(a,b,0.525532)+0.362683*f(a,b,0.183434));
break;
}
printf("With %d Quadrature points, The Integration is:",n);
printf("\n");
printf("I=%f",I);
}
