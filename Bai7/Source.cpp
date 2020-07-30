// Lab_7.cpp : Defines the entry Rectangle(colorful) for the console application.
//

#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"

const int screenWidth = 640;
const int screenHeight = 480;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//clear white
}
void drawRectangle(GLint x, GLint y, GLint width, GLint heigth)
{
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f);// đỉnh màu hồng
	glVertex2i(x, y);						//(trên, trái)  +------->
	glColor3f(0.0f, 1.0f, 1.0f);// đỉnh màu xanh dương
	glVertex2i(x + width, y);				//(trên, phải)	^		|
	glColor3f(1.0f, 1.0f, 0.0f);// đỉnh màu xanh vàng
	glVertex2i(x + width, y + heigth);		//(dưới, phải)	|		v
	glColor3f(1.0f, 1.0f, 1.0f);// đỉnh màu trắng
	glVertex2i(x, y + heigth);				//(dưới, trái)	+<------+
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);//Clears the color buffer

	GLint w = 400, h = 200;//chiều rộng = 400, chiều cao = 200

	GLint x = (screenWidth - w) / 2;// canh vào giữa màn hình
	GLint y = (screenHeight - h) / 2;//
	drawRectangle(x, y, w, h);

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