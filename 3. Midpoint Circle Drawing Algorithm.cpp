/*********************************************************************************
TITLE:  Program to implement Midpoint Circle Drawing Algorithm.
*********************************************************************************/
#include<graphics.h>
#include<stdio.h>

//Plotting the circle
void pixel(int xc, int yc, int x, int y)
{
    putpixel(xc+x+320,240-(yc+y),14);
 	putpixel(xc+x+320,240-(yc-y),14);
 	putpixel(xc-x+320,240-(yc+y),14);
	putpixel(xc-x+320,240-(yc-y),14);
	putpixel(xc+y+320,240-(yc+x),14);
	putpixel(xc+y+320,240-(yc-x),14);
	putpixel(xc-y+320,240-(yc+x),14);
	putpixel(xc-y+320,240-(yc-x),14);

}

int main()
{

	int gdriver=DETECT, gmode; //Detects the graphics drivers automatically
	initgraph(&gdriver,&gmode," "); //Initialize to graphics mode
	int xc, yc,r,x,y,p;

	printf("Enter the co-ordinates of the center of the circle :");
	scanf("%d %d",&xc,&yc);
 	printf("Enter the radius of the circle :");
	scanf("%d",&r);

	//Take start position as(0,r)
	x=0;
	y=r;

	p=1-r; //Finding decision parameter p

	//To plot the quadrants
    line(0,240,639,240);
    line(320,0,320,479);
    outtextxy(295,243,"0,0");
    setcolor(WHITE);

    pixel(xc,yc,x,y);

    while (x<y) //Repeat the following steps until x>=y
    {
		if(p<0) //If the decision parameter is less than 0
		{
			x++; //Increment x
			p=p+2*x+1; //Calculate the new decision parameter
			pixel(xc,yc,x,y); // Call to the function to plot the circle
		}
		else //If the decision parameter is greater than 0
		{
			x++; //Increment x
 			y--; //Decrement y
 			p=p+2*(x-y)+1; //Calculate the new decision parameter
			pixel(xc,yc,x,y); // Call to the function to plot the circle
		}

    }

    getch(); //Pauses the Output Console until a key is pressed
    closegraph(); //Closes the graphics mode
    return 0;
}

