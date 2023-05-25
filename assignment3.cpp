/*Write C++ program to draw the following pattern. Use DDA line and Bresenham‘s circle drawing algorithm. Apply the concept of 
encapsulation.*/

#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;
class tri_cir {
private:
	float x1,y1,x2,y2,step;
	int xc,yc,R;
	int xi,yi,di,limit,del,del2;
public:
	void ddaline(int x1,int y1,int x2,int y2,int icolour);
	void bresencircle(int xc,int yc,int R);
};

//dda line
void tri_cir:: ddaline(int x1,int y1,int x2,int y2,int icolour) {

	int i;
	float dx,dy,steps,xinc,yinc,X,Y;
	dx=(x2-x1);
	dy=(y2-y1);
	if (fabs(dx)>fabs(dy))
	{
	steps=fabs(dx);
	}
	else
	{
	steps=fabs(dy);
	}
	xinc=dx/steps;
	yinc=dy/steps;
	X=x1;
	Y=y1;
	for (i=0;i<steps;i++)
	{
	putpixel(floor(X),floor(Y),icolour);
	X=X+xinc;
	Y=Y+yinc;
	}
}

//bresenham circle
void tri_cir::bresencircle(int xc,int yc,int R)
{
	xi=0;
	yi=R;
	di=2*(1-R);
	limit=0;
	
	while (yi>=limit)
	{
		putpixel(xc+xi, yc+yi, 3);
		putpixel(xc-xi, yc+yi, 4);
		putpixel(xc-xi, yc-yi, 5);
		putpixel(xc+xi, yc-yi, 6);
		if (di<0)
		{
			del=(2*di)+(2*yi)-1;
			if (del<=0)
			{
				//mh
				xi+=1;
				di=di+(2*xi)+1;
			}
			else
			{
				//md
				xi+=1;
				yi-=1;
				di=di+(2*xi)-(2*yi)+2;
			}
		}
		else if (di>0)
		{
			del2=(2*di)-(2*xi)-1;
			if (del2<=0)
			{
				//md
				xi+=1;
				yi-=1;
				di=di+(2*xi)-(2*yi)+2;
			}
			else
			{
				//mv
				yi-=1;
				di=di-(2*yi)+1;
			}
		}
		else if (di==0)
		{
			//md
			xi+=1;
			yi-=1;
			di=di+(2*xi)-(2*yi)+2;
		}
	}
}

int main() {
int gd,gm;
gd=DETECT;
initgraph(&gd,&gm,NULL);

//object creation
tri_cir obj;

//cicle
obj.bresencircle(200,125,67);

//rectangle
obj.ddaline(50,50,350,50,WHITE);
obj.ddaline(50,50,50,200,WHITE);
obj.ddaline(50,200,350,200,WHITE);
obj.ddaline(350,50,350,200,WHITE);

//diamond
obj.ddaline(200,50,350,125,WHITE);
obj.ddaline(200,50,50,125,WHITE);
obj.ddaline(50,125,200,200,WHITE);
obj.ddaline(200,200,350,125,WHITE);
delay(50000);
getch();
closegraph();
return 0;
}
