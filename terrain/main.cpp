#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

//glut fonts
// const int font8x15 = GLUT_BITMAP_8_BY_13;
// const int font9x15 = GLUT_BITMAP_9_BY_15;
// const int fontTimes10 = GLUT_BITMAP_TIMES_ROMAN_10;
// const int fontTimes24 = GLUT_BITMAP_TIMES_ROMAN_24;
// const int fontHelvatica10 = GLUT_BITMAP_HELVETICA_10;
// const int fontHelvatica12 = GLUT_BITMAP_HELVETICA_12;
// const int fontHelvatica18 = GLUT_BITMAP_HELVETICA_18;

//global stuff
int width = 600, height = 600;

//stuffs
int cols, rows;
int scl = 20;

void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
static void key(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}
void init()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    cols = width / scl;
    rows = height / scl;
}
void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3d(1, 0, 0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glPushMatrix();
    glTranslatef(0, 0.0f, -8.0f);
    //glRotatef(30, 1, 0, 0);
    // glPushMatrix();
    // for (int x = 0; x < cols; x++)
    // {
    //     glBegin(GL_TRIANGLE_STRIP);
    //     for (int y = 0; y < rows; y++)
    //     {
    //         glVertex3d(x * scl, y * scl, 0);
    //         //glVertex3d((x + 1) * scl, y * scl, 0);
    //         glVertex3d((x)*scl, (y + 1) * scl, 0);
    //     }
    //     glEnd();
    // }

    glBegin(GL_LINES);

    glVertex3d(0, 0, 0);
    glColor3f(0, 1, 0);
    glVertex3d(width, height, 0);
    glEnd();
    glPopMatrix();
    //glFlush();
    glutSwapBuffers();
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    //do update here
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-10, 10, -10, 10);
    gluPerspective(60.0, 1, 2, 50);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(width, height);
    glutCreateWindow("template");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(key);
    init();
    glutMainLoop();
    return 0;
}