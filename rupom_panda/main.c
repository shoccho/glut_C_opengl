
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void draw_circle(float x, float y, float radius)
{
    // glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    // glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);

    double angle1 = 0.0;
    glVertex2d(radius * cos(0.0), radius * sin(0.0));
    int i;
    for (i = 0; i < circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius * sin(angle1));
        angle1 += angle;
    }
    glEnd();
    glPopMatrix();
}

void drawEars()
{

    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(142, 107);
    glVertex2d(122, 87);
    glVertex2d(107, 81);
    glVertex2d(106, 81);
    glVertex2d(71, 87);
    glVertex2d(57, 112);
    glVertex2d(63, 136);
    glVertex2d(87, 143);
    glVertex2d(113, 147);
    glVertex2d(113, 146);
    glVertex2d(114, 145);
    glVertex2d(115, 144);
    glVertex2d(116, 143);
    glVertex2d(116, 142);
    glVertex2d(147, 113);

    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(294, 97);
    glVertex2d(312, 74);
    glVertex2d(340, 65);
    glVertex2d(341, 65);
    glVertex2d(372, 75);
    glVertex2d(385, 92);
    glVertex2d(385, 110);
    glVertex2d(367, 124);
    glVertex2d(332, 129);
    glVertex2d(293, 102);

    glEnd();
}
void drawEyes()
{

    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(208, 134);
    glVertex2d(180, 132);
    glVertex2d(144, 151);
    glVertex2d(122, 185);
    glVertex2d(132, 213);
    glVertex2d(158, 219);
    glVertex2d(190, 206);
    glVertex2d(205, 178);
    glVertex2d(214, 149);
    glVertex2d(214, 148);
    glVertex2d(210, 133);
    glVertex2d(207, 133);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(260, 162);
    glVertex2d(283, 196);
    glVertex2d(302, 206);
    glVertex2d(338, 204);
    glVertex2d(351, 193);
    glVertex2d(352, 192);
    glVertex2d(352, 174);
    glVertex2d(338, 156);
    glVertex2d(337, 154);
    glVertex2d(317, 136);
    glVertex2d(296, 128);
    glVertex2d(261, 125);
    glVertex2d(250, 132);
    glVertex2d(249, 138);
    glVertex2d(255, 153);
    glVertex2d(261, 165);
    glEnd();

    glColor3d(1, 1, 1);
    draw_circle(180, 185, 18);
    draw_circle(300, 185, 18);
    glColor3d(0, 0, 0);
    draw_circle(180, 185, 10);
    draw_circle(300, 185, 10);
    glColor3d(1, 1, 1);
    draw_circle(175, 180, 5);
    draw_circle(295, 180, 5);
}
void drawNose()
{
    glColor3d(0, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2d(214, 197);
    glVertex2d(263, 193);
    glVertex2d(241, 210);
    glEnd();
}
void drawFace()
{
    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2d(225, 69);
    glVertex2d(195, 79);
    glVertex2d(193, 79);
    glVertex2d(156, 94);
    glVertex2d(118, 123);
    glVertex2d(118, 124);
    glVertex2d(93, 153);
    glVertex2d(74, 185);
    glVertex2d(67, 205);
    glVertex2d(66, 229);
    glVertex2d(93, 249);
    glVertex2d(132, 261);
    glVertex2d(181, 265);
    glVertex2d(289, 260);
    glVertex2d(290, 260);
    glVertex2d(292, 260);
    glVertex2d(346, 252);
    glVertex2d(398, 225);
    glVertex2d(407, 197);
    glVertex2d(406, 176);
    glVertex2d(356, 122);
    glVertex2d(306, 92);
    glVertex2d(256, 80);
    glVertex2d(265, 71);
    glVertex2d(232, 77);
    glVertex2d(245, 67);
    glVertex2d(205, 75);
    glEnd();

    glColor3d(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(243, 225);
    glVertex2d(267, 212);
    glVertex2d(248, 231);
    glVertex2d(239, 231);
    glVertex2d(214, 225);
    glVertex2d(242, 226);
    glEnd();
}
void drawLegs()
{

    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);

    glVertex2d(151, 439);
    glVertex2d(139, 448);
    glVertex2d(138, 456);
    glVertex2d(210, 456);
    glVertex2d(205, 443);
    glVertex2d(227, 417);
    glVertex2d(160, 411);
    glVertex2d(113, 393);
    glVertex2d(92, 378);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(315, 438);
    glVertex2d(329, 446);
    glVertex2d(329, 454);
    glVertex2d(265, 455);
    glVertex2d(266, 441);
    glVertex2d(266, 440);
    glVertex2d(247, 416);
    glVertex2d(308, 414);
    glVertex2d(307, 414);
    glVertex2d(308, 413);
    glVertex2d(309, 413);
    glVertex2d(375, 377);
    glVertex2d(368, 395);
    glVertex2d(353, 413);
    glVertex2d(326, 432);
    glVertex2d(311, 434);
    glEnd();
}

void drawBody()
{
    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);

    glVertex2d(117, 260);
    glVertex2d(99, 272);
    glVertex2d(56, 319);
    glVertex2d(43, 353);
    glVertex2d(47, 374);
    glVertex2d(59, 386);
    glVertex2d(92, 387);
    glVertex2d(94, 386);
    glVertex2d(376, 379);
    glVertex2d(408, 385);
    glVertex2d(422, 374);
    glVertex2d(424, 347);
    glVertex2d(413, 320);
    glVertex2d(391, 293);
    glVertex2d(357, 263);
    glVertex2d(355, 263);
    glVertex2d(354, 263);
    glVertex2d(353, 262);
    glVertex2d(341, 254);
    glVertex2d(235, 263);
    glVertex2d(120, 259);

    glEnd();

    glColor3d(1, 1, 1);
    glBegin(GL_POLYGON);

    glVertex2d(92, 309);
    glVertex2d(86, 339);
    glVertex2d(86, 362);
    glVertex2d(87, 377);
    glVertex2d(122, 399);
    glVertex2d(169, 415);
    glVertex2d(296, 416);
    glVertex2d(361, 392);
    glVertex2d(362, 391);
    glVertex2d(381, 375);
    glVertex2d(385, 341);
    glVertex2d(379, 311);
    glVertex2d(292, 283);
    glVertex2d(194, 283);
    glVertex2d(125, 296);
    glVertex2d(103, 303);

    glEnd();
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    drawEars();
    drawFace();
    drawBody();
    drawLegs();

    drawEyes();
    drawNose();
    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
    glOrtho(0.0, 500.0, 500.0, 0, -1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Panda");
    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0; /* ANSI C requires main to return int. */
}
