// Lab_8.cpp : Defines the entry 2 triangle for the console application.
//

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);//clear white
	glShadeModel(GL_FLAT);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear color buffer
	glColor3f(0.0, 0.0, 0.0);//black
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);
		glVertex2i(50,50);				//v0
		glVertex2i(255, 50);			//v2
		glVertex2i(100, 150);			//v1
	
		glVertex2i(300, 100);			//v3
		glVertex2i(450, 150);			//v4
		glVertex2i(350, 250);			//v5
	glEnd();
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Point");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}