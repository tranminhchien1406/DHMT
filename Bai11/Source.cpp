// Lab_10.cpp : Defines the entry circle(color) for the console application.
//
#include <math.h>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#define PI 3.13159265358976323846
#define STEPS 40

const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//clear black
	glShadeModel(GL_FLAT);
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
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//clear the color buffer
	GLfloat red = 1.0f;			//thêm giá trị R G B
	GLfloat green = 1.0f;
	GLfloat blue = 1.0f;

	for (int r = 200; r > 0; r -= 30)	 //vẽ từ lớn tới nhỏ
	{
		glColor3f(red, green, blue);
		glCircle(320, 240, r);
		red -= 0.1f;
		green -= 0.2f;
		blue -= 0.3f;
	}
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