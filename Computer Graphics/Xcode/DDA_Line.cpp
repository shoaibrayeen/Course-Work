//
//  DDA_Line.cpp
//  Computer Graphics
//
//  Created by Mohd Shoaib Rayeen on 18/02/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>

#define ROUND(x) ((int)(x+0.5))

int xa,xb,ya,yb;

void dda_line () {
    int dx=xb-xa,dy=yb-ya,steps,k;
    float xIncrement,yIncrement,x=xa,y=ya;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    if(fabs(dx)>fabs(dy))
        steps=fabs(dx);
    else steps=fabs(dy);
    xIncrement=dx/(float)steps;
    yIncrement=dy/(float)steps;
    glBegin(GL_POINTS);
    glVertex2s(ROUND(x),ROUND(y));
    for(k=0;k<steps;k++) {
        x+=xIncrement;
        y+=yIncrement;
        glVertex2s(ROUND(x),ROUND(y));
    }
    glColor3f (1.0, 1.0, 1.0);
    for(int i=-200 ; i<=200 ; i++) {
        glVertex2s(i,0);
        glVertex2s(0,i);
    }
    for(int i=-2; i<=2 ; i++) {
        glVertex2s(195+i,4+i);
        glVertex2s(195-i,4+i);
    }
    for(int i=0; i<=2 ; i++) {
        glVertex2s(4+i,195+i);
        glVertex2s(4-i,195+i);
        glVertex2s(4,195-i);
    }
    
    glEnd();
    glFlush();
}
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
}
void input() {
    printf("\nEnter the points\n");
    printf("\nEnter x1\t:\t");
    scanf("%d" , &xa);
    printf("\nEnter y1\t:\t");
    scanf("%d" , &ya);
    printf("\nEnter x2\t:\t");
    scanf("%d" , &xb);
    printf("\nEnter y2\t:\t");
    scanf("%d" , &yb);
}
int main(int argc, char** argv) {
    input();
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Simple DDA ");
    init ();
    glutDisplayFunc(dda_line);
    glutMainLoop();
    return 0;
}
