﻿// Lab_4.cpp : Defines the entry triangle(colorful) for the console application.
//

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//clear white
}
void triangle()
{
	//Tô màu flat
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);//màu đỏ
		glVertex2i(160, 80);
		glColor3f(0.0, 1.0, 0.0);//màu xanh
		glVertex2i(480, 80);
		glColor3f(0.0, 0.0, 1.0);//màu lục
		glVertex2i(320, 400);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear the color buffer
	triangle();

	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
	glMatrixMode(GL_MODELVIEW);
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
	glutMainLoop();
	return 0;
}