#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void hermite(int x1,int y1,int x2,int y2,float slope1,float slope2) {
	float x,y;
	float u;
	for(u=0.00;u<=1.0;u+=0.001) {
		x=(2*u*u*u-3*u*u+1)*x1+(-2*u*u*u+3*u*u)*x2+(u*u*u-2*u*u+u)*slope1*x1+(u*u*u-u*u)*slope2*x2;
		y=(2*u*u*u-3*u*u+1)*y1+(-2*u*u*u+3*u*u)*y2+(u*u*u-2*u*u+u)*slope1*x1+(u*u*u-u*u)*slope2*x2;
		putpixel(20+(int)(x+0.5),240-(int)(y+0.5),RED);                // shifting and type casting
	}
}

void main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	int x1,y1,x2,y2;
	float m1,m2;
	cout << endl << "Enter first point(x,y) ";
	cin >> x1 >> y1;
	cout << endl << "Enter second point(x,y) ";
	cin >> x2 >> y2;
	cout << endl << "Enter two slopes ";
	cin >> m1 >> m2;
	hermite(x1,y1,x2,y2,m1,m2);

	getch();
	closegraph();
}
