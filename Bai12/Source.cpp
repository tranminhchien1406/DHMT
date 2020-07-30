﻿// Lab_12.cpp : Defines the entry Yosora for the console application.
//
#include <math.h>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#define PI 3.13159265358976323846
#define STEPS 40				//số lượng hình nón trên hình tròn
#define MAX_STARS 300			//số lượng ngôi sao

const int screenWidth = 640;
const int screenHeight = 480;
//------------------------------//
typedef struct star				//structure of stars
{
	GLint x, y;
	GLint radius;
	GLint velocity;
	GLfloat intensity;
}STARS;
STARS sky[MAX_STARS];			//vùng chứa sao
//----------------------------//
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//clear black
}
void glCircle(GLint x, GLint y, GLint radius)
{
	GLfloat twicePi = (GLfloat) 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);					//tâm hình tròn
	for (int i = 0; i <= STEPS; i++)		//vẽ hình nón
	{
		glVertex2i((GLint)(x + (radius * cos(i * twicePi / STEPS)) + 0.5),
			(GLint)(y + (radius * sin(i * twicePi / STEPS)) + 0.5));
	}
	glEnd();
}
//--------------------------//
void skyInit()
{
	for (int i = 0; i < MAX_STARS; i++)
	{
		sky[i].x = rand() % screenWidth;
		sky[i].y = rand() % screenHeight;
		sky[i].radius = 1 + rand() % 3;
		sky[i].intensity = sky[i].radius / 3.0f;
		sky[i].velocity = sky[i].radius * 2 + rand() % 3;
	}
}
//-------------------------//
void skyDraw()					//code vẽ sao
{
	glClearColor(0, 0, 0, 0); // clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < MAX_STARS; i++)
	{
		glColor3f(sky[i].intensity, sky[i].intensity, sky[i].intensity);
		glCircle(sky[i].x, sky[i].y, sky[i].radius);
	}
}
//-------------------------//
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear the color buffer
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	skyDraw();
	glPopMatrix();
	glutSwapBuffers();

	glFlush();
}
//------------------------//
void update()
{
	for (int i = 0; i < MAX_STARS; i++)
	{
		sky[i].x += sky[i].velocity;
		if (sky[i].x >= screenWidth)
		{
			sky[i].x = 0;
			sky[i].y = rand() % screenHeight;
			sky[i].radius = 1 + rand() % 3;
			sky[i].intensity = sky[i].radius / 3.0f;
			sky[i].velocity = sky[i].radius * 2 + rand() % 3;
		}
	}
	Sleep(50);
	glutPostRedisplay();
}
//-----------------------//
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);//khởi tạo glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);//khởi tạo chế độ vẽ single buffer và hệ màu RGB
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);//tùy chọn khung màn hình
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(update);
	glutMainLoop();
	return 0;
}