#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

float p_pos_x = 0;
float p_pos_y = 0;
float p_pos_z = 0;
float xrot = 0;
float yrot = 0;
int HEIGHT = 500, WIDTH = 500;
int chunkSize = 100;
float windrot = 0;
bool wind = false;
float speed = 0;
GLUquadricObj *quadratic = gluNewQuadric();

static void key(unsigned char key, int x, int y)
{
    // std::cout << key << std::endl;

    if (key == 'w')
        p_pos_z += .5;
    else if (key == 's' && p_pos_z > 0)
        p_pos_z -= .5;
    else if (key == 'd')
        p_pos_x -= .5;
    else if (key == 'a')
        p_pos_x += .5;
    else if (key == 'b')
    {
        if (wind == true)
        {
            wind = false;
            speed = 0;
        }
        else
        {
            wind = true;
            speed = .2;
        }
    }
    if (key == 'f')
    {
        speed += .5;
    }
    glutPostRedisplay();
}
void init()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
}
void drawwindmill()
{

    glPushMatrix();

    glPushMatrix();
    glTranslated(0, 5, 0);
    glRotated(windrot, 0, 0, 1);
    glColor3f(0.94f, 0.50f, 0.00f);

    glBegin(GL_TRIANGLES);

    glVertex3f(-.5f, 0.0f, -15.0f);
    glVertex3f(.5f, 0.0f, -15.0f);
    glVertex3f(0.0f, 4.0f, -15.0f);

    glVertex3f(-.5f, 0.0f, -15.0f);
    glVertex3f(.5f, 0.0f, -15.0f);
    glVertex3f(0.0f, -4.0f, -15.0f);

    glVertex3f(0.f, -.5f, -15.0f);
    glVertex3f(0.f, 0.5f, -15.0f);
    glVertex3f(4.f, 0.f, -15.0f);

    glVertex3f(0.f, -.5f, -15.0f);
    glVertex3f(0.f, 0.5f, -15.0f);
    glVertex3f(-4.f, 0.0f, -15.0f);

    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.1f, 0.3f, 0.2f);

    glTranslated(0, 7, -16);
    glRotated(90, 1, 0, 0);
    gluCylinder(quadratic, .3, .3, 15, 10, 10);

    glPopMatrix();
}

void drawTerrain()
{
    glPushMatrix();
    glRotated(-10, 1, 0, 0);

    glBegin(GL_QUADS);

    glColor3f(0.13f, 0.36f, 0.09f);
    glVertex3f(-chunkSize, -1.0, -chunkSize);
    glVertex3f(-chunkSize, -1.0, chunkSize);
    glVertex3f(chunkSize, -1.0, chunkSize);
    glVertex3f(chunkSize, -1.0, -chunkSize);
    glEnd();
    glPopMatrix();
}
GLfloat lightpos[] = {5, 10, 20, 1};
void draw_sun()
{
    glPushMatrix();
    glTranslated(5, 10, -20);
    glColor4b(1, 0, 0, 1);
    glutSolidSphere(1.5, 50, 50);
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glPopMatrix();
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glEnable(GL_LIGHTING);

    glEnable(GL_LIGHT0);
    glTranslatef(p_pos_x, p_pos_y, p_pos_z);
    glRotated(xrot, 0, 1, 0);
    glRotated(yrot, 1, 0, 0);
    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glEnable(GL_COLOR_MATERIAL);
    drawTerrain();
    draw_sun();
    drawwindmill();
    //glFlush();
    glutSwapBuffers();
}
void timer(int)
{
    if (wind == true)
    {
        windrot += speed;
        if (windrot >= 360)
            windrot -= 360;
    }
    glutPostRedisplay();
    // std::cout << "x: " << p_pos_x << "y: " << p_pos_y << "z: " << p_pos_z << std::endl;
    glutTimerFunc(1000 / 60, timer, 0);
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
void mouse(int button, int state, int x, int y)
{
}
void passiveMotion(int x, int y)
{

    xrot = (x - (WIDTH / 2)) / 5;
    yrot = (y - (HEIGHT / 2)) / 5;
    if (yrot > 0)
        yrot = 0;
    if (xrot <= -70)
        xrot = -70;
    if (xrot >= 70)
        xrot = 70;
    std::cout << xrot << " " << yrot << std::endl;
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Project");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    init();
    glutMainLoop();
    return 0;
}
