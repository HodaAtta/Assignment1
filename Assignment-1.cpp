#include <windows.h>
#include <iostream>
#include <stdlib.h> 
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <math.h>
#endif
#define M_PI   3.14159265358979323846264338327950288

using namespace std;

void handleKeypress(unsigned char key, 
                    int x, int y) {    
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
                   (double)w / (double)h, 
                   1.0,                  
                   200.0);                
}


void drawScene() {
    //Clear information from last draw
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); 
   	glLoadIdentity();

   //Pentagon
   			 glBegin(GL_TRIANGLES); 
		   	    glColor3f(0.3f, 0.3f, 0.3f);
		    	glVertex3f(0.5f, 0.5f, -5.0f);
		    	glVertex3f(1.5f, 0.5f, -5.0f);
		    	glVertex3f(0.5f, 1.0f, -5.0f);
		    	glVertex3f(0.5f, 1.0f, -5.0f);
		  	 	glVertex3f(1.5f, 0.5f, -5.0f);
		   	    glVertex3f(1.5f, 1.0f, -5.0f);
		  	    glVertex3f(0.5f, 1.0f, -5.0f);
		  	    glVertex3f(1.5f, 1.0f, -5.0f);
		   	    glVertex3f(1.0f, 1.5f, -5.0f);

   		   glEnd(); //End triangle coordinates

//octagon 
 			glBegin(GL_POLYGON);
                glColor3f(0.3f, 0.3f, 0.3f);
                glVertex3f(0.51f, 0.77f, 0.0f); //f
                glVertex3f(0.7f,  0.77f, 0.0f);  //g
                glVertex3f(0.83f, 0.63f, 0.0f); //h
                glVertex3f(0.83f, 0.43f, 0.0f); //i
                glVertex3f(0.7f,  0.29f, 0.0f); //j
                glVertex3f(0.51f, 0.29f, 0.0f); //k
                glVertex3f(0.38f, 0.43f, 0.0f); //m
                glVertex3f(0.38f, 0.63f, 0.0f); //n

 			 glEnd();

     //heptagon
            glBegin(GL_POLYGON);
                glColor3f(0.3f, 0.3f, 0.3f);
                glVertex3f(0.65f, -0.11f, 0.0f); 
                glVertex3f(0.85f, -0.22f,0.0f);  
                glVertex3f(0.95f, -0.42f, 0.0f); 
                glVertex3f(0.80f, -0.67f, 0.0f); 
                glVertex3f(0.50f, -0.67f, 0.0f); 
                glVertex3f(0.35f, -0.42f, 0.0f); 
                glVertex3f(0.45f, -0.22f, 0.0f);
            glEnd();

 //nonagon
            glBegin(GL_POLYGON);
                glColor3f(0.3f, 0.3f, 0.3f);
                glVertex3f(0.0f,0.66f, 0.0f); 
                glVertex3f(0.14f, 0.6f,0.0f);  
                glVertex3f(0.2f, 0.5f, 0.0f); 
                glVertex3f(0.18f, 0.37f, 0.0f); 
                glVertex3f(0.09f, 0.28f, 0.0f); 
                glVertex3f(-0.09f, 0.28f, 0.0f); 
                glVertex3f(-0.18f, 0.37f, 0.0f); 
                glVertex3f(-0.2f, 0.5f, 0.0f); 
                glVertex3f(-0.14f, 0.6f, 0.0f); 
            glEnd();

                //Decagon
                glBegin(GL_POLYGON);
                glColor3f(0.3f, 0.3f, 0.3f);
                glVertex3f(-0.72f,0.8f, 0.0f); 
                glVertex3f(-0.52f,   0.8f,0.0f);  
                glVertex3f(-0.35f,   0.64f, 0.0f);
                glVertex3f(-0.3f,   0.48f, 0.0f);
                glVertex3f(-0.35f,   0.3f, 0.0f); 
                glVertex3f(-0.52f, 0.16f, 0.0f); 
                glVertex3f(-0.72f, 0.16f, 0.0f); 
                glVertex3f(-0.9f, 0.3f, 0.0f); 
                glVertex3f(-0.95f, 0.48f, 0.0f); 
                glVertex3f(-0.9f, 0.64f, 0.0f); 
            glEnd();

 //hexagon
            glBegin(GL_POLYGON);
                glColor3f(0.3f, 0.3f, 0.3f);
                glVertex3f(-0.18f, -0.2f, 0.0f);
                glVertex3f(0.12f,   -0.2f,0.0f);
                glVertex3f(0.22f,   -0.42f, 0.0f);
                glVertex3f(0.12f,   -0.62f, 0.0f);
                glVertex3f(-0.18f,   -0.62f, 0.0f);
                glVertex3f(-0.28f, -0.43f, 0.0f);
            glEnd();



            glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400); //Set the window size

    //Create the window
    glutCreateWindow("Basic Shapes - videotutorialsrock.com");
    initRendering(); //Initialize rendering

     //Set handler functions for drawing, keypresses, and window resizes
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);

        glutMainLoop();
    return 0;
}