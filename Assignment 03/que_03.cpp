// // // draw a line joining two end points given by the user by implementing mid point algorithm
// // do not declare the points as global variables and do not use built in functions for drawing the line

// // use the following algorithm
// // 1. input the two end points of the line
// // 2. calculate dx and dy
// // 3. calculate steps
// // 4. calculate xincrement and yincrement
// // 5. put pixel (x,y)
// // 6. repeat steps 5 and 6 until x=x2 and y=y2
// // 7. end

// #include <iostream>
// #include <GL/glut.h>

// using namespace std;

// // Structure to hold a point (x, y)
// struct Point {
//     int x;
//     int y;
// };

// // Function to draw a line using Midpoint algorithm
// void drawLine(Point p1, Point p2) {
//     int dx = p2.x - p1.x;
//     int dy = p2.y - p1.y;
//     int d = 2 * dy - dx;
//     int incrE = 2 * dy;
//     int incrNE = 2 * (dy - dx);
//     int x = p1.x;
//     int y = p1.y;

//     glBegin(GL_POINTS);
//     glVertex2i(x, y);
//     while (x < p2.x) {
//         if (d <= 0) {
//             d += incrE;
//             x++;
//         } else {
//             d += incrNE;
//             x++;
//             y++;
//         }
//         glVertex2i(x, y);
//     }
//     glEnd();
//     glFlush();
// }

// // Function to handle drawing
// void display() {
//     Point p1, p2;

//     // Input two endpoints
//     cout << "Enter endpoint 1 (x1, y1): ";
//     cin >> p1.x >> p1.y;

//     cout << "Enter endpoint 2 (x2, y2): ";
//     cin >> p2.x >> p2.y;

//     // Set the color of the line to green
//     glColor3f(0.0, 1.0, 0.0);

//     // Draw the line
//     drawLine(p1, p2);
// }

// int main(int argc, char** argv) {
//     // Initialize GLUT
//     glutInit(&argc, argv);

//     // Set display mode
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

//     // Set window size and position
//     glutInitWindowSize(500, 500);
//     glutInitWindowPosition(100, 100);

//     // Create window with a title
//     glutCreateWindow("Midpoint Line Drawing");

//     // Set the display function
//     glutDisplayFunc(display);

//     // Set the color for clearing the window
//     glClearColor(1.0, 1.0, 1.0, 0.0);

//     // Set the viewport
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, 500, 0, 500);

//     // Start the main loop
//     glutMainLoop();

//     return 0;
// }

//Midpoint algorithm for line drawing 

// if slope is less than 1 then 
// we declare a variable d i.e., is dy - (dx/2)
// if d < 0 , d ==> d + dy and x++,y
// else d ==> d + dy - dx, x++,y++



// for slope grater than 1 then
// d will be dx - (dy/2)
// if d < 0, d ==> d + dx and y++, x
// else d ==> d + dx - dy, x++, y++



#include <GL/glut.h>
#include<GL/glu.h>
#include<bits/stdc++.h>
using namespace std;

void MidPoint(int x1,int y1,int x2,int y2){

    //slope
    float m = (float)(y2 - y1)/(float)(x2 - x1);

    int dx = x2-x1, dy = y2-y1;

    if(abs(m) <= 1){
        float d = (float)dy - (float)dx/(float)2;
        float X = x1,Y = y1;
        glColor3f(0.0f, 1.0f, 0.0f); // green color
        glBegin(GL_POINTS);
            glVertex2f(round(X),round(Y));
        glEnd();
        for(int i=0;i<abs(dx);i++){
            if(d < 0){
                d = d + dy;
                X = X + 1;
                Y = Y;
                glColor3f(0.0f, 1.0f, 0.0f); // green color
                glBegin(GL_POINTS);
                    glVertex2f(round(X),round(Y));
                glEnd();
            }else{
                d = d + dy - dx;
                X = X + 1;
                Y = Y + 1;
                glColor3f(0.0f, 1.0f, 0.0f); // green color
                glBegin(GL_POINTS);
                    glVertex2f(round(X),round(Y));
                glEnd();
            }
        }

    }else{
        float d = (float)dx - (float)dy/(float)2;
        float X = x1,Y = y1;
        glColor3f(0.0f, 1.0f, 0.0f); // green color
        glBegin(GL_POINTS);
            glVertex2f(round(X),round(Y));
        glEnd();
        for(int i=0;i<abs(dy);i++){
            if(d < 0){
                d = d + dx;
                Y = Y + 1;
                X = X;
                glColor3f(0.0f, 1.0f, 0.0f); // green color
                glBegin(GL_POINTS);
                    glVertex2f(round(X),round(Y));
                glEnd();
            }else{
                d = d + dx - dy;
                X = X + 1;
                Y = Y + 1;
                glColor3f(0.0f, 1.0f, 0.0f); // green color
                glBegin(GL_POINTS);
                    glVertex2f(round(X),round(Y));
                glEnd();
            }
        }

    }
    glFlush();

}

void Draw() {
    float x1,y1,x2,y2; 
    x1=30;
    y1=40;
    x2=70;
    y2=70;
    MidPoint(x1,y1,x2,y2);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("MidPoint Line Drawing Algorithm");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    gluOrtho2D(0, 100, 0, 100);     // 2D Orthographic projection

    glutDisplayFunc(Draw);

    glutMainLoop();

    return 0;
}