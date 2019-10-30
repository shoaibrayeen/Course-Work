#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<iostream.h>
#include<math.h>

void main() {
   	clrscr();
   	int x1,x2,y1,y2;
   	float dy,dx;
   	/* request auto detection */
   	int gdriver = DETECT, gmode, errorcode;
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
	cout << "Enter x1" << endl;
	cin >> x1;
	cout << "Enter x2" << endl;
	cin >> x2;
	cout << "Enter y1" << endl;
	cin >> y1;
	cout << "Enter y2" << endl;
	cin >> y2;

   	line(x1,y1,x2,y2);
   	dy=y2-y1;
   	dx=x2-x1;
   	if(x1==x2) {
		if(y2<y1) {
			int z =y1;
			y1=y2;
			y2=z;
		}
		for(int i=y1;i<=y2;i++) {
			putpixel(x1,i,RED);
		}
   	}
   	else {
		float m=dy/dx;
		if(fabs(m)<1) {
			if(x1>x2) {
				int z=x1;
				x1=x2;
				x2=z;
				z=y1;
				y1=y2;
				y2=z;
			}
			float y=y1;
			for(int i=x1;i<=x2;i++,y+=m) {
				putpixel(i,float(floor(y+0.5)),RED);
			}
		}
		else {
			if(y1>y2) {
				int z=y1;
				y1=y2;
				y2=z;
				z=x1;
				x1=x2;
				x2=z;
			}
			float x=x1;
			for(int i=y1;i<=y2;i++,x+=1/m) {
				putpixel(float(floor(x+0.5)),i,RED);
			}
	 	}
   	}
   	getch();
}
