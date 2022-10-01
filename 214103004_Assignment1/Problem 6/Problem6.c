#include<stdio.h>
#include<math.h>
float func(int,int);
int main()
{
int x,n;
float k;
printf("Enter a value for x: ");
scanf("%d",&x);
printf("Enter a vlaue for n:");
scanf("%d",&n);
k=func(x,n);
printf("Answer is :%f",k);
return 0;
}

float func(int x,int n)
{
float y=1;
if(n==1)
{
return (sqrt(x));
}
else
{
y=func(sqrt(x),n-1);
}
return (y);
}
