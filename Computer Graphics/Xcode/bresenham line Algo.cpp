//
//  bresenham line Algo.cpp
//  Computer Graphics
//
//  Created by Mohd Shoaib Rayeen on 18/02/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<GLUT/glut.h>
#include<stdio.h>
#include<math.h>

int xa,xb,ya,yb;

void bresenham_line () {
    
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    int dx , dy , x ,y , xEnd , yEnd, p;
    dx = fabs(xa-xb);
    dy = fabs(ya-yb);
    if ( xa == xb ) {
        x = xa;
        if ( ya > yb ) {
            y = yb;
            yEnd = ya;
        }
        else {
            y = ya;
            yEnd = yb;
        }
        glVertex2s(x,y);
        while ( y < yEnd ) {
            y++ ;
            glVertex2s(x,y);
        }
        
    }
    else if ( ya == yb ) {
        y = ya;
        if ( xa > xb ) {
            x = xb;
            xEnd = xa;
        }
        else {
            x = xa;
            xEnd = xb;
        }
        glVertex2s(x,y);
        while ( x < xEnd ) {
            x++ ;
            glVertex2s(x,y);
        }
    }
    else if ( dy < dx ) {
        p = 2 * dy - dx;
        if ( xa > xb ) {
            x = xb;
            y = yb;
            xEnd = xa;
        }
        else {
            x = xa;
            y = ya;
            xEnd = xb;
        }
        glVertex2s(x,y);
        while ( x < xEnd ) {
            x++ ;
            if( p < 0 ) {
                p = p + 2 * dy;
            }
            else {
                y++;
                p = p + 2 * ( dy - dx );
            }
            glVertex2s(x,y);
        }
    }
    else {
        p = dy - 2 * dx;
        if ( ya > yb ) {
            x = xb;
            y = yb;
            yEnd = ya;
        }
        else {
            x = xa;
            y = ya;
            yEnd = yb;
        }
        glVertex2s(x,y);
        while ( y < yEnd ) {
            y++ ;
            if( p > 0 ) {
                p = p - 2 * dx;
            }
            else {
                x++;
                p = p + 2 * ( dy - dx );
            }
            glVertex2s(x,y);
        }
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
    glutCreateWindow ("Bresenham's Line Algorithm ");
    init ();
    glutDisplayFunc(bresenham_line);
    glutMainLoop();
    return 0;
}
