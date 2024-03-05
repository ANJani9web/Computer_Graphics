#include <GL/glut.h>
#include<bits/stdc++.h> // Standard C++ library headers
using namespace std;

// Global variables to store the coordinates of the bottom-most left vertex of the rectangle
int x_coor, y_coor;

// Global variables to store the length and breadth of the rectangle
int length, breadth;

// Global variables to store the RGB components of the color
float red = 1, blue = 0, green = 1;

// Display callback function
void displayCB(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw a colored polygon with the specified color
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    glVertex2f(x_coor, y_coor);
    glVertex2f(x_coor + breadth, y_coor);
    glVertex2f(x_coor + breadth, y_coor + length);
    glVertex2f(x_coor, y_coor + length);
    glEnd();

    glFlush(); // Flush OpenGL buffers to display
}

// Mouse click callback function
void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // Change color to a random one on left-click
        red = (GLfloat)rand() / RAND_MAX;
        green = (GLfloat)rand() / RAND_MAX;
        blue = (GLfloat)rand() / RAND_MAX;
        glutPostRedisplay(); // Request a redraw to update the display
    }
}

int main(int argc, char *argv[])
{
    // Input the coordinates, length, breadth, and movement from the user
    cout << "Enter the coordinates of bottom-most left vertex of the Rectangle\n";
    cout << "X coor: ";
    cin >> x_coor;
    cout << "Y coor: ";
    cin >> y_coor;

    cout << "Enter the length and breadth of the rectangle" << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Breadth: ";
    cin >> breadth;

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Question_02 - Color Changing of the Polygon");

    // Set up the OpenGL environment
    glClearColor(1, 1, 1, 0.0); // Set clear color to white
    gluOrtho2D(0, 600, 0, 600); // Set up a 2D orthographic projection

    // Register the display callback function and the mouse click callback function
    glutDisplayFunc(displayCB);
    glutMouseFunc(mouseClick);

    glutMainLoop();

    return 0;
}
