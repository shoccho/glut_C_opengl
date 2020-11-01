#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

//glut fonts
// const int font8x15 = (int)GLUT_BITMAP_8_BY_13;
// const int font9x15 = (int)GLUT_BITMAP_9_BY_15;
// const int fontTimes10 = (int)GLUT_BITMAP_TIMES_ROMAN_10;
// const int fontTimes24 = (int)GLUT_BITMAP_TIMES_ROMAN_24;
// const int fontHelvatica10 = (int)GLUT_BITMAP_HELVETICA_10;
// const int fontHelvatica12 = (int)GLUT_BITMAP_HELVETICA_12;
// const int fontHelvatica18 = (int)GLUT_BITMAP_HELVETICA_18;

// void renderBitmapString(float x, float y, void *font, const char *string)
// {
//     const char *c;
//     glRasterPos2f(x, y);
//     for (c = string; *c != '\0'; c++)
//     {
//         glutBitmapCharacter(font, *c);
//     }
// }

float positions[6] = {-0.5f, -0.5f, -0.5f, 0.0f, 0.5f, -0.5f};
unsigned int buffer;
static void key(unsigned char key, int x, int y)
{
    //     //std::cout << key << std::endl;

    //     glutPostRedisplay();
}
void init()
{
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glutSwapBuffers();
}
void timer(int)
{
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
    gluOrtho2D(-1, 1, -1, 1);
    //gluPerspective(60.0, 1,  2.0,  50.0);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(400, 25);
    glutInitWindowSize(500, 500);
    glutCreateWindow("glew start");
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glGetString(GL_VERSION));

    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(key);
    init();
    glutMainLoop();
    return 0;
}
