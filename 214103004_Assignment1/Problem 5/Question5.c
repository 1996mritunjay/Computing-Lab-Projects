#include<stdio.h>
#include<math.h>
int main()
{
float fact,sum=0;
int i,n,j;
printf("Enter a no:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
fact=1;
for(j=1;j<=i;j++)
{
fact=fact*j;
}
sum=sum+i/fact;
}
printf("The Sum of the series is:%5.3f",sum);  //5.3 denotes 5 character and upto 3 decimal points
return 0;
}

