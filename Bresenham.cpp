
#include <gl/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void myInit() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y1, int y2) 
{
	GLint x = x1,y = y1;
	GLint dx = x2-x1;
	GLint dy = y2-y1,dt = 2*(dy-dx),ds = 2*dy;
	int d = 2*dy-dx;
	draw_pixel(x,y);
	while(x<x2)
	{
		x++;
		if(d<0)
		{
			d = d+ds;
		}
		else
		{
			y++;
			d=d+dt;
		}
		draw_pixel(x,y);
	}

}

void myDisplay() {
	draw_line(x1, x2, y1, y2);
	glFlush();
}

void main(int argc, char **argv) {

	printf( "Enter (x1, y1, x2, y2)\n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line ");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}