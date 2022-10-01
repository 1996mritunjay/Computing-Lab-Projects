#include<stdio.h>
#include<math.h>

float f(float x,float y,float z)
{
return (y*(z+1));
}

float g(float x,float y,float z)
{
return ((-2*exp(x))/y);
}

float y_anat(float x)
{
return (x*x*exp(x));
}

float z_anat(float x)
{
return (2/x);
}

float RK4(float x,float y,float z,float L,int N)
{
FILE *op;
op=fopen("Output2b.txt","w");
float h,k1,k2,k3,k4,a,b,c;
float l1,l2,l3,l4;
float y_an,z_an;
float error1=0,error2=0,yl2,zl2;
h=(L-x)/N;
a=x;
b=y;
c=z;
fprintf(op,"N\tyl2\t\tzl2\n");
//printf("x\t\ty_analytical\ty\t\tz_analytical\tz\n");
fprintf(op,"________________________________________________________________________________\n");
for(N=1;N<=25;N=N+1)
{
if(N==2||N%5==0)
{
while(a<=L)
{
k1=h*f(a,y,z);
l1=h*g(a,y,z);
//printf("k1=%f\nl1=%f\n",k1,l1);

k2=h*f(a+h/2,y+k1/2,z+l1/2);
l2=h*g(a+h/2,y+k1/2,z+l1/2);
//printf("k2=%f\nl2=%f\n",k2,l2);

k3=h*f(a+h/2,y+k2/2,z+l2/2);
l3=h*g(a+h/2,y+k2/2,z+l2/2);
//printf("k3=%f\nl3=%f\n",k3,l3);

k4=h*f(a+h,y+k3,z+l3);
l4=h*g(a+h,y+k3,z+l3);
//printf("k4=%f\nl4=%f\n",k4,l4);

y_an=y_anat(a);
z_an=z_anat(a);

b=y+(k1+(2*k2)+(2*k3)+k4)*0.1666;
c=z+(l1+(2*l2)+(2*l3)+l4)*0.1666;

error1=error1+pow((y-y_anat(a)),2);
error2=error2+pow((z-z_anat(a)),2);

//printf("%f\t%f\t%f\t%f\t%f\n",a,y_an,y,z_an,z);


y=b;
z=c;
a=a+h;
}
fprintf(op,"%d\t%f\t%f\n",N,sqrt(error1)/N,sqrt(error2)/N);
}
}
}

int main()
{
float x,y,z,L;
int N;
printf("Enter the initial value of x,y and z: ");
scanf("%f%f%f",&x,&y,&z);
printf("Enter the End point value:");
scanf("%f",&L);
//printf("Enter the No. of Points:");
//scanf("%d",&N);
RK4(x,y,z,L,N);
}
