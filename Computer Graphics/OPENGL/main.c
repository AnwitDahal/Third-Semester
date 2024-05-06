// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<GL/glut.h> 

// function to initialize 
void myInit (void) 
{ 
	// making background color black as first 
	// 3 arguments all are 0.0 
	glClearColor(0.0,1, 0.0, 0.0); 
	
	// making picture color red (in RGB mode), as middle argument is 1.0 
	glColor3f(1.0, 0.0, 0.0); 
	
	// breadth of picture boundary is 1 pixel brav
	glPointSize(1.0); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	
	// setting window dimension in X- and Y- direction 
	gluOrtho2D(-780, 780, -420, 420); 
} 

void display (void) 
{ 
	glClear(GL_COLOR_BUFFER_BIT); 
	glBegin(GL_TRIANGLES);
		glVertex2i(100,100);
		glVertex2i(50,200);
		glVertex2i(150,200); 
	glEnd(); 
	glFlush(); 
} 

int main (int argc, char** argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
	
	// giving window size in X- and Y- direction 
	glutInitWindowSize(1366, 768); 
	glutInitWindowPosition(0, 0); 
	
	// Giving name to window 
	glutCreateWindow("Triangle Drawing"); 
	myInit(); 
	
	glutDisplayFunc(display); 
	glutMainLoop(); 
} 

