/*********************************************************************************
TITLE: Program to implement Flood Fill Algorithm using 8-connected approach.
*********************************************************************************/

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
        int gd=DETECT,gm; //Detects the graphics drivers automatically
		initgraph(&gd,&gm," "); //Initialize to graphics mode

		rectangle(50,50,150,150);
		floodFill(70,70,0,1);
		delay(10000);

        getch();
        closegraph();
        return 0;
}
