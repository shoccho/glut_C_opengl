#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>
#define twicePi 6.28318

void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter,GLfloat ycenter) {
int i;
int triangleAmount = 20; //# of triangles used to draw circle

//GLfloat radius = 0.8f; //radius
//GLfloat twicePi = 2.0f * PI;
 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x, y); // center of circle
for (i = 0; i <= triangleAmount; i++) {
    glVertex2f(
        x + ((xcenter+1)* cos(i * twicePi / triangleAmount)),
        y + ((ycenter-1)* sin(i * twicePi / triangleAmount))
    );
}
glEnd();
 glFlush();
}


void init(){

    glClearColor(0.0f,1.0f,0.0f,0.0f);
    glOrtho(-6,6,-6,6,-6,6);
}
static void display(void){
    int x,y,i,radius=2;
    x=4.5,y=3;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f,0.0f,0.0f);
    drawFilledelipse(0,0,.2f,.1f);
    glFlush();
}

int main(){

    glutInitWindowSize(800,450);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("BD flag");


    init();
    glutDisplayFunc(display);
    //glClearColor(1,1,1,1);
    glutMainLoop();

    return EXIT_SUCCESS;
}
