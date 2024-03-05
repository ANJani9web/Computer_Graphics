#include <GL/glut.h>
#include <bits/stdc++.h>

GLfloat vertex[][2] = {{-10, 10}, {10, -10}, {10, 10}};
int n = 3; // Number of vertex in the polygon

void drawPolygon() {
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
        glVertex2fv(vertex[i]);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red color for the polygon
    drawPolygon();
    glFlush();
}

void translate(float dx, float dy) {
    for (int i = 0; i < n; i++) {
        vertex[i][0] += dx;
        vertex[i][1] += dy;
       // std::cout<<vertex[i][0]<<" "<<vertex[i][1]<<std::endl;
    }
    glutPostRedisplay();
}

void rotate(float angle) {
    float theta = angle * (3.14159 / 180.0);
    float tempX, tempY;
    for (int i = 0; i < n; i++) {
        tempX = vertex[i][0];
        tempY = vertex[i][1];
        vertex[i][0] = tempX * cos(theta) - tempY * sin(theta);
        vertex[i][1] = tempX * sin(theta) + tempY * cos(theta);
       // std::cout<<vertex[i][0]<<" "<<vertex[i][1]<<std::endl;
    }
    glutPostRedisplay();
}

void scale(float sx, float sy) {
    for (int i = 0; i < n; i++) {
        vertex[i][0] *= sx;
        vertex[i][1] *= sy;
        //std::cout<<vertex[i][0]<<" "<<vertex[i][1]<<std::endl;
    }
    glutPostRedisplay();
}

void shear(float shx, float shy) {
    for (int i = 0; i < n; i++) {
        vertex[i][0] += shx * vertex[i][1];
        vertex[i][1] += shy * vertex[i][0];
        //std::cout<<vertex[i][0]<<" "<<vertex[i][1]<<std::endl;
    }
    glutPostRedisplay();
}

void reflect() {
    for (int i = 0; i < n; i++)
        vertex[i][0] = -vertex[i][0];// y axis
        
    glutPostRedisplay();
}

void menu(int choice) {
    switch (choice) {
        case 1:
            translate(20, 20);
            break;
        case 2:
            rotate(120);
            break;
        case 3:
            scale(1.5, 1.5);
            break;
        case 4:
            shear(0.5, 0);
            break;
        case 5:
            reflect();
            break;
        case 6:
            exit(0);
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutCreateWindow("2D Transformations");
    gluOrtho2D(-50, 50, -50, 50);
    glutDisplayFunc(display);

    int submenu = glutCreateMenu(menu);
    glutAddMenuEntry("Translate", 1);
    glutAddMenuEntry("Rotate", 2);
    glutAddMenuEntry("Scale", 3);
    glutAddMenuEntry("Shear", 4);
    glutAddMenuEntry("Reflect", 5);

    glutCreateMenu(menu);
    glutAddSubMenu("Transformations", submenu);
    glutAddMenuEntry("Exit", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}