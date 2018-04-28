//
//  circle_in_circle.cpp
//  Computer Graphics
//
//  Created by Mohd Shoaib Rayeen on 23/03/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>


void plotpix(int x,int y) {
    glVertex2f(x,y);
    glVertex2f(y,x);
    glVertex2f(y,-x);
    glVertex2f(x,-y);
    glVertex2f(-x,-y);
    glVertex2f(-y,-x);
    glVertex2f(-y,x);
    glVertex2f(-x,y);
}
int j = 0;
void circle (GLfloat radius) {
    GLfloat x = 0 , y = radius;
    GLfloat p = 1 - radius ;
    
    plotpix(x,y);
    while(x<=y) {
        for(int i = x; i <= y; i++) {
            plotpix(j,i);
        }
        j++;
        if(p<0) {
            x++;
            p = p + 2*x +1;
        }
        else {
            x++;
            y--;
            p = p + 2 *  ( x - y ) + 1;
        }
        plotpix(x,y);
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

void circle_in_circle() {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    circle(100);
    j = 0;
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    circle(75);
    j = 0;
    glColor3f (0.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    circle(50);
}

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-200.0, 200.0, -200.0, 200.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Circle in circle");
    init ();
    glutDisplayFunc(circle_in_circle);
    glutMainLoop();
    return 0;
}
