/********************************************************************************
TITLE : PROGRAM TO IMPLEMENT DDA LINE ALGORITHM
********************************************************************************/

#include <stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

int main()
{
    float x,y,x1,y1,x2,y2,dx,dy,step;
    int i = 1;
    int gdriver=DETECT,gmode; //Detects the graphics drivers automatically

    initgraph(&gdriver,&gmode,""); //Initialize to graphics mode

    printf("Enter the value of x1,y1:\n"); //First co-ordinate of the line
    scanf("%f %f",&x1,&y1);
    printf("Enter the value of x2,y2:\n"); //Second co-ordinate of the line
    scanf("%f %f",&x2,&y2);


    dx=x2-x1;
    dy=y2-y1;

    if(dx>=dy) //Decides whether to move along X-direction
        step=dx;
    else //Or Y-direction
        step=dy;

    dx=dx/step;
    dy=dy/step;

    x=x1; //Calculates the increment value for x
    y=y1; //Calculates the increment value for y

    //To plot the quadrants
    line(0,240,639,240);
    line(320,0,320,479);
    outtextxy(295,243,"0,0");
    setcolor(WHITE);

    while(i<=step) //To plot the line
    {
        putpixel(x+320,240-y,12); //Plots the points
        x=x+dx; //Incrementing x
        y=y+dy; //Incrementing y
        i=i+1;
    }

    getch(); //Pauses the Output Console until a key is pressed
    closegraph(); //Closes the graphics mode
    return 0;
}

