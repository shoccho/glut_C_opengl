#include <GL/gl.h>
#include <GL/glut.h>

int angle_x = 0;

void showgrid(){
    int ortho=10;
   glBegin(GL_LINES);
    glColor3f(.5f,.5f,.5f);
    for (int i=-ortho; i<=ortho; i++)
    {
        glVertex2d(ortho,i);
        glVertex2d(-ortho,i);

    }
    for (int i=-ortho; i<=ortho; i++)
    {
        glVertex2d(i,ortho);
        glVertex2d(i,-ortho);

    }
    glColor3f(0.0f,0.0f,1.0f);
    glVertex2d(-ortho,0);
    glVertex2d(ortho,0);

    glVertex2d(0,ortho);
    glVertex2d(0,-ortho);

    glEnd();
}
void init(void)
{
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_FLAT);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    showgrid();
    glPushMatrix();
    glRotated(50,0,1,0);
    glBegin(GL_QUADS);
    glVertex2d(5,3);
    glVertex2d(-4,3);
    glVertex2d(-6,-2);
    glVertex2d(6,-2);
    glEnd();
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
    glOrtho(-10, 10, -10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glutIdleFunc(NULL);
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