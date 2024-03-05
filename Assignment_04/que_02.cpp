#include <GL/glut.h>
#include<GL/glu.h>
#include<bits/stdc++.h>
using namespace std;

// Write a program using glut library to draw the
// circle by implementing the following
// techniques:
// 1. Bresenham's algorithm
// code to run in terminal
// g++ que_01.cpp -o que_01 -lglut -lGLU -lGL

void Draw() 
{
    cout<<"Enter the radius\n";
    int radius;
    cin>>radius;

    cout<<"Enter the coordinates of the center\n";
    int x_center,y_center;
    cin>>x_center>>y_center;
    
    glClear(GL_COLOR_BUFFER_BIT); 
    vector<pair<int,int>> vp;

    int x_c= 0;
    int y_c = radius;

    int decision_par = 3 - 2*radius;

    while(x_c<=y_c){
         
         vp.push_back({x_c,y_c});
         if(decision_par<0){
            decision_par = decision_par + 4*x_c + 6;
         }
         else{
            decision_par = decision_par + 4*x_c - 4*y_c;
            y_c--;
         }
         x_c++;
    }

    glBegin(GL_POINTS);
    
    for(int i=0;i<vp.size();i++){
        int x = vp[i].first;
        int y = vp[i].second;

        glVertex2i(x+x_center,y+y_center);
        glVertex2i(-x+x_center,y+y_center);
        glVertex2i(-x+x_center,-y+y_center);
        glVertex2i(x+x_center,-y+y_center);

        glVertex2i(y+x_center,x+y_center);
        glVertex2i(-y+x_center,x+y_center);
        glVertex2i(-y+x_center,-x+y_center);
        glVertex2i(y+x_center,-x+y_center);

    }

    glEnd();

   glFlush();


}

void Initial() {
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0,0,0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 150, 0, 150);
}

int main(int C, char *V[]){
    glutInit(&C,V);
    glutInitDisplayMode(GLUT_RGB  | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham's algorithm");
    Initial();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
