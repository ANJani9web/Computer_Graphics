#include <GL/gl.h>
#include <bits/stdc++.h> // Standard C++ library headers
#include <GL/glut.h>
#include <GL/glu.h>
using namespace std;

// Display callback function
void displayCB(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Drawing the lower rectangular part (blue)
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        glVertex2i(40, 640);
        glVertex2i(40, 40);
        glVertex2i(760, 40);
        glVertex2i(760, 640);
    glEnd();

    // Drawing the rectangular door part (green)
    glColor3f(0, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2i(300, 560);
        glVertex2i(300, 60);
        glVertex2i(500, 60);
        glVertex2i(500, 560);
    glEnd();

    // Drawing the left square window (yellow)
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2i(80, 560);
        glVertex2i(80, 360);
        glVertex2i(280, 360);
        glVertex2i(280, 560);
    glEnd();

    // Drawing the right square window (yellow)
    glColor3f(1, 1, 0);
    glBegin(GL_POLYGON);
        glVertex2i(520, 560);
        glVertex2i(520, 360);
        glVertex2i(720, 360);
        glVertex2i(720, 560);
    glEnd();

    // Drawing the rectangular knob of the gate (brown)
    glColor3f(0.1, 0.35, 0.05);
    glBegin(GL_POLYGON);
        glVertex2i(330, 340);
        glVertex2i(330, 325);
        glVertex2i(345, 325);
        glVertex2i(345, 340);
    glEnd();

    // Drawing the upper triangular part (red)
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(400, 760);
        glVertex2i(10, 640);
        glVertex2i(790, 640);
    glEnd();

    glFlush(); // Flush OpenGL buffers to display
}

// Main function
int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB); // Set display mode to RGB
    glutInitWindowSize(800, 800); // Set initial window size
    glutCreateWindow("Question_02 - House"); // Create window with a title

    glClearColor(1, 1, 1, 1); // Set the clear color to white
    gluOrtho2D(0, 800, 0, 800); // Set up an orthographic projection

    glutDisplayFunc(displayCB); // Register display callback function
    glutMainLoop(); // Enter the GLUT event processing loop

    return 0;
}
