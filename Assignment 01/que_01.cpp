#include <GL/glut.h> // Include the GLUT library for OpenGL functions
#include <bits/stdc++.h> // Include standard C++ library headers
using namespace std;

// Display callback function
void displayCB(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Drawing the bottom most triangle (green)
    glColor3f(0, 1, 0);   // doing it for green color
    glBegin(GL_POLYGON);  // adding all the details of the polygon vertex 
                          // coordinates in counterclockwise direction
        glVertex2i(220, 260);
        glVertex2i(380, 260);
        glVertex2i(300, 390);
    glEnd();

    // Drawing the middle triangle (yellow)
    glColor3f(1, 1, 0);    // doing it for yellow color
    glBegin(GL_POLYGON);   // adding all the details of the polygon vertex 
                           // coordinates in counterclockwise direction 
        glVertex2i(220 + 10, 260 + 50);
        glVertex2i(380 - 10, 260 + 50);
        glVertex2i(300, 390 + 50);
    glEnd();

    // Drawing the top most triangle (cyan)
    glColor3f(0, 1, 1);  // doing it for cyan color
    glBegin(GL_POLYGON); // adding all the details of the polygon vertex 
                         // coordinates in counterclockwise direction
        glVertex2i(220 + 20, 260 + 100);
        glVertex2i(380 - 20, 260 + 100);
        glVertex2i(300, 390 + 80);
    glEnd();

    // Draw the wood base (rectangle) in brown color
    glColor3f(0.52, 0.35, 0.052); // doing it for brown color
    glBegin(GL_POLYGON);   // adding all the details of the polygon vertex 
                           // coordinates in counterclockwise direction
        glVertex2i(280, 60 + 40);
        glVertex2i(280, 260);
        glVertex2i(320, 260);
        glVertex2i(320, 60 + 40);
    glEnd();

    glFlush(); // Flush OpenGL buffers to display
}

// Main function
int main(int argc, char *argv[]) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Question_01 - Tree");

    // Set up the OpenGL environment
    glClearColor(1, 1, 1, 0.0); // Set the background color to white
    gluOrtho2D(0, 600, 0, 600); // Set up an orthographic projection

    // Register display callback function
    glutDisplayFunc(displayCB);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}

// code to compile the program 
// g++ que_01.cpp -o que_01 -lglut -lGLU - lGL

// code to run the program
// ./que_01
