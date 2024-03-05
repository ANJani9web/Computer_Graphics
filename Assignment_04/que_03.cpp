#include <GL/glut.h>
#include <cmath>
#include<bits/stdc++.h>
using namespace std;
// Function to draw a circle using DDA algorithm
// float h, k;
void drawCircle(float radius) {
    float x, y;
    int h,k;
    cout<<"Enter x_coor :"<<endl;
    cin>>h;

    cout<<"Enter y_coor :"<<endl;
    cin>>k;

    float step = 1.00; // Step size for DDA algorithm

    glBegin(GL_POINTS);

    for (float theta = 0; theta <= 45; theta += step) {
       

        x = radius * cos(theta);
        y = radius * sin(theta);

        // Plot the points in each octant
        glVertex2i(round(h+x), round(y+k));
        glVertex2i(round(-x+h), round(y+k));
        glVertex2i(round(x+h), round(-y+k));
        glVertex2i(round(-x+h), round(-y+k));
        glVertex2i(round(y+h), round(x+k));
        glVertex2i(round(-y+h), round(x+k));
        glVertex2i(round(y+h), round(-x+k));
        glVertex2i(round(-y+h), round(-x+k));
    }

    glEnd();
}

// Function to set up the OpenGL environment
void init() {
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0,0,0);
    glPointSize(2.0);
    gluOrtho2D(0.0,150.0,0.0,150.0); // Set the clipping window
}

// Function to handle all drawings
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw a circle with radius 50 using DDA algorithm
    drawCircle(30);

    glFlush(); // Flush the buffer
}

int main(int argc, char** argv) {
    // int h,k;
    // cin>>h>>k;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DDA Circle Drawing Algorithm");

    init(); // Initialize the OpenGL environment

    glutDisplayFunc(display); // Register the display function

    glutMainLoop(); // Enter the GLUT event processing loop

    return 0;
}
