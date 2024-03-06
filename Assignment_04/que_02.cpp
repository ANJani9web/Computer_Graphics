#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

// Declare variables to store circle parameters
float x_cen, y_cen, radius;
vector<float> x_coor, y_coor;

// Display callback function to draw the circle
void displayCB() {
    // Initialize starting components and decision parameter
    float x_comp = 0, y_comp = radius;
    int decision_parameter = 1 - radius;

    // Add initial points to vectors
    x_coor.push_back(0);
    y_coor.push_back(radius);

    x_coor.push_back(0);
    y_coor.push_back(-radius);

    x_coor.push_back(-radius);
    y_coor.push_back(0);

    x_coor.push_back(radius);
    y_coor.push_back(0);
    
    // Mid-point circle algorithm
    while (x_comp != y_comp) {
        if (decision_parameter < 0) {
            decision_parameter += 2 * x_comp + 3;
            x_comp++;
        } else {
            decision_parameter += 2 * (x_comp - y_comp) + 5;
            y_comp--;
            x_comp++;
        }
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
    
    glFlush();
}

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
    glutCreateWindow("Mid-Point Circle Drawing Algorithm");
    
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
