#include<iostream>
#include<GLUT/glut.h>
#include <math.h>
using namespace std;
#define PI 3.14159265358979323846

void drawHollowCircle(GLfloat x, GLfloat y, GLfloat radius){
    int i;
    int lineAmount = 2000; //# of triangles used to draw circle
    
    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * PI;
    glColor3f (1.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
                   x + (radius * cos(i *  twicePi / lineAmount)),
                   y + (radius* sin(i * twicePi / lineAmount))
                   );
    }
    glEnd();
}
void display() {
    glClear (GL_COLOR_BUFFER_BIT);
    drawHollowCircle(0, 0,150);
    glFlush();
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
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
