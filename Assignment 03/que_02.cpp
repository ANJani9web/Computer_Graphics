#include <bits/stdc++.h>
using namespace std;
#include <GL/glut.h>
#include <cmath>

struct Point {
    float x, y;
};

vector<Point> points; // Vector to store points

void drawPoint(float x, float y) {
    glColor3f(0.0f, 1.0f, 0.0f); // green color
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void addPoint(float x, float y) {
    points.push_back({x, y});
}

void displayMe() {
    glClear(GL_COLOR_BUFFER_BIT);
    float xStart, yStart, xEnd, yEnd;
    xStart = 30;
    yStart = 40;
    xEnd = 70;
    yEnd = 70;
    float slope = (yEnd - yStart) / (xEnd - xStart);
    float deltaY = yEnd - yStart;
    float deltaX = xEnd - xStart;
    int steps;

    // First case m < 1
    if (slope < 1.0) {
        steps = xEnd - xStart;
        float x = xStart;
        float y = yStart;
        float decisionParam = 2 * deltaY - deltaX;

        addPoint(x, y);

        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2 * deltaY;
                x += 1;
            } else {
                decisionParam += 2 * deltaY - 2 * deltaX;
                x += 1;
                y += 1;
            }

            addPoint(x, y);
        }
    }
    // Second case m = 1
    if (slope == 1.0) {
        float x = xStart, y = yStart;

        addPoint(x, y);

        steps = xEnd - xStart;
        for (int add = 1; add <= steps; add++) {
            x += 1;
            y += 1;

            addPoint(x, y);
        }
    }
    // Third case m > 1
    if (slope > 1) {
        float x = xStart, y = yStart;
        addPoint(x, y);

        steps = yEnd - yStart;
        float decisionParam = 2 * deltaX - deltaY;
        for (int add = 1; add <= steps; add++) {
            if (decisionParam < 0) {
                decisionParam += 2 * deltaX;
                y += 1;
            } else {
                decisionParam += 2 * deltaX - 2 * deltaY;
                x += 1;
                y += 1;
            }

            addPoint(x, y);
        }
    }

    // Draw points from the vector
    for (const auto& point : points) {
        drawPoint(point.x, point.y);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Bresenham's Line Algorithm");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    gluOrtho2D(0, 100, 0, 100);             // 2D Orthographic projection

    glutDisplayFunc(displayMe);

    glutMainLoop();

    return 0;
}