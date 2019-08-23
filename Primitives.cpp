#include <GL/glut.h>

void init()
{
	glClearColor (0.0, 0.0, 0.0, 1.0);

	glColor3f(1.0, 1.0, 1.0); 

	glMatrixMode (GL_PROJECTION);    
	glLoadIdentity ();    
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  
}


void mydisplay1(){
	glClear(GL_COLOR_BUFFER_BIT); 
	glPointSize (20);
	glBegin(GL_POINTS); 
		glVertex2f( 0.1,0.2);
		glVertex2f( 0.2, 0.2 );
		glVertex2f(0.3, 0.2);
		glVertex2f( 0.4, 0.2 );
		
		glVertex2f( 0.5, 0.2 );
		glVertex2f( 0.6, 0.2);
	glEnd();
	glFlush(); 
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple");     
	glutDisplayFunc(mydisplay1);  
	init();  
	glutMainLoop();
}
