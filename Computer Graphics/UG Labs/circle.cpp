#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
#include<math.h>

void plotpix(int x,int y,int x1,int y1) {
  	putpixel(x+x1,y+y1,RED);
  	putpixel(y+x1,x+y1,RED);
  	putpixel(y+x1,-x+y1,RED);
  	putpixel(x+x1,-y+y1,RED);
  	putpixel(-x+x1,-y+y1,RED);
  	putpixel(-y+x1,-x+y1,RED);
  	putpixel(-y+x1,x+y1,RED);
  	putpixel(-x+x1,y+y1,RED);
}

void main() {
	clrscr();
	float dE,dNE;
  int x1,x,y1,y,r,d;
  float dy,dx;
  /* request auto detection */
  int gdriver = DETECT, gmode, errorcode;
  int xmax, ymax;
  /* initialize graphics and local variables */
  initgraph(&gdriver, &gmode, "");
 	/* read result of initialization */
  errorcode = graphresult();

  /* an error occurred */
 	if (errorcode != grOk) {
      		printf("Graphics error: %s\n", grapherrormsg(errorcode));
      		printf("Press any key to halt:");
      		getch();
      		exit(1);
  }
  setcolor(getmaxcolor());
  xmax = getmaxx();
  ymax = getmaxy();
	cout << "Enter the coordinates of the origin" << endl;
	cout << "Enter x1" << endl;
	cin >> x1;
	cout << "Enter y1" << endl;
	cin >> y1;
	cout << "Enter the radius" << endl;
	cin >> r;

  x=0;
 	y=r;
  d=1-r;

  plotpix(x,y,x1,y1);
	while(x<=y) {
		if(d<0) {             //choose E 
			d=d+(2*x+3);
			x++;
   		}
		else {               //chhose SE 
			d=d+(2*x-(2*y)+5);
			x++;
			y--;
   		}
		plotpix(x,y,x1,y1);

 	}
	getch();
}
