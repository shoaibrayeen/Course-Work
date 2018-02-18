//
//  ellipse.cpp
//  Computer Graphics
//
//  Created by Mohd Shoaib Rayeen on 18/02/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>

GLfloat xa , ya;
GLfloat a , b;
void ellipse () {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    
    GLfloat x = 0 , y = b;
    GLfloat d1 , d2;
    d1=b*b+a*a*(0.25-b);
    glVertex2f(x+xa,y+ya);
    glVertex2f(-x+xa,y+ya);
    glVertex2f(x+xa,-y+ya);
    glVertex2f(-x+xa,-y+ya);
    while((a*a*(y-0.5))>(b*b*(x+1))) {
        if(d1<0) {
            d1=d1+b*b*((2*x)+3);
        }
        else {
            d1=d1+b*b*((2*x)+3)+a*a*((-2*y)+2);
            y--;
        }
        x++;
        glVertex2f(x+xa,y+ya);
        glVertex2f(-x+xa,y+ya);
        glVertex2f(x+xa,-y+ya);
        glVertex2f(-x+xa,-y+ya);
    }
    d2=b*b*pow((x+0.5),2)+a*a*(pow(y-1,2))-(a*a*b*b);
    while(y>0) {
        if(d2<0) {
            d2=d2+b*b*((2*x)+2)+a*a*((-2*y)+3);
            x++;
        }
        else {
            d2=d2+a*a*((-2*y)+3);
        }
        y--;
        glVertex2f(x+xa,y+ya);
        glVertex2f(x+xa,-y+ya);
        glVertex2f(-x+xa,y+ya);
        glVertex2f(-x+xa,-y+ya);
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
    printf("\nEnter the coordinates of ellipse : \n");
    printf("\nEnter x\t:\t");
    scanf("%f" , &xa);
    printf("\nEnter y\t:\t");
    scanf("%f" , &ya);
    printf("\nEnter a\t:\t");
    scanf("%f" , &a);
    printf("\nEnter b\t:\t");
    scanf("%f" , &b);
}
int main(int argc, char** argv) {
    input();
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Ellipse");
    init ();
    glutDisplayFunc(ellipse);
    glutMainLoop();
    return 0;
}

