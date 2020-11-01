#include <GL/gl.h>
#include <GL/glut.h>

int angle_x = 0;

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotated(angle_x, 0, 0, 1);
    glColor3f(1, 0, 0);
    glRectf(-25, -25, 25, 25);
    glPopMatrix();
    glutSwapBuffers();
}

void spin()
{
    angle_x += 1;
    angle_x %= 360;
    glutPostRedisplay();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glutIdleFunc(spin);
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glutIdleFunc(NULL);
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("spin");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}