/*Write C++ program to generate fractal patterns by using Koch curves.*/

#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

void curve(int x1, int y1, int x2, int y2, int n)
{
	//int n;
	float angle = 60*3.14/180;
	int x3 = (2*x1 + x2)/3;
	int y3 = (2*y1 +y2)/3;
	int x4 = (x1+2*x2)/3;
	int y4 = (y1+2*y2)/3;
	
	int x = x3 + (x4 - x3)*cos(angle) + (y4-y3)*sin(angle);
	int y = y3 - (x4 - x3)*sin(angle) + (y4 - y3)*cos(angle) ;
	
	if(n>0)
	{
		delay(10);
		curve(x1, y1, x3, y3, n-1);
		delay(10);
		curve(x3, y3, x, y, n-1);
		delay(10);
		curve(x, y, x4, y4, n-1);
		delay(10);
		curve(x4, y4, x2, y2, n-1);
	}
	else
	{
		line(x1,y1,x3,y3);
		line(x3,y3,x,y);
		line(x,y,x4,y4);
		line(x4,y4,x2,y2);
		
	}
	
}

int main()
{
	int gd=DETECT, gm;
	initgraph(&gd, &gm, NULL);
	curve(200,266,100,100,3);
	curve(100,100,300,100,3);
	curve(300,100,200,266,3);
	delay(6000);
	closegraph();
}

