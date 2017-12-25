#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>


void input();
void output();
void translation();
void rotation();
void scaling();
void shearing();
void reflection();


int a[10][2],i,x,temp,y,n,fx,fy,opt,ch,j=1;
int sx,sy;
int tx,ty;
float k;
int shx,shy;



void input() {	
	printf("\nEnter the number of lines: ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
   		printf("\nEnter the coordinates for the Line: ");
   		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i+1][0],&a[i+1][1]);
 	}
}



void output() {

	line(getmaxx()/2,0,getmaxx()/2,getmaxy());     //display quadrant system
	line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
	for(i=0;i<n;i++) {
     		line(a[i][0]+getmaxx()/2,getmaxy()/2-a[i][1],a[i+1][0]+getmaxx()/2,getmaxy()/2-a[i+1][1]);
   	}
}
 
void translation() {
   	printf("enter the tranformation vertex tx,ty:\n");
   	scanf("%d%d",&tx,&ty);
   	cleardevice();
   	output();
    	for(i=0;i<=n;i++) {
      		a[i][0]=a[i][0]+tx;
      		a[i][1]=a[i][1]+ty;
    	}
	setlinestyle(2,1,1);
	output();
	setlinestyle(0,1,1);
	line(75,460,125,460);
	outtextxy(130,460,"Before translation");
	setlinestyle(2,1,1);
	line(300,460,350,460);
	outtextxy(355,460,"After translation");
	outtextxy(520,460,"SHOBHIT");
	delay(100);
}



void rotation() {
	printf("\nEnter the rotating angle: ");
	scanf("%d",&y);
	printf("\nEnter the pivot point:");
	scanf("%d%d",&fx,&fy);
	cleardevice();
	output();
	k=(y*3.14)/180;
	for(i=0;i<=n;i++) {
		tx=fx+(a[i][0]-fx)*cos(k)-(a[i][1]-fy)*sin(k);
		ty=fy+(a[i][0]-fx)*sin(k)+(a[i][1]-fy)*cos(k);
		a[i][0]=tx;
		a[i][1]=ty;

	}
	setlinestyle(2,1,1);
	output();
	setlinestyle(0,1,1);
	line(75,460,125,460);
	outtextxy(130,460,"Before rotation");
	setlinestyle(2,1,1);
	line(300,460,350,460);
	outtextxy(355,460,"After rotation");
	outtextxy(520,460,"SHOBHIT");
	delay(100);
}




void scaling() {
	printf("\nEnter the scaling factor: ");
	scanf("%d%d",&sx,&sy);
	cleardevice();
	output();
	for(i=0;i<=n;i++) {
		a[i][0]=a[i][0]*sx;
		a[i][1]=a[i][1]*sy;
	}
	setlinestyle(2,1,1);
	output();
	setlinestyle(0,1,1);
	line(75,460,125,460);
	outtextxy(130,460,"Before scaling");
	setlinestyle(2,1,1);
	line(300,460,350,460);
	outtextxy(355,460,"After scaling");
	outtextxy(520,460,"SHOBHIT");
	delay(100);
}



void shearing() {
	printf("\nEnter the shearing factor: ");
	scanf("%d%d",&shx,&shy);
	cleardevice();
	output();
	for(i=0;i<=n;i++) {
		x=a[i][0];
		y=a[i][1];
		int x1=x+shx*y;
		int y1=y+x*shy;
		a[i][0]=x1;
		a[i][1]=y1;
	}


	setlinestyle(2,1,1);
	output();
	setlinestyle(0,1,1);

	line(75,460,125,460);
	outtextxy(130,460,"Before shearing");
	setlinestyle(2,1,1);
	line(300,460,350,460);
	outtextxy(355,460,"After shearing");
	outtextxy(520,460,"SHOBHIT");
	delay(100);
}

void reflection() {
	int cr;
	printf("\n0:About origin\n1:About x=y\n2:About x\n3:About y\n4:About x=-y\n");
	printf("\nEnter your Choice: ");
	scanf("%d",&cr);
	cleardevice();
	output();
	if(cr==0) {
		for(i=0;i<=n;i++) {
			a[i][0]=a[i][0]*(-1);            // change x
			a[i][1]=a[i][1]*(-1);            // change y
		}
  	}
	if(cr==1) {
		for(i=0;i<=n;i++) {   // swap x and y
			int swap;
			swap=a[i][0];
			a[i][0]=a[i][1];
			a[i][1]=swap;

		}
	}
	if(cr==2) {
		for(i=0;i<=n;i++) {
			a[i][1]=a[i][1]*(-1);            // change y
		}
	}
	if(cr==3) {
		for(i=0;i<=n;i++) {
			a[i][0]=a[i][0]*(-1);           // change x
		}
	}
	if(cr==4) {
		for(i=0;i<=n;i++) {  // multiply by -1 and then swap x y
			int swap;
			a[i][0]=(-1)*a[i][0];
			a[i][1]=(-1)*a[i][1];
			swap=a[i][0];
			a[i][0]=a[i][1];
			a[i][1]=swap;
		}
	}



	setlinestyle(2,1,1);
	output();
	setlinestyle(0,1,1);
	line(75,460,125,460);
	outtextxy(130,460,"Before reflection");
	setlinestyle(2,1,1);
	line(300,460,350,460);
	outtextxy(355,460,"After reflection");
	outtextxy(520,460,"SHOBHIT");
	delay(100);
}


void main() {

	int gd=DETECT,gx;
	initgraph(&gd,&gx,"C:\\TurboC3\\BGI");
	input();
	output();

	do {
		printf("\nWhat Do you want to do with current object\n");
		printf("\n1:Translation\n2:Rotation\n3:Scaling\n4:Shearing\n5:Reflection\n");
		printf("\nEnter your Choice: ");
		scanf("%d",&ch);
		switch(ch) {
			case 1 :	translation();
					break;
			case 2 :	rotation();
					break;
			case 3 :	scaling();
					break;
			case 4 :	shearing();
					break;
			case 5 :	reflection();
					break;
		}
		delay(6000);
		closegraph();


		initgraph(&gd,&gx,"C:\\TurboC3\\BGI");
		setlinestyle(0,1,1);

		printf("To continue press 1 & to EXIT press 0:");
		scanf("%d",&j);

		if(j==1) {
 			printf("\nThe current object has the line coordinates:");
  			for(i=0;i<n;i++) {
   				printf("\n");
   				printf("For line %d:",i+1);
   				printf("%d %d %d %d",a[i][0],a[i][1],a[i+1][0],a[i+1][1]);
  			}
		}

	}while(j==1);

	getch();
}
