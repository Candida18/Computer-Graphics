#include<graphics.h>
#include<stdio.h>
void pixel(int xc,int yc,int x,int y);
int main() {
int gdriver=DETECT, gmode,xc,yc,r,x,y,p;
initgraph(& gdriver, & gmode,"C:\\TURBOC3\\BGI");
printf("Enter the co-ordinates of the centre of the circle:\n");
scanf("%d %d",&xc,&yc);
printf("Enter the radius of the circle:\n");
scanf("%d",&r);
x=0;
y=r;
p=1-r;
//pixel(xc,yc,x,y);
while(x<y)
{ if (p<0)
{x++;
p=p+2*x+1;
}
else
{x++;
y--;
p=p+2*(x-y)+1;
}
pixel(xc,yc,x,y);
}
getch();
closegraph();
return 0;
}
void pixel(int xc, int yc, int x, int y)
{putpixel(xc+x,yc+y,2);
putpixel(xc+x,yc-y,2);
putpixel(xc-x,yc+y,2);
putpixel(xc-x,yc-y,2);
putpixel(xc+y,yc+x,2);
putpixel(xc+y,yc-x,2);
putpixel(xc-y,yc+x,2);
putpixel(xc-y,yc-x,2);
  }