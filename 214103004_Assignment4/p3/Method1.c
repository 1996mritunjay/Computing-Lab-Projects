#include<stdio.h>
#include<math.h>

float f(float x)
{
return (2*pow((1-x*x),0.5));
}
int main()
{
float I;
int n;
printf("Choose the no. of Quadrature Points:");
scanf("%d",&n);
switch(n)
{
case 2:
I=(f(-0.57735)+f(0.57735));
break;

case 3:
I=(.55555*f(-0.77459)+0.88888*f(0.0)+0.55555*f(0.77459));
break;

case 4:
I=(0.34785*f(-0.861136)+0.652145*f(-0.339981)+0.34785*f(0.861136)+0.652145*f(0.339981));
break;

case 5:
I=(0.23692*f(-0.90617)+0.478628*f(-0.538469)+0.56888*f(0.0)+0.23692*f(-0.90617)+0.478628*f(0.538469));
break;

case 6:
I=(0.17132*f(-0.932469)+0.36076*f(-0.661209)+0.467913*f(-0.238619)+0.17132*f(0.932469)+0.36076*f(0.661209)+0.467913*f(0.238619));
break;

case 7:
I=(0.129489*f(-0.949107)+0.279705*f(-0.74153)+0.381830*f(-0.40584)+0.41759*f(0.0)+0.129489*f(0.949107)+0.279705*f(0.74153)+0.381830*f(0.40584));
break;

case 8:
I=(0.10122*f(-0.960289)+0.222381*f(-0.796666)+0.313706*f(-0.525532)+0.362683*f(-0.183434)+0.10122*f(0.960289)+0.222381*f(0.796666)+0.313706*f(0.525532)+0.362683*f(0.183434));
break;
}
printf("With %d Quadrature points, The answer is:",n);
printf("\n");
printf("I=%f",I);
}