#include<graphics.h>
#include<dos.h>
#include<conio.h>
void floodFill(int x,int y,int old,int newcol)
{
                if(getpixel(x,y)==old)
                {
		putpixel(x,y,newcol);
		floodFill(x-1,y,old,newcol);
		floodFill(x+1,y,old,newcol);
		floodFill(x,y-1,old,newcol);
		floodFill(x,y+1,old,newcol);
		floodFill(x+1,y+1,old,newcol);
		floodFill(x-1,y+1,old,newcol);
		floodFill(x-1,y-1,old,newcol);
		floodFill(x+1,y-1,old,newcol);
                }
}

int main()
{
                int gd=DETECT,gm;
                initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
		rectangle(50,50,150,150);
		floodFill(70,70,0,1);
		delay(10000);
                getch();
                closegraph();
}
