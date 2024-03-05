// // // draw a line joining two end points given by the user by implementing DDA(digital differential Analyzer)
// // // do not declare the points as global variables and do not use built in functions for drawing the line
// // // use the following algorithm
// // // 1. input the two end points of the line
// // // 2. calculate dx and dy
// // // 3. calculate steps
// // // 4. calculate xincrement and yincrement
// // // 5. put pixel (x,y)
// // // 6. repeat steps 5 and 6 until x=x2 and y=y2
// // // 7. end

// // #include <iostream>
// // #include <cmath>
// // #include <GL/glut.h>

// // using namespace std;

// // // Structure to hold a point (x, y)
// // struct Point {
// //     int x;
// //     int y;
// // };

// // // Function to draw a line using DDA algorithm
// // void drawLine(Point p1, Point p2) {
// //     // Calculate the differences between endpoints
// //     int dx = p2.x - p1.x;
// //     int dy = p2.y - p1.y;

// //     // Calculate steps required for generating pixels
// //     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

// //     if(dy>dx){
// //         steps = abs(dy);
// //         float xInc = dx / (float) steps;
// //         float yInc = 1;
// //         // Initialize starting point


// //     }
// //     float xInc = dx / (float) steps;
// //     float yInc = dy / (float) steps;

// //     // Initialize starting point
// //     float x = p1.x;
// //     float y = p1.y;

// //     // Begin drawing line
// //     glBegin(GL_POINTS);

// //     // Iterate over all the steps
// //     for (int i = 0; i <= steps; i++) {
// //         // Plot the point (x, y)
// //         glVertex2i(round(x), round(y));
        
// //         // Increment in x and y for the next step
// //         x += xInc;
// //         y += yInc;
// //     }

// //     glEnd();
// //     glFlush();
// // }

// // // Function to handle drawing
// // void display() {
// //     Point p1, p2;

// //     // Input two endpoints
// //     cout << "Enter endpoint 1 (x1, y1): ";
// //     cin >> p1.x >> p1.y;

// //     cout << "Enter endpoint 2 (x2, y2): ";
// //     cin >> p2.x >> p2.y;

// //     // Set the color of the line to red
// //     glColor3f(1.0, 0.0, 0.0);

// //     // Draw the line
// //     drawLine(p1, p2);
// // }

// // int main(int argc, char** argv) {
// //     // Initialize GLUT
// //     glutInit(&argc, argv);

// //     // Set display mode
// //     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

// //     // Set window size and position
// //     glutInitWindowSize(500, 500);
// //     glutInitWindowPosition(100, 100);

// //     // Create window with a title
// //     glutCreateWindow("DDA Line Drawing");

// //     // Set the display function
// //     glutDisplayFunc(display);

// //     // Set the color for clearing the window
// //     glClearColor(1.0, 1.0, 1.0, 0.0);

// //     // Set the viewport
// //     glMatrixMode(GL_PROJECTION);
// //     glLoadIdentity();
// //     gluOrtho2D(0, 100, 0, 100);

// //     // Start the main loop
// //     glutMainLoop();

// //     return 0;
// // }


// #include <GL/glut.h>
// #include<GL/glu.h>
// #include<bits/stdc++.h>
// using namespace std;


// void Draw() 
// {
//     int x1, y1, x2, y2; //starting and ending points of lines
//     x1 = 100;
//     y1 = 100;
//     x2 = 750;
//     y2 = 200;
//     // adjust the values to draw the diagram

//     glClear(GL_COLOR_BUFFER_BIT); 

// 	glPointSize(3);

//     // calculating dx, dy
//     int dx = x2-x1, dy = y2-y1;      

//     //for steps in ddl we take max steps possible direction
//     // means if dx is > dy we take dx steps
//     // otherwise we take dy steps
//     int steps = max(abs(dx), abs(dy));
//     //abs is absolute diff function and max is max of both

//     float m = (float)(dy)/(float)(dx);

//     //in dda algorithm we decide next point based on slope
//     //if |m| < 1 x -> x + 1 and y -> y + m
//     //if |m| > 1 x -> x + 1/m and y -> y + 1

