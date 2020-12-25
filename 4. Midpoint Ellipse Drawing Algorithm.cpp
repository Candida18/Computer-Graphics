/*********************************************************************************
TITLE:  Program to implement Midpoint Ellipse Algorithm.
*********************************************************************************/
#include<graphics.h>
#include<stdio.h>
#include<math.h>

//Function to plot the ellipse
void pixel (int xc, int yc, int x,int y)
{
	putpixel(320+(xc+x),240-(yc+y),14);
	putpixel(320+(xc+x),240-(yc-y),14);
	putpixel(320+(xc-x),240-(yc-y),14);
	putpixel(320+(xc-x),240-(yc+y),14);
}

int main()
{
	int xc, yc, x, y, p, rx, ry;

	int gdriver=DETECT, gmode; //Detects the graphics drivers automatically
	initgraph(&gdriver, &gmode,""); //Initialize to graphics mode

	printf("Enter the co-ordinates of the center of the ellipse : ");
	scanf("%d %d",&xc,&yc);
	printf("Enter the value of rx and ry of the ellipse : ");
	scanf("%d %d",&rx,&ry);

    //Take start position as(0,ry)
    x=0;
	y=ry;

	p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4); //Finding decision parameter p in region 1

    //To plot the quadrants
    line(0,240,639,240);
    line(320,0,320,479);
    outtextxy(295,243,"0,0");
    setcolor(WHITE);

	pixel (xc, yc, x, y);

	while((2*x*ry*ry)<(2*y*rx*rx)) //At each x position in region 1
	{
		if(p<0) //If decision parameter is less than 0
		{
			x++; //Increment x
			p=p+(2*ry*ry*x)+(ry*ry); //Calculate the new decision parameter
		}
		else //If decision parameter is greater than 0
        {
            x++; //Increment x
            y--; //Decrement y
            p=p+(2*ry*ry*x)+(ry*ry)-(2*rx*rx*y); //Calculate the new decision parameter
        }
        pixel (xc, yc, x, y);
	}

    p=ry*ry*pow((float)x+0.5,2) + rx*rx*pow(y-1,2)-rx*rx*ry*ry; //Finding decision parameter p in region 2
    pixel (xc, yc, x, y);

    while(y>=0) //At each y position in region 2
    {
		if(p>0) //If decision parameter is greater than 0
        {
            y--; //Decrement y
            p=p-(2*y*rx*rx)+(rx*rx); //Calculate the new decision parameter
        }
        else //If decision parameter is less than 0
        {
            y--; //Decrement y
            x++; //Increment x
            p=p+(2*ry*ry*x)-(2*y*rx*rx)+(rx+rx); //Calculate the new decision parameter
        }
        pixel (xc, yc, x, y);
    }

    getch(); //Pauses the Output Console until a key is pressed
    closegraph(); //Closes the graphics mode
    return 0;
}

