#include <GL/glut.h>
#include<bits/stdc++.h> // Standard C++ library headers
using namespace std;

int x_coor, y_coor; // Variables to store the coordinates of the bottom-most left vertex of the rectangle
int length, breadth; // Variables to store the length and breadth of the rectangle
int x_mov, y_mov; // Variables to store the movement in x-direction and y-direction after clicking on the key

// Display callback function
void displayCB()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw a colored polygon
    glColor3f(0.4, 0.6, 0.4);  // Set color to a shade of green
    glBegin(GL_POLYGON);
    glVertex2f(x_coor, y_coor);
    glVertex2f(x_coor + breadth, y_coor);
    glVertex2f(x_coor + breadth, y_coor + length);
    glVertex2f(x_coor, y_coor + length);
    glEnd();

    glFlush(); // Flush OpenGL buffers to display
}

// Function to handle special keyboard key events
void Keys(int key, int x, int y)
{   
    // Move the rectangle based on the keys pressed
    if(key == 101){ // Up arrow key
        y_coor += y_mov;
    }
    if(key == 100){ // Left arrow key
        x_coor -= x_mov;
    }
    if(key == 103){ // Down arrow key
        y_coor -= y_mov;
    }
    if(key == 102){ // Right arrow key
        x_coor += x_mov;
    }

    // Ensure that the rectangle stays within the window boundaries
    if(x_coor < 0) x_coor = 0;
    if(x_coor + breadth > 600) x_coor = 600-breadth;
    if(y_coor < 0) y_coor = 0;
    if(y_coor + length > 600) y_coor = 600 - length;

    glutPostRedisplay();  // Request a redraw to update the display
}

// Main function
int main(int argc, char *argv[])
{   
    // Input the coordinates, length, breadth, and movement from the user
    cout<<"Enter the coordinates of bottom-most left vertex of the Rectangle\n";
    cout<<"X coor: ";
    cin>>x_coor;
    cout<<"Y coor: ";
    cin>>y_coor;

    cout<<"Enter the length and breadth of the rectangle"<<endl;
    cout<<"Length: ";
    cin>>length;
    cout<<"Breadth: ";
    cin>>breadth;
    
    cout<<"Enter the movement in x-direction and y-direction after clicking on the key\n";
    cout<<"X-direction movement: ";
    cin>>x_mov;
    cout<<"Y-direction movement: ";
    cin>>y_mov;

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Question_01 - Colored Polygon Shifting");

    // Set up the OpenGL environment
    glClearColor(1, 1, 1, 0.0); // Set clear color to white
    gluOrtho2D(0, 600, 0, 600); // Set up a 2D orthographic projection

    // Register the display callback function and the special keys callback function
    glutDisplayFunc(displayCB);
    glutSpecialFunc(Keys);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0; // Return 0 to exit main function
}

// void Initial() {
//     glClearColor(1.0, 1.0, 1.0, 0);
//     glColor3f(1,0,1);
//     glPointSize(7.0);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, 100, 0, 100);
// }

// int main(int C, char *V[]){
//     glutInit(&C,V);
//     glutInitDisplayMode(GLUT_RGB  | GLUT_SINGLE);
//     glutInitWindowSize(600,600);
//     glutInitWindowPosition(0,0);

//     glutCreateWindow("DDA Line Drawing");
//     Initial();
//     glutDisplayFunc(Draw);
//     glutMainLoop();
//     return 0;
// }
