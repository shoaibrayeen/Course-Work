  /*
     Bresenham line drawing algorithm.
  */
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<process.h>

void main() {
	clrscr();
 	int gdriver = DETECT, gmode, errorcode;
 	initgraph(&gdriver, &gmode,"");
 	errorcode = graphresult();
 	if (errorcode != grOk) {
  		cout << "Graphics error: %s\n" << grapherrormsg(errorcode);
  		cout << "\nPress any key to halt:";
  		getch();
  		exit(1);
 	}
 	float x1,y1,x2,y2,a,b;
 	float m;
 	cout << "\nEnter the starting coordinates\n";
 	cout<<"\nEnter x1: ";
 	cin>>x1;
 	cout<<"\nEnter y1: ";
 	cin>>y1;
 	cout<<"\nEnter the ending coordinates\n";
 	cout<<"\nEnter x2: ";
 	cin>>x2;
 	cout<<"\nEnter y2: ";
 	cin>>y2;
	clrscr();
	setcolor(getmaxcolor());
	line(x1,y1,x2,y2);
	if((x2-x1)==0) {
   		if(y1>y2) {
			int temp;
       			temp=y1;
       			y1=y2;
       			y2=temp;
   		}
      		for(int i=y1;i<=y2;i++) {
	   		putpixel(x1,i,RED);
		}

	}
	else if((y2-y1)==0) { 
		if(x1>x2) {     
			int temp;
       			temp=x1;
       			x1=x2;
       			x2=temp;
    		}
      		for(int i=x1;i<=x2;i++) {
	  		putpixel(i,y1,RED);
		}
	}
	else {
		if(x1>x2) {
			float temp;
			temp=x1;
			x1=x2;
			x2=temp;
			temp=y1;
			y1=y2;
			y2=temp;
		}
		float m;
		float x=x1,y=y1,d;
		m=(y2-y1)/(x2-x1);
		a=y2-y1;
		b=x1-x2;
		if(fabs(m)<1) {
			if(y1<y2) {
				d=(2*a)+b;
				while(x<=x2) {
					if(d<0) {
						d=d+(2*a);
					}
					else {
						d=d+(2*a)+(2*b);
						y++;
					}
					x++;
					putpixel(x,y,RED);
				}
			}
	 		else {
				d=(2*a)-b;
				while(x<=x2) {
					if(d>0) {
						d=d+(2*a);
					}
					else {
						d=d+(2*a)-(2*b);
						y--;
					}
					x++;
					putpixel(x,y,RED);
				}
	   		}
		}
		else {
			if(y1<y2) {
				d=a+(2*b);
				while(y<=y2) {
					if(d>0) {
						d=d+(2*b);
					}
					else {
						d=(d+(2*a))+(2*b);
						x++;
					}
					y++;
					putpixel(x,y,RED);
				}
		 	}
		  	else {
				d=a-(2*b);
				while(y>=y2) {
					if(d<0) {
						d=d-(2*b);
					}
					else {
						d=(d+(2*a))-(2*b);
						x++;
					}
					y--;
					putpixel(x,y,RED);
				}
		  	}
		}
	}
	getch();
}
