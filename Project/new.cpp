#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>

#define HEIGHT 500
#define WIDTH 500
#define block 10
#define grass_color         \
    {                       \
        0.13f, 0.36f, 0.09f \
    }
#define sand_color          \
    {                       \
        0.72f, 0.67f, 0.17f \
    }
int renderDist = 1000;

float camX = 0;
float camY = 0;
float camZ = 0;
float rot = 0;
struct Chunk
{
    int startX, startY, endX, endY;
    char type[5];
    // std::vector<float> color;
    float color[3];
};

std::vector<Chunk> Terrain;

static void key(unsigned char key, int x, int y)
{
    if (key == 'w')
        camZ += 1;
    if (key == 's')
        camZ -= 1;
    if (key == 'r')
    {
        camZ = 0;
        camX = 0;
        camY = 0;
    }
    glutPostRedisplay();
}

void init()
{
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1, 2, renderDist);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 1);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_MODELVIEW);
}

void drawTerrain()
{

    glColorMaterial(GL_FRONT_AND_BACK, GL_EMISSION);
    glEnable(GL_COLOR_MATERIAL);
    for (auto chunk : Terrain)
    {
        glColor3fv(chunk.color);
        //
        for (int Y = chunk.startY; Y <= chunk.endY; Y += block)
        {
            for (int X = chunk.startX; X <= chunk.endX; X += block)
            {
                glRectf(X, Y, X + block, Y + block);
            }
        }
    }
}

void handleCam_lights()
{
    glLoadIdentity();
    glTranslated(0, 0, -renderDist / 2);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}
void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTranslated(camX, camY, camZ);
    handleCam_lights();
    drawTerrain();

    std::cout << camX << " " << camY << " " << camZ << " " << std::endl;
    glutSwapBuffers();
}
void timer(int)
{
    rot += .1;
    if (rot > 360)
    {
        rot -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, 1, camZ + 2, camZ + renderDist);
    glMatrixMode(GL_MODELVIEW);
}
void mouse(int button, int state, int x, int y)
{
}
void passiveMotion(int x, int y)
{
}
void generateChunks()
{

    Chunk grass = {0, 0, 500, 500, "grss", grass_color};

    Terrain.push_back(grass);
    Chunk sand = {-500, -500, 0, 0, "sand", sand_color};
    Terrain.push_back(sand);
}
int main(int argc, char **argv)
{

    generateChunks();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50, 25);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Project");
    glutDisplayFunc(draw);
    // glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(passiveMotion);
    init();
    glutMainLoop();
    return 0;
}
