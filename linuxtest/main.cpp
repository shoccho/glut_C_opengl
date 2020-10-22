#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
float x = 0;
float dx = 1;
void init()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}
void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3d(1, 0, 0);
    glPushMatrix();
    glTranslatef(0, 0.0f, -8.0f);
    glRotated(x, 1, 1, 1);
    //glTranslatef(0, 0.0f, -8.0f);
    glBegin(GL_QUADS);
    //zf
    glColor3d(1, 0, 0);
    glVertex3d(1, 1, 1);
    glVertex3d(1, -1, 1);
    glVertex3d(-1, -1, 1);
    glVertex3d(-1, 1, 1);

    glColor3d(0, 1, 0);
    glVertex3d(1, 1, -1);
    glVertex3d(1, -1, -1);
    glVertex3d(-1, -1, -1);
    glVertex3d(-1, 1, -1);

    //xf
    glColor3d(0, 0, 1);
    glVertex3d(1, 1, 1);
    glVertex3d(1, 1, -1);
    glVertex3d(1, -1, -1);
    glVertex3d(1, -1, 1);

    glColor3d(1, 0, 1);
    glVertex3d(-1, 1, 1);
    glVertex3d(-1, 1, -1);
    glVertex3d(-1, -1, -1);
    glVertex3d(-1, -1, 1);

    //yf
    glColor3d(1, 1, 0);
    glVertex3d(1, 1, 1);
    glVertex3d(1, 1, -1);
    glVertex3d(-1, 1, -1);
    glVertex3d(-1, 1, 1);

    glColor3d(1, 1, 1);
    glVertex3d(1, -1, 1);
    glVertex3d(1, -1, -1);
    glVertex3d(-1, -1, -1);
    glVertex3d(-1, -1, 1);

    glEnd();
    glPopMatrix();
    //glFlush();
    glutSwapBuffers();
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
    x += dx;
    if (x > 360)
        x = 0;
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
    glutInitWindowSize(500, 500);
    glutCreateWindow("linux test");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}