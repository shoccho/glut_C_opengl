#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

struct point
{
    float x;
    float y;
};
struct line
{
    point start;
    point end;
};
struct tbrl
{
    std::string start;
    std::string end;
};
bool clipped = false;

std::vector<line> lines;
std::vector<tbrl> tbrls;
std::vector<line> cliped_lines;
point clip_area[2];
int ortho = 10;
point Max, Min;

void init()
{
    glClearColor(1, 1, 1, 1);
    glOrtho(-ortho, ortho, -ortho, ortho, -1.0, 1.0);
}
void drawGraphs()
{
    int orthox = 10;
    int orthoy = 10;
    glColor4d(0, 0, 0, .01);
    glBegin(GL_LINES);
    for (int i = -orthoy; i <= orthoy; i++)
    {
        glVertex2d(orthox, i);
        glVertex2d(-orthox, i);
    }
    for (int i = -orthox; i <= orthox; i++)
    {
        glVertex2d(i, orthoy);
        glVertex2d(i, -orthoy);
    }
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glEnd();
    glLineWidth(2);
    glBegin(GL_LINES);

    glVertex2d(-orthox, 0);
    glVertex2d(orthox, 0);
    glVertex2d(0, orthoy);
    glVertex2d(0, -orthoy);
    glEnd();
}
void drawClipping()
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3d(0, 0, 1);
    glLineWidth(2);
    glRectf(clip_area[0].x, clip_area[0].y, clip_area[1].x, clip_area[1].y);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void addline()
{
    tbrls.clear();
    cliped_lines.clear();
    clipped = false;
    //enter a line points
    std::printf("enter the lines starting and ending points\n");
    line ab;
    std::scanf("%f %f", &ab.start.x, &ab.start.y);
    std::scanf("%f %f", &ab.end.x, &ab.end.y);
    lines.push_back(ab);
    glutPostRedisplay();
}
void gentbrls()
{
    tbrls.clear();
    for (auto line : lines)
    {
        tbrl point_codes;
        std::string code;
        if (line.start.y <= Max.y)
        {
            code.append("0");
        }
        else
        {
            code.append("1");
        }
        if (line.start.y >= Min.y)
        {
            code.append("0");
        }
        else
        {
            code.append("1");
        }

        if (line.start.x < Max.x)
        {
            code.append("0");
        }
        else
        {
            code.append("1");
        }
        if (line.start.x > Min.x)
        {
            code.append("0");
        }
        else
        {
            code.append("1");
        }
        point_codes.start = code;

        std::string ecode;
        if (line.end.y < Max.y)
        {
            ecode.append("0");
        }
        else
        {
            ecode.append("1");
        }
        if (line.end.y > Min.y)
        {
            ecode.append("0");
        }
        else
        {
            ecode.append("1");
        }

        if (line.end.x < Max.x)
        {
            ecode.append("0");
        }
        else
        {
            ecode.append("1");
        }
        if (line.end.x > Min.x)
        {
            ecode.append("0");
        }
        else
        {
            ecode.append("1");
        }

        point_codes.end = ecode;

        tbrls.push_back(point_codes);
    }
    for (auto i : tbrls)
    {
        std::cout << "start " << i.start << std::endl;
        std::cout << "end " << i.end << std::endl;
    }
}
void printline(line l)
{
    std::cout << "starting x " << l.start.x << " y " << l.start.y << std::endl;
    std::cout << "ending x " << l.end.x << " y " << l.end.y << std::endl;
}
void clip()
{
    gentbrls();
    cliped_lines.clear();
    int i = -1;
    for (auto itr : tbrls)
    {
        i++;
        line nl = lines[i];
        int ones = std::count(itr.start.begin(), itr.start.end(), '1');

        if (ones == 1)
        {
            // std::cout << "execution was here " << std::endl;
            if (itr.start.at(0) == '1')
                nl.start.y = std::min(lines[i].start.y, Max.y);
            if (itr.start.at(1) == '1')
                nl.start.y = std::max(lines[i].start.y, Min.y);
            if (itr.start.at(2) == '1')
                nl.start.x = std::min(lines[i].start.x, Max.x);
            if (itr.start.at(3) == '1')
            {
                nl.start.x = std::max(lines[i].start.x, Min.x);

                // std::cout << nl.start.x << std::endl;
            }
        }

        ones = std::count(itr.end.begin(), itr.end.end(), '1');
        if (ones == 1)
        {
            if (itr.end.at(0) == '1')
                nl.end.y = std::min(lines[i].end.y, Max.y);
            if (itr.end.at(1) == '1')
                nl.end.y = std::max(lines[i].end.y, Min.y);
            if (itr.end.at(2) == '1')
                nl.end.x = std::min(lines[i].end.x, Max.x);
            if (itr.end.at(3) == '1')
                nl.end.x = std::max(lines[i].end.x, Min.x);
        }

        printline(nl);
        cliped_lines.push_back(nl);
    }
}
void drawLines()
{
    glColor3d(1, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    for (auto line : lines)
    {
        glVertex2d(line.start.x, line.start.y);
        glVertex2d(line.end.x, line.end.y);
    }
    glEnd();
}
void drawClippedLines()
{
    glColor3d(1, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINES);
    for (auto line : cliped_lines)
    {
        glVertex2d(line.start.x, line.start.y);
        glVertex2d(line.end.x, line.end.y);
    }
    glEnd();
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(1);
    drawGraphs();
    drawClipping();
    if (clipped)
        drawClippedLines();
    else
        drawLines();
    glFlush();
}
void sp_key(int key, int x, int y)
{
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 't')
    {
        gentbrls();
    }
    if (key == 'a')
    {
        addline();
    }
    if (key == 'c')
    {
        if (clipped)
            clipped = false;
        else
        {
            cliped_lines.clear();
            std::cout << Max.x << " " << Max.y << std::endl;
            std::cout << Min.x << " " << Min.y << std::endl;
            clipped = true;
            clip();
            glutPostRedisplay();
        }
    }
}
void mouse(int button, int state, int x, int y)
{
}

int main(int argc, char **argv)
{
    // std::cout << "clipping area cords ";
    // //top left

    // std::scanf("%f %f", &clip_area[0].x, &clip_area[0].y);
    // //top right
    // std::scanf("%f %f", &clip_area[1].x, &clip_area[1].y);
    // //enter a line points
    // line ab;
    // std::scanf("%f %f", &ab.start.x, &ab.start.y);
    // std::scanf("%f %f", &ab.end.x, &ab.end.y);

    clip_area[0].x = -3;
    clip_area[0].y = 6;

    clip_area[1].x = 2;
    clip_area[1].y = 1;

    Max.x = std::max(clip_area[0].x, clip_area[1].x);
    Min.x = std::min(clip_area[0].x, clip_area[1].x);

    Max.y = std::max(clip_area[0].y, clip_area[1].y);
    Min.y = std::min(clip_area[0].y, clip_area[1].y);

    line ab;
    ab.start.x = -4;
    ab.start.y = 2;

    ab.end.x = -1;
    ab.end.y = 7;
    printline(ab);
    lines.push_back(ab);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Clipping");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(sp_key);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}