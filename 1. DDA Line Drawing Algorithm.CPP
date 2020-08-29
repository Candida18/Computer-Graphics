
#include <stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>


int main(){
float x,y,x1,y1,x2,y2,dx,dy,step;
int i,gdriver=DETECT,gmode;

initgraph(&gdriver,&gmode,"");

printf("Enter the value of x1,y1:\n");
scanf("%f %f",&x1,&y1);
printf("Enter the value of x2,y2:\n");
scanf("%f %f",&x2,&y2);


dx=x2-x1;
dy=y2-y1;

if(dx>=dy)
step=dx;
else
step=dy;

dx=dx/step;
dy=dy/step;

x=x1;
y=y1;
i=1;

while(i<=step)
{
putpixel(x,y,2);
x=x+dx;
y=y+dy;
i=i+1;
}

getch();
closegraph();
return 0;
}
