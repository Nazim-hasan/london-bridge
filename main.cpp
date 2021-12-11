#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <conio.h>


float tp3=0;
float moveShip = 50.0f;
void circle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)
{
    int i;
    float rad = 0;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i = 0; i<=360; i++)
    {
        rad = i*(3.1416/180);
        glVertex2f(x+rx*cos(rad),y+ry*sin(rad));
    }
    glEnd();
}

/*void Move(int value) {

moveShip -= 1;

if(moveShip == -60)

{

 return;    //stops for bridge and wait for commands
}


if(moveShip < -300)

{

 moveShip = 50;

}

glutPostRedisplay();
glutTimerFunc(20, Move, 0);
}*/

void AfterBreak() {

//moveShip= -91;
moveShip -= 0.1;

if(moveShip == -60)

{

 return;    //stops for bridge and wait for commands
}
if(moveShip < -300)

{

 moveShip = 50;

}
glutPostRedisplay();
}


void make_cloud(int x, int y)
{
glColor3f(1.0, 1.0, 1.0);
circle(10,10,x,y);
circle(10,10,x+10,y);
circle(10,10,x+30,y);
circle(10,10,x+5,y-10);
circle(10,10,x+20,y-10);
circle(10,10,x+5,y+10);
circle(10,10,x+20,y+10);
}

void cloud_move_right(GLfloat t)
{
tp3=tp3+t;
if(tp3>1000)
tp3 = 0;
glutPostRedisplay();
}
void cloud()
{
glPushMatrix();
glTranslatef(tp3,0,0);
make_cloud(0,520);
/*
make_cloud(-500,280);
make_cloud(-200,250);
make_cloud(-400,250);
make_cloud(200,250);
make_cloud(-100,250);
make_cloud(-350,230);
*/
glPopMatrix();
cloud_move_right(.1);
glEnd();
}


void background()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 191, 255);
    glVertex2f(0, 600);
    glVertex2f(0, 300);
    glVertex2f(1000, 300);
    glVertex2f(1000, 600);

    glBegin(GL_QUADS);
    glColor3ub(107, 142, 35);
    glVertex2f(0, 300);
    glVertex2f(0, 0);
    glVertex2f(1000,0);
    glVertex2f(1000, 300);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(65, 105, 225);
    glVertex2f(425, 300);
    glVertex2f(100, 0);
    glVertex2f(900, 0);
    glVertex2f(575, 300);

    glEnd();
}


void megh()
{


    circle(13,4,78,71);
    circle(13,4,75,67);
    circle(13,4,78,62);
    circle(13,4,80,65);
}

void ship()
{
    glPushMatrix();
    glTranslatef(0.0f,moveShip,0.0f);
    glBegin(GL_POLYGON);    //Dec starts from here
    glColor3ub(231,232,234);  //1st floor
    glVertex2f(470.0f, 315.0f);
    glVertex2f(530.0f, 315.0f);
    glVertex2f(530.0f, 288.0f);
    glVertex2f(470.0f, 288.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(214,215,219);  //1st floor (middle ware)
    glVertex2f(465.0f, 315.0f);
    glVertex2f(535.0f, 315.0f);
    glVertex2f(535.0f, 320.0f);
    glVertex2f(465.0f, 320.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(231,232,234);  //second  floor
    glVertex2f(470.0f, 315.0f);
    glVertex2f(530.0f, 315.0f);
    glVertex2f(530.0f, 288.0f);
    glVertex2f(470.0f, 288.0f);
    glEnd();

    //boat front
    //left side
    glBegin(GL_POLYGON);
    glColor3ub(12,87,118);
    glVertex2f(500.0f, 308.0f);
    glVertex2f(465.0f, 285.0f);
    glVertex2f(473.0f, 232.0f);
    glVertex2f(500.0f, 223.0f);
    glEnd();
    //right side
    glBegin(GL_POLYGON);
    glColor3ub(5,71,95);
    glVertex2f(500.0f, 308.0f);
    glVertex2f(535.0f, 285.0f);
    glVertex2f(527.0f, 232.0f);
    glVertex2f(500.0f, 223.0f);
    glEnd();

    //Bottom red border
    glBegin(GL_POLYGON);
    glColor3ub(203,33,42);
    glVertex2f(473.0f, 232.0f);
    glVertex2f(500.0f, 223.0f);
    glVertex2f(500.0f, 227.0f);
    glVertex2f(473.0f, 236.0f);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(203,33,42);
    glVertex2f(527.0f, 232.0f);
    glVertex2f(500.0f, 223.0f);
    glVertex2f(500.0f, 227.0f);
    glVertex2f(527.0f, 236.0f);
    glEnd();

    glPopMatrix();
}
void display()
{
    glClearColor(0.00,0.00, 0.00, 1.00); // Set background color to black and opaque

    glClear(GL_COLOR_BUFFER_BIT);
    background();
    cloud();
    ship();
    glFlush();

}


void handleKeypress(unsigned char key, int x, int y) {
switch (key) {
case 'p':
    glutIdleFunc(AfterBreak);
    break;
//case 'e':
  //  glutIdleFunc(NULL);
  //  break;

}
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Traffic Signal");
    gluOrtho2D(0.0,1000.0,0.0,600.0);
    glutDisplayFunc(display);
    //glutTimerFunc(20,Move,0);

    glutKeyboardFunc(handleKeypress);
    glutMainLoop();

    return 0;

}


