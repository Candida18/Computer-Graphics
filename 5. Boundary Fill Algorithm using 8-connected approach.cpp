/*********************************************************************************
TITLE: Program to implement Boundary Fill Algorithm using 8-connected approach.
*********************************************************************************/

#include <graphics.h>
#include <dos.h>
#include <conio.h>
void boundaryFill8(int x, int y, int fill_color,int boundary_color)
{
    if((getpixel(x, y) != boundary_color )&& (getpixel(x, y) != fill_color))
    {
        putpixel(x, y, fill_color);
        boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
        boundaryFill8(x, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
    }
}
int main()
{
    int gd=DETECT,gm; //Detects the graphics drivers automatically
	initgraph(&gd,&gm," "); //Initialize to graphics mode
	
    rectangle(50, 50, 150, 150);
    boundaryFill8(55, 55, 12, 15);
    delay(10000);
    getch();
    closegraph();
    return 0;
}
