// Lab_5.cpp : Defines the entry square for the console application.
//

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//clear white
}
void drawSquare(GLint x, GLint y, GLint a)
{
	glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x+a, y);
		glVertex2i(x+a, y+a);
		glVertex2i(x, y+a);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//Clears the color buffer

	GLint size = 200;//độ dài cạnh = 200
	GLint x = (screenWidth - size) / 2;// canh vào giữa theo x
	GLint y = (screenHeight - size) / 2;//canh vào giữa theo y
	drawSquare(x, y, size);

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