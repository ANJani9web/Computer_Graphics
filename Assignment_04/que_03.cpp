#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

// Declare variables to store circle parameters
float x_cen, y_cen, radius;
vector<float> x_coor, y_coor;

// Display callback function to draw the circle using DDA algorithm
void displayCB() {
    // Iterate through angles to generate circle points
    for (float angle = 0.0; angle <= 0.80; angle = angle + 0.01) {
        // Calculate components using trigonometric functions
        float x_comp = radius * cos(angle);
        float y_comp = radius * sin(angle);

        // Add points based on symmetry
        x_coor.push_back(x_comp);
        y_coor.push_back(y_comp);

        x_coor.push_back(y_comp);
        y_coor.push_back(x_comp);

        x_coor.push_back(-y_comp);
        y_coor.push_back(x_comp);
        
        x_coor.push_back(-x_comp);
        y_coor.push_back(y_comp);

        x_coor.push_back(-x_comp);
        y_coor.push_back(-y_comp);

        x_coor.push_back(-y_comp);
        y_coor.push_back(-x_comp);

        x_coor.push_back(y_comp);
        y_coor.push_back(-x_comp);

        x_coor.push_back(x_comp);
        y_coor.push_back(-y_comp);
    }

    // Plot the calculated points
    for (int i = 0; i < x_coor.size(); i++) {
         glBegin(GL_POINTS);
             glVertex2f(x_cen + x_coor[i], y_cen + y_coor[i]);
         glEnd();
    }
    
    // Flush the drawing commands
    glFlush();
}

// Main function
int main(int argc, char** argv) {
    // Prompt user to enter circle parameters
    cout << "Enter the coordinates of the Center: \n";
    cout << "Enter the x-coordinate: ";
    cin >> x_cen;
    cout << "Enter the y-coordinate: ";
    cin >> y_cen;

    cout << "Enter the radius of the circle: ";
    cin >> radius;

    // Initialize OpenGL and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("DDA Circle Drawing Algorithm");
    
    // Set OpenGL properties
    glClearColor(1, 1, 1, 0.0);
    glColor3f(1, 0, 0);
    glPointSize(3.0);
    gluOrtho2D(0, 100, 0, 100);

    // Register the display callback function
    glutDisplayFunc(displayCB);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}
