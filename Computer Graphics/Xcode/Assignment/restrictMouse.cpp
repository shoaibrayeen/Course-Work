#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;


void mouse() {
    POINT pt;
    int tempX , tempY;
    int centerX = 400;
    int centerY = 300;
    int radius = 150;
    circle(centerX ,centerY ,radius);
    pt.x = tempX = centerX;
    pt.y = tempY = centerY;
    while(!kbhit()) {
        GetCursorPos(&pt);
        if((pow(pt.x - centerX - 2,2) + pow(pt.y - centerY - 25,2) - pow(radius,2)) > 0) {
            SetCursorPos(tempX,tempY);
            pt.x = tempX;
            pt.y = tempY;
        }
        tempX = pt.x;
        tempY = pt.y;
    };
}
int main() {
    initwindow(800,600);
    mouse();
    getch();
    closegraph();
    return 0;
}
