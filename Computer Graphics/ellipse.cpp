#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

void putellipse1(int x,int y,int x1,int y1,int c) {
    	putpixel(x+x1,y+y1,c);
    	putpixel(-x+x1,y+y1,c);
    	putpixel(x+x1,-y+y1,c);
    	putpixel(-x+x1,-y+y1,c);
}

void putellipse2(int x,int y,int x1,int y1,int c) {
    	putpixel(x+x1,y+y1,c);
    	putpixel(x+x1,-y+y1,c);
    	putpixel(-x+x1,y+y1,c);
    	putpixel(-x+x1,-y+y1,c);
}

void ellipse(int x1,int y1,double a,double b) {
    	clrscr();
    	int x=0,y=b,c=0;
    	double d1,d2;
    	d1=b*b+a*a*(0.25-b);
    	putellipse1(x,y,x1,y1,c);
    	randomize();
    	while((a*a*(y-0.5))>(b*b*(x+1))) {
		if(d1<0) {
	     		d1=d1+b*b*((2*x)+3);
	  	}
		else {
			d1=d1+b*b*((2*x)+3)+a*a*((-2*y)+2);
			y--;
	  	}
		x++;
		c=rand()%100;
		putellipse1(x,y,x1,y1,c);
      }
    	d2=b*b*pow((x+0.5),2)+a*a*(pow(y-1,2))-(a*a*b*b);
    	randomize();
    	while(y>0) {
		if(d2<0) {
	     		d2=d2+b*b*((2*x)+2)+a*a*((-2*y)+3);
	     		x++;
	  	}
		else {
	     		d2=d2+a*a*((-2*y)+3);
	  	}
		y--;
		c=rand()%100;
		putellipse2(x,y,x1,y1,c);
       }
}

void main() {

      	clrscr();
      	int gdriver = DETECT, gmode, errorcode;
      	initgraph(&gdriver, &gmode,"c:\\tc\\bgi");
      	errorcode = graphresult();
      	if (errorcode != grOk) {
	    	cout << "Graphics error: %s\n" << grapherrormsg(errorcode);
	    	cout << "\nPress any key to halt:";
	    	getch();
	    	exit(1);
	      }
      	int x,y;
     	  double a,b;
      	cout << "Enter the coordinates of ellipse : \n";
      	cin >> x;
      	cin >> y;
      	cout << "Enter a : ";
      	cin >> a;
      	cout << "Enter b : ";
      	cin >> b;
      	ellipse(x,y,a,b);
      	getch();
}
