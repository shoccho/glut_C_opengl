#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

//glut fonts
const int font8x15 = (int)GLUT_BITMAP_8_BY_13;
const int font9x15 = (int)GLUT_BITMAP_9_BY_15;
const int fontTimes10 = (int)GLUT_BITMAP_TIMES_ROMAN_10;
const int fontTimes24 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
const int fontHelvatica10 = (int)GLUT_BITMAP_HELVETICA_10;
const int fontHelvatica12 = (int)GLUT_BITMAP_HELVETICA_12;
const int fontHelvatica18 = (int)GLUT_BITMAP_HELVETICA_18;

float p_pos_x = 0;
float p_pos_y = -1;
float p_pos_z = 0;
float xrot = 0;
float yrot = 0;

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
    std::cout << key << std::endl;
    glutPostRedisplay();
    if (key == 'w')
        p_pos_z += .5;
    else if (key == 's' && p_pos_z > 0)
        p_pos_z -= .5;
    else if (key == 'e')
        p_pos_x += .5;
    else if (key == 'q')
        p_pos_x -= .5;

    else if (key == 'd')
        xrot += 2;
    else if (key == 'a')
        xrot -= 2;
}
void init()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}
void draw(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    int scl = 2;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(p_pos_x, p_pos_y, p_pos_z);
    glRotated(xrot, 0, 1, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_TRIANGLE_STRIP);

    glPushMatrix();
    glRotated(-10, 1, 0, 0);
    glColor3d(.2, 1, .2);
    // glVertex3f(-100.0, -1.0, -100.0);
    // glVertex3f(-100.0, -1.0, 100.0);
    // glVertex3f(100.0, -1.0, 100.0);
    // glVertex3f(100.0, -1.0, -100.0);

    for (int i = -100; i <= 100; i += scl)
    {
        for (int j = -100; j <= 100; j += scl)
        {
            glVertex3d(i, -(rand() % 2), j);
            glVertex3d(i + scl, -(rand() % 2), j);
            glVertex3d(i, -(rand() % 2), j + scl);
            // glVertex3d(i + scl, -rand() % 3, j + scl);
        }
    }
    glEnd();
    glPopMatrix();

    //glFlush();
    glutSwapBuffers();
}
void timer(int)
{
    glutPostRedisplay();
    // std::cout << "x: " << p_pos_x << "y: " << p_pos_y << "z: " << p_pos_z << std::endl;
    glutTimerFunc(1000 / 5, timer, 0);
    //do update here
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(-10, 10, -10, 10);
    gluPerspective(60.0, 1, p_pos_z + 2.0, p_pos_z + 50.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(500, 500);
    glutCreateWindow("terrain");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(key);
    init();
    glutMainLoop();
    return 0;
}