//     //for writing programme we can obsorve 
//     //if dx > dy it means |m|<1 i.e steps = dx , x -> x + 1 == x -> x + dx/steps
//     //      y -> y + m == y -> y + (dy/dx) == y -> y + (dy/steps)
//     //if dx < dy it means |m|>1 i.e steps = dy , y -> y + 1 == y -> y + dy/steps (steps is max with dy,dx i.e., is dy)
//     //      x -> x + 1/m == x -> x + (dx/dy) == x -> x + (dx/steps)

//     //in total x -> x + (dx/steps) and y -> y + (dy/steps) will work for all cases

//     float Xinc = (float)(dx) / (float)(steps), Yinc = (float)(dy) / (float)(steps); 
//     // cout<<Xinc<<" "<<Yinc<<"\n";
//     float X = x1, Y = y1;
//     for(int i=0;i<=steps;i++)
//     {
//         glBegin(GL_POINTS);
//             glColor3f(1, 0, 0);
//             glVertex2f(round(X),round(Y)); //round function will make round of to near integers
//         glEnd();
//         // cout<<X<<" "<<Y<<"\n";
//         X = X + Xinc;
//         Y = Y + Yinc;
//     }
//     glFlush();
// }

// void Initial() {
//     glClearColor(1.0, 1.0, 1.0, 0);
//     glColor3f(1,0,1);
//     glPointSize(7.0);
//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     gluOrtho2D(0, 800, 0, 800);
// }

// int main(int C, char *V[]){
//     glutInit(&C,V);
//     glutInitDisplayMode(GLUT_RGB  | GLUT_SINGLE);
//     glutInitWindowSize(600,600);
//     glutInitWindowPosition(0,0);

//     glutCreateWindow("DDL Line Drawing");
//     Initial();
//     glutDisplayFunc(Draw);
//     glutMainLoop();
//     return 0;
// }


#include <GL/glut.h>
#include<GL/glu.h>
#include<bits/stdc++.h>
using namespace std;


void Draw() 
{
    int x1, y1, x2, y2; //starting and ending points of lines
    x1 = 30;
    y1 = 40;
    x2 = 70;
    y2 = 70;
    // adjust the values to draw the diagram

    glClear(GL_COLOR_BUFFER_BIT); 

	glPointSize(3);

    // calculating dx, dy
    int dx = x2-x1, dy = y2-y1;      

    //for steps in ddl we take max steps possible direction
    // means if dx is > dy we take dx steps
    // otherwise we take dy steps
    int steps = max(abs(dx), abs(dy));
    //abs is absolute diff function and max is max of both

    float m = (float)(dy)/(float)(dx);

    //in dda algorithm we decide next point based on slope
    //if |m| < 1 x -> x + 1 and y -> y + m
    //if |m| > 1 x -> x + 1/m and y -> y + 1

    //for writing programme we can obsorve 
    //if dx > dy it means |m|<1 i.e steps = dx , x -> x + 1 == x -> x + dx/steps
    //      y -> y + m == y -> y + (dy/dx) == y -> y + (dy/steps)
    //if dx < dy it means |m|>1 i.e steps = dy , y -> y + 1 == y -> y + dy/steps (steps is max with dy,dx i.e., is dy)
    //      x -> x + 1/m == x -> x + (dx/dy) == x -> x + (dx/steps)

    //in total x -> x + (dx/steps) and y -> y + (dy/steps) will work for all cases

    float Xinc = (float)(dx) / (float)(steps), Yinc = (float)(dy) / (float)(steps); 
    // cout<<Xinc<<" "<<Yinc<<"\n";
    float X = x1, Y = y1;
    for(int i=0;i<=steps;i++)
    {
        glBegin(GL_POINTS);
            glColor3f(1, 0, 0);
            glVertex2f(round(X),round(Y)); //round function will make round of to near integers
        glEnd();
        // cout<<X<<" "<<Y<<"\n";
        X = X + Xinc;
        Y = Y + Yinc;
    }
    glFlush();
}

void Initial() {
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(1,0,1);
    glPointSize(7.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}

int main(int C, char *V[]){
    glutInit(&C,V);
    glutInitDisplayMode(GLUT_RGB  | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);

    glutCreateWindow("DDA Line Drawing");
    Initial();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
