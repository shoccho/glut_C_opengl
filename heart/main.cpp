#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
#include<math.h>
#define twicePi 2*3.14159


const int font=(int)GLUT_BITMAP_9_BY_15;

void drawFilledelipse(GLfloat x, GLfloat y, GLfloat xcenter,GLfloat ycenter)
{

    int triangleAmount = 20;
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
        for (int i = 0; i <= triangleAmount; i++)
        {
            glVertex2f(
                x + ((xcenter)* cos(i * twicePi / triangleAmount)),
                y + ((ycenter)* sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}






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
   // glOrtho(-1,1,-1,1,-1,1);
}
void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}
static void display(void){
 glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2, 2, -2, 2);

    glPointSize(1);
    glColor3ub(255, 0, 0);  // Color Red
    glBegin(GL_POINTS);
        for (float x = -1.139; x <= 1.139; x += 0.001)
        {
            float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
            float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
            float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
            glVertex2f(x, y1);
            glVertex2f(x, y2);
        }
    glEnd();
    renderBitmapString(-0.9,.3,(void *)font,"I love you Sultana anika ahmed nayona");

    glFlush();
}

int main(){

    glutInitWindowSize(700,700);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode( GLUT_SINGLE|  GLUT_RGB);
    glutCreateWindow("Heart");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();

    return EXIT_SUCCESS;
}
