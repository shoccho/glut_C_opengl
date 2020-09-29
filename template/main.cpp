#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<math.h>


static void idle(void)
{
    glutPostRedisplay();
}
static void key(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}
void init(){

    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glOrtho(-10,10,-10,10,-10,10);
}

static void display(void){

    glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_QUADS);
        glVertex2d(5,2);
        glVertex2d(5,-5);
        glVertex2d(-5,-5);
        glVertex2d(-5,2);
    glEnd();
    glFlush();
}

int main(){

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Template");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc();
    glutMainLoop();

    return EXIT_SUCCESS;
}
