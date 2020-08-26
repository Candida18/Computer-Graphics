#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void pixel(int xc, int yc, int x, int y)
{
	putpixel(xc+x,yc+y,YELLOW);
	putpixel(xc+x,yc-y,YELLOW);
	putpixel(xc-x,yc-y,YELLOW);
	putpixel(xc-x,yc+y,YELLOW);
}
int main()
{
int gdriver=DETECT,gmode,xc,yc,x,y,p,rx,ry;

initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
printf("Enter the co-ordinates of the centre:\n");
scanf("%d %d",&xc,&yc);
printf("Enter the value of rx and ry of the ellipse:\n");
scanf("%d %d",&rx,&ry);
x=0;
y=ry;
p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
pixel(xc,yc,x,y);

while((2*x*ry*ry)<(2*y*rx*rx))
{
if(p<0)
{
x=x+1;
p=p+(2*ry*ry*x)+(ry*ry);
}
else
{
x=x+1;
y=y-1;
p=p+(2*ry*ry*x+ry*ry)-(2*rx*rx*y);
}
	pixel(xc,yc,x,y);
}
p=ry*ry*pow((float)x+0.5,2)+rx*rx*pow(y-1,2)-(rx*rx*ry*ry);
pixel(xc,yc,x,y);
while(y>=0)
{
if(p>0)
{
	y=y-1;
	p=p-(2*rx*rx*y)+(rx*rx);
}
else
{
x=x+1;
y=y-1;
p=p+(2*ry*ry*x)-(2*rx*rx*y)+(rx*rx);
}
pixel(xc,yc,x,y);
}
getch();
closegraph();
return 0;
}




