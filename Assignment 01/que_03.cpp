#include<GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

// Function to draw a circle using center and radius
void Circle(float a, float b, float radius) {
    GLfloat xi, yi, angle = 0;

    // Draw points around the circle using trigonometry
    for (int i = 1 ; i <= 6500 ; i++) {
        angle = i * 0.001;
        xi = a + radius * cos(angle);
        yi = b + radius * sin(angle);
        glBegin(GL_POINTS);
        glColor3f(0, 0, 0); // Set color to black
        glVertex2f(xi, yi); // Draw the point
        glEnd();
    }
    glFlush(); // Flush OpenGL buffers to display
}

// Display callback function
void displayCB(){
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glColor3f(1, 0, 1); // Set color to magenta
    glPointSize(2.0); // Set point size to 2.0
    glLineWidth(2.0); // Set line width to 2.0
    
    // Drawing the body of the cycle using lines
    glBegin(GL_LINES);
        glVertex2f(130, 150);
        glVertex2f(300, 150);
        glVertex2f(300, 150);
        glVertex2f(300, 400);
        glVertex2f(300, 400);
        glVertex2f(470, 400);
        glVertex2f(470, 400);
        glVertex2f(470, 150);
        glVertex2f(130, 150);
        glVertex2f(300, 400);
        glVertex2f(300, 150);
        glVertex2f(470, 400);
    glEnd();

    // Draw back wheel
    Circle(130, 150, 100);

    // Draw front wheel
    Circle(470, 150, 100);

    // Drawing the seat
    glColor3f(0, 0, 0); // Set color to black
    glBegin(GL_POLYGON);
        glVertex2f(270, 400);
        glVertex2f(330, 400);
        glVertex2f(330, 445);
        glVertex2f(270, 430);
    glEnd();

    // Drawing the handle
    glColor3f(0, 0, 1); // Set color to blue
    glBegin(GL_LINES);
        glVertex2f(430, 440);
        glVertex2f(510, 360);

        glVertex2f(430, 440);
        glVertex2f(450, 460);

        glVertex2f(510, 360);
        glVertex2f(530, 380);
    glEnd();

    glFlush(); // Flush OpenGL buffers to display
}

// Main function
int main(int argc, char *argv[]) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB); // Set display mode to RGB
    glutInitWindowPosition(0, 0); // Set initial window position
    glutInitWindowSize(600, 600); // Set initial window size
    glutCreateWindow("Question_03 - Cycle"); // Create window with a title

    glClearColor(1, 1, 1, 0.0); // Set clear color to white
    gluOrtho2D(0, 600, 0, 600); // Set up an orthographic projection

    glutDisplayFunc(displayCB); // Register display callback function
    glutMainLoop(); // Enter the GLUT event processing loop

    return 0; // Return 0 to exit main function
}
