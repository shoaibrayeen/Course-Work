//
//  circle.cpp
//  Computer Graphics
//
//  Created by Mohd Shoaib Rayeen on 18/02/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

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

GLfloat xa , ya , radius;

void plotpix(int x,int y,int x1,int y1) {
    glVertex2f(x+x1,y+y1);
    glVertex2f(y+x1,x+y1);
    glVertex2f(y+x1,-x+y1);
    glVertex2f(x+x1,-y+y1);
    glVertex2f(-x+x1,-y+y1);
    glVertex2f(-y+x1,-x+y1);
    glVertex2f(-y+x1,x+y1);
    glVertex2f(-x+x1,y+y1);
}
void circle () {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    
    GLfloat x = 0 , y = radius;
    GLfloat p = 1-radius;
    
    plotpix(x,y,xa,ya);
    while(x<=y) {
        if(p<0) {
            x++;
            p = p + 2*x +1;
        }
        else {
            x++;
            y--;
            p = p + 2 *  ( x - y ) + 1;
        }
        plotpix(x,y,xa,ya);
        
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
    printf("\nEnter orgin of circle : \n");
    printf("\nEnter x\t:\t");
    scanf("%f" , &xa);
    printf("\nEnter y\t:\t");
    scanf("%f" , &ya);
    printf("\nEnter radius\t:\t");
    scanf("%f" , &radius);
}

int main(int argc, char** argv) {
    input();
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Circle");
    init ();
    glutDisplayFunc(circle);
    glutMainLoop();
    return 0;
}


