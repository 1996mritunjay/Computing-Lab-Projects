#include<stdio.h>
#include<math.h>

int main()
{
int n,r,result,x,sum=0;
printf("Enter the value of x and n :");
scanf("%d%d",&x,&n);
printf("The binomial expansion is:\n");
for(r=0;r<=n;r++){
result=combination(n,r)*pow(x,r);
sum=sum+result;
printf("%d\t",result);
}
printf("\n");
printf("The sum is: %d\t\n",sum);
return 0;
}

//calculation of nCr!
int combination(int n,int r)
{
int ncr;
ncr=fact(n)/(fact(r)*fact(n-r));
return (ncr);
}

//calculation of factorial
int fact(int x)
{
int i;
int fac=1;
for(i=1;i<=x;i++)
{
fac=fac*i;
}
return (fac);
}
