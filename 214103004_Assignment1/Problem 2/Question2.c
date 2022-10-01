#include<stdio.h>
#include<math.h>
int main()
{
float x1,x2,x3,y1,y2,y3,m1,m2;
printf("Enter the Co-ordinates of(x1,y1):");
scanf("%f%f",&x1,&y1);

printf("Enter the Co-ordinates of(x2,y2):");
scanf("%f%f",&x2,&y2);

printf("Enter the Co-ordinates of(x3,y3):");
scanf("%f%f",&x3,&y3);

m1=(y2-y1)/(x2-x1);
m2=(y3-y1)/(x3-x1);

if(m1==m2){
printf("All Three points are collinear!");

}
else
{
printf("Given points can draw a valid triangle!");
}
return 0;


}
