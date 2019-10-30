#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

void circleInCircle() {
    struct arccoordstype a;
    int angle = 0;
    while(angle<=360) {
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,100);
      setcolor(RED);
      getarccoords(&a);
      circle(a.xstart,a.ystart,25);
      setcolor(BLACK);
      arc(getmaxx()/2,getmaxy()/2,angle,angle+2,150);
      getarccoords(&a);
      setcolor(YELLOW);
      circle(a.xstart,a.ystart,25);
      angle = angle+5;
      delay(50);
   }
}

int main(){
    initwindow(800,600);
    circleInCircle();
    getch();
    closegraph();
    return 0;
}
