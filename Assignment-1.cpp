#include <windows.h>
#include <iostream>
#include <stdlib.h> 
#include <GL/glut.h>
using namespace std;

void handleKeypress(unsigned char key, int x, int y) {  
	switch (key) {
	case 27:
		exit(0); 
	}
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	gluPerspective(45.0,                 
		(double)w / (double)h, 1.0,200.0);                
}


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	//Pentagon
	glBegin(GL_TRIANGLES); 
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.5f, 0.5f, -5.0f);
	glVertex3f(1.5f, 0.5f, -5.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(1.5f, 0.5f, -5.0f);
	glVertex3f(1.5f, 1.0f, -5.0f);
	glVertex3f(0.5f, 1.0f, -5.0f);
	glVertex3f(1.5f, 1.0f, -5.0f);
	glVertex3f(1.0f, 1.5f, -5.0f);
	glEnd(); 

//octagon 
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.51f, 0.37f, -5.0f); 
	glVertex3f(0.7f, 0.37f, -5.0f);  
	glVertex3f(0.83f, 0.23f, -5.0f); 
	glVertex3f(0.83f, 0.03f, -5.0f); 
	glVertex3f(0.7f, -0.09f, -5.0f); 
	glVertex3f(0.51f, -0.09f, -5.0f); 
	glVertex3f(0.38f, 0.03f, -5.0f); 
	glVertex3f(0.38f, 0.23f, -5.0f); 
	glEnd();

	//heptagon
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.95f, -0.31f, -5.0f);
	glVertex3f(1.15f, -0.42f, -5.0f);  
	glVertex3f(1.25f, -0.62f, -5.0f);
	glVertex3f(1.10f, -0.87f, -5.0f);
	glVertex3f(0.80f, -0.87f, -5.0f);
	glVertex3f(0.65f, -0.62f, -5.0f);
	glVertex3f(0.75f, -0.42f, -5.0f); 
	glEnd();

	//nonagon
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, .0f);
	glVertex3f(0.03f, 0.93f, -5.0f); 
	glVertex3f(0.24f, 0.81f, -5.0f);  
	glVertex3f(0.3f, 0.71f, -5.0f); 
	glVertex3f(0.28f, 0.58f, -5.0f); 
	glVertex3f(0.19f, 0.49f, -5.0f); 
	glVertex3f(-0.19f, 0.49f, -5.0f); 
	glVertex3f(-0.28f, 0.58f, -5.0f); 
	glVertex3f(-0.3f, 0.71f, -5.0f); 
	glVertex3f(-0.24f, 0.81f, -5.0f);
	glEnd();

	//Decagon
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-0.72f, 0.8f, -5.0f); 
	glVertex3f(-0.52f, 0.8f, -5.0f); 
	glVertex3f(-0.35f, 0.64f, -5.0f); 
	glVertex3f(-0.3f, 0.48f, -5.0f); 
	glVertex3f(-0.35f, 0.3f, -5.0f); 
	glVertex3f(-0.52f, 0.16f, -5.0f);
	glVertex3f(-0.72f, 0.16f, -5.0f); 
	glVertex3f(-0.9f, 0.3f, -5.0f); 
	glVertex3f(-0.95f, 0.48f, -5.0f); 
	glVertex3f(-0.9f, 0.64f, -5.0f); 
	glEnd();

	//hexagon
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-0.18f, -0.2f, -5.0f);
	glVertex3f(0.12f, -0.2f, -5.0f);
	glVertex3f(0.22f, -0.42f, -5.0f);
	glVertex3f(0.12f, -0.62f, -5.0f);
	glVertex3f(-0.18f, -0.62f, -5.0f);
	glVertex3f(-0.28f, -0.43f, -5.0f);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}
