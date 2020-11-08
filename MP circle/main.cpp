
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <bits/stdc++.h>

//glut fonts

int orthox = 100;
int orthoy = 100;
int orthoz = 100;

std::vector<float> xpoints;
std::vector<float> ypoints;

static void idle(void)
{
    glutPostRedisplay();
}

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
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-orthox, orthox, -orthoy, orthoy, -orthoz, orthoz);
}

void showgrid()
{
    glBegin(GL_LINES);
    // glColor3f(.5f,.5f,.5f);
    // for (int i=-orthoy; i<=orthoy; i++)
    //    {
    //      glVertex2d(orthox,i);
    //    glVertex2d(-orthox,i);

    //}
    //for (int i=-orthox; i<=orthox; i++)
    //{
    //  glVertex2d(i,orthoy);
    //glVertex2d(i,-orthoy);

    //}
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(-orthox, 0);
    glVertex2d(orthox, 0);
    glVertex2d(0, orthoy);
    glVertex2d(0, -orthoy);
    glEnd();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    showgrid();
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(-4,-5,0);
    glBegin(GL_POINTS);
    
    for (int i = 0; i < xpoints.size(); i++)
    {
        glVertex2d(xpoints[i], ypoints[i]);
        glVertex2d(xpoints[i], -abs(ypoints[i]));
glVertex2d(-abs(xpoints[i]), ypoints[i]);
        glVertex2d(-abs(xpoints[i]), -abs(ypoints[i]));

        glVertex2d(ypoints[i], xpoints[i]);
        glVertex2d(ypoints[i], -abs(xpoints[i]));
        glVertex2d(-abs(ypoints[i]), xpoints[i]);
        glVertex2d(-abs(ypoints[i]), -abs(xpoints[i]));
    }
    
    glEnd();
    glPopMatrix();
    
    
    glFlush();
}
void circle(float r, float cx, float cy)
{

    float p = 1 - r;
    float x = 0;
    float y = r;
    int i = 0;
    printf("K,\t\t(X Y),\t\t\t\tPk,\t\t(Xk+1 Yk+1),\t\t(Xplot Yplot)\n");
    float xk, yk;
    xk = x;
    yk = y;

    while (x <= y)
    {
        printf("%d,\t\t(%.02lf %.02lf),\t\t%.02lf,\t\t", i, x, y, p);
        i += 1;
        xpoints.push_back((x ));
        ypoints.push_back((y ));
        if (p >= 0)
        {
            xk += 1;
            yk -= 1;
        }
        else
        {
            xk += 1;
        }
        p = p + (2 * xk + 1) + ((yk) * (yk)-y * y) - (yk - y);
        x = xk;
        y = yk;
        printf("(%.02lf %.02lf),\t\t(%.2lf %.2lf)\n", xk, yk, xk + cx, yk + cy);
        // return (px,py)
    }
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    circle(14,-4, -5);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(300, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("circle");

    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(key);
    glutMainLoop();

    return EXIT_SUCCESS;
}
