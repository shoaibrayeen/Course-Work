//
//  bar_graph.cpp
//  Computer Graphics
//
//  Created by Mohd Shoaib Rayeen on 06/04/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<GLUT/glut.h>
#include<iostream>
using namespace std;

void printaxis();

void bar_graph() {
    int numbers_of_bar;
    cout << "\nHow many bars do you want to see?\t:\t";
    cin >> numbers_of_bar;
    printaxis();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //printing bars
    double j = -110;
    double k = 80;
    double add;
    int p;
    float m = 0 , n = 0 , o = 0;
    for ( int i = 1 ; i <= numbers_of_bar; ++i ) {
        if(numbers_of_bar > 7) {
            add = 12;
        }
        else {
            add = 20;
        }
        p = i;
        if(i > 7 ) {
            p = i%7;
        }
        if( (p&1) == 1 ) {
            o = 1;
        }
        if ( (p&2) == 2 ) {
            n = 1;
        }
        if ( (p&4) == 4  ) {
            m = 1;
        }
        k = random()%100;
        while(k < 50) {
            k = random()%100;
        }
        glColor3f (m, n, o);
        glBegin(GL_POLYGON);
        glVertex2d( j,-120 );
        glVertex2d(j+add,-120);
        glVertex2d(j+add,k);
        glVertex2d(j,k);
        j=j+add*(1.5);
        glEnd();
        m = n = o = 0;
    }
    glFlush();
}

void printaxis() {
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_POLYGON);
    glVertex2d(-140,-140);
    glVertex2d(140,-140);
    glVertex2d(140,140);
    glVertex2d(-140,140);
    glEnd();
    glFlush();
    glColor3f (1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    //For Printing Axes
    glVertex2d(-120,120);
    glVertex2d(-120,-120);
    glVertex2d(-120,-120);
    glVertex2d(120,-120);
    //glEnd();
    //glBegin(GL_LINES);
    //for printing X
    glVertex2d(123,-122);
    glVertex2d(127,-118);
    glVertex2d(123,-118);
    glVertex2d(127,-122);
    //glEnd();
    //glBegin(GL_LINES);
    //For Printing Y
    glVertex2d(-120,125);
    glVertex2d(-118,135);
    glVertex2d(-121,135);
    glVertex2d(-119,130);
    glEnd();
}
void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glOrtho(-150.0, 150.0, -150.0, 150.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1700, 1000);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("Bar Graph");
    init ();
    glutDisplayFunc(bar_graph);
    glutMainLoop();
    return 0;
}
