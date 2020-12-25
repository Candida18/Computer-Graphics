/*******************************************************************************************
TITLE:  Program to implement Bresenham's Line Drawing Algorithm.
*******************************************************************************************/
#include<stdio.h>
#include<graphics.h>

void drawbresenhamline(int x0, int y0, int x1, int y1)
{
   	int dx, dy, p, x, y;

	//Calculating constants
    dx=abs(x1-x0);
    dy=abs(y1-y0);

   	x=x0;
   	y=y0;

    p=2*dy-dx; //Initial decision parameter


    //This is the case when slope(m) < 1
    if(dx > dy)
    {
        putpixel(320+x,240-y,14);    //this putpixel is for very first pixel of the line
        int p = (2 * dy) - dx;

        for(int i = 0; i < dx ; i++)
        {
            x = x + 1;
            if(p < 0)
                p = p + (2 * dy);
            else
            {
                y = y + 1;
                p = p + (2 * dy) - (2 * dx);
            }
            putpixel(320+x,240-y,14);
        }
    }
    else
    {
        //This is the case when slope is greater than or equal to 1  i.e: m>=1
        putpixel(320+x,240-y,14);    //this putpixel is for very first pixel of the line
        int p = (2 * dx) - dy;

        for(int i = 0; i < dy ; i++)
        {
            y = y + 1;
            if(p < 0)
                p = p + (2 * dx);
            else
            {
                x = x + 1;
                p = p + (2 * dx) - (2 *dy);
            }
            putpixel(320+x,240-y,14);    // display pixel at coordinate (x, y)
        }
    }
}

int main()
{
    int x0, y0, x1, y1;
    int gdriver=DETECT, gmode; //Detects the graphics drivers automatically

    initgraph(&gdriver, &gmode, ""); //Initialize to graphics mode

    printf("Enter the co-ordinates of the first point: "); //First co-ordinate of the line
    scanf("%d %d", &x0, &y0);
    printf("Enter the co-ordinates of the second point: "); //Second co-ordinate of the line
    scanf("%d %d", &x1, &y1);

    //To plot the quadrants
    line(0,240,639,240);
    line(320,0,320,479);
    outtextxy(295,243,"0,0");
    setcolor(WHITE);

    drawbresenhamline(x0, y0, x1, y1); //Call to Bresenham Line Drawing function

    getch(); //Pauses the Output Console until a key is pressed
    closegraph(); //Closes the graphics mode
    return 0;
}
