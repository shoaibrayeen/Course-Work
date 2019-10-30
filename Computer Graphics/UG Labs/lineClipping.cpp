#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

const short top=0x8;
const short bottom=0x4;
const short right=0x2;
const short left=0x1;
const short nil=0;

short generate(float x, float y, float xmin,float xmax, float ymin,float ymax) {
	short code=0;
	if(x<xmin) {
		code|=left;
	}
	else if(x>xmax) {
		code|=right;
	}
	if(y<ymin) {
		code|=bottom;
	}
	else if(y>ymax) {
		code|=top;
	}
	return code;
}

void quadrant(float xmin,float xmax,float ymin,float ymax) {

	line(getmaxx()/2,0,getmaxx()/2,getmaxy());
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	xmin+=getmaxx()/2;
	xmax+=getmaxx()/2;
	ymin=getmaxy()/2-ymin;
	ymax=getmaxy()/2-ymax;
	line(xmin,ymin,xmax,ymin);
	line(xmin,ymin,xmin,ymax);
	line(xmax,ymin,xmax,ymax);
	line(xmin,ymax,xmax,ymax);
}

void main() {
	/* request auto detection */
   	int gdriver = DETECT, gmode, errorcode;
   	double x,y,x1,y1,x2,y2,xmin,ymin,xmax,ymax,dx,dy,slope;
   	int accept=0,done=0;
   	/* initialize graphics and local variables */
   	initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");

   	/* read result of initialization */
   	errorcode = graphresult();
   	if (errorcode != grOk)  /* an error occurred */ {
      		printf("Graphics error: %s\n", grapherrormsg(errorcode));
      		printf("Press any key to halt:");
      		getch();
      		exit(1); /* terminate with an error code */
   	}

   	cout << "Enter the values of xmin,ymin,xmax,ymax: ";
   	cin >> xmin >> ymin >> xmax >> ymax;
   	cout << "\n\nEnter the x & y coordinates of the 1st point: ";
   	cin >> x1 >> y1;
   	cout << "\n\nEnter the x & y coordinates of the 2nd Point: ";
   	cin >> x2 >> y2;
   	cleardevice();
   	quadrant(xmin,xmax,ymin,ymax);
   	setcolor(50);
   	line( x1+getmaxx()/2 , getmaxy()/2 - y1 , x2 + getmaxx()/2 , getmaxy()/2 - y2 );
   	dx=x2-x1;
   	dy=y2-y1;

   	if(dx==0 || dy==0) {
		slope=0;
	}
   	else {
		slope=dy/dx;
	}

   	short code1,code2,codeout;
   	code1=generate(x1,y1,xmin,xmax,ymin,ymax);
   	code2=generate(x2,y2,xmin,xmax,ymin,ymax);

   	do {
		if((code1|code2)==0) {
			accept=1;
			done=1;
		}
		else if(code1&code2) {
			done=1;
		}
		else {
			if(code1) {
				codeout=code1;
			}
			else {
				codeout=code2;
			}

			if(codeout&top) {
				y=ymax;
				x=x2+(1/slope)*(y-y2);
			}
			else if(codeout&bottom) {
				y=ymin;
				x=x2+(1/slope)*(y-y2);
			}
			else if(codeout&left) {
				x=xmin;
				y=y2+(slope)*(x-x2);
			}
			else {
				x=xmax;
				y=y2+(slope)*(x-x2);
			}

			if(codeout==code1) {
				x1=x;
				y1=y;
				code1=generate(x1,y1,xmin,xmax,ymin,ymax);
			}
			else {
				x2=x;
				y2=y;
				code2=generate(x2,y2,xmin,xmax,ymin,ymax);
			}
		}//else
   	}//do
   	while(!done);

   	if(accept==1) {
		setcolor(100);
		line( x1 + getmaxx()/2 , getmaxy()/2 -y1 , x2 + getmaxx()/2 , getmaxy()/2 - y2 );
   	}
   	getch();
}
