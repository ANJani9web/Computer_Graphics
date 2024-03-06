#include <GL/glut.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Structure to represent a point
struct Dot {
    int x, y;
    Dot(int a = 0, int b = 0) : x(a), y(b) {}
};

// Structure to represent a color in RGB
struct Shade {
    GLfloat red;
    GLfloat green;
    GLfloat blue;
};

// Vector to store points for drawing
vector<Dot> dots;

// Function to get the color of a pixel at given coordinates
Shade acquirePixelShade(GLint x, GLint y) {
    Shade shade;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &shade);
    return shade;
}

// Function to set the color of a pixel at given coordinates
void adjustPixelShade(GLint x, GLint y, Shade shade) {
    glColor3f(shade.red, shade.green, shade.blue);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

// Function to check if a neighboring pixel has the same color
bool confirmDirection(GLint x, GLint y, Shade oldShade, int dx, int dy) {
    Shade shade1 = acquirePixelShade(x + dx, y);
    Shade shade2 = acquirePixelShade(x, y + dy);
    return (shade1.red == oldShade.red && shade1.green == oldShade.green && shade1.blue == oldShade.blue) &&
           (shade2.red == oldShade.red && shade2.green == oldShade.green && shade2.blue == oldShade.blue);
}

// Flood fill algorithm to fill a bounded area with a new color
void performFloodFill(GLint x, GLint y, Shade oldShade, Shade newShade) {
    Shade shade = acquirePixelShade(x, y);

    // If the color at the given coordinates is different from the old color, fill it with the new color
    if (shade.red != oldShade.red && shade.green != oldShade.green && shade.blue != oldShade.blue) {
        adjustPixelShade(x, y, newShade);

        // Recursively fill adjacent pixels with the new color
        performFloodFill(x + 1, y, oldShade, newShade);
        performFloodFill(x, y + 1, oldShade, newShade);
        performFloodFill(x - 1, y, oldShade, newShade);
        performFloodFill(x, y - 1, oldShade, newShade);

        // Check diagonal pixels and fill them if they have the old color
        if (!confirmDirection(x, y, oldShade, 1, -1)) performFloodFill(x + 1, y - 1, oldShade, newShade);
        if (!confirmDirection(x, y, oldShade, 1, 1)) performFloodFill(x + 1, y + 1, oldShade, newShade);
        if (!confirmDirection(x, y, oldShade, -1, 1)) performFloodFill(x - 1, y + 1, oldShade, newShade);
        if (!confirmDirection(x, y, oldShade, -1, -1)) performFloodFill(x - 1, y - 1, oldShade, newShade);
    }
}

// Function to draw a circle using Bresenham's algorithm
void drawCircle(int x, int y, int radius) {
    int X = 0, Y = radius;
    int d = 3 - 2 * radius;
    while (X <= Y) {
        dots.push_back(Dot(X, Y));
        dots.push_back(Dot(Y, X));
        dots.push_back(Dot(-X, Y));
        dots.push_back(Dot(-Y, X));
        dots.push_back(Dot(X, -Y));
        dots.push_back(Dot(Y, -X));
        dots.push_back(Dot(-X, -Y));
        dots.push_back(Dot(-Y, -X));

        if (d < 0) {
            d = d + 4 * X + 6;
        } else {
            d = d + 4 * (X - Y) + 10;
            Y--;
        }
        X++;
    }

    glBegin(GL_POINTS);
    for (auto dot : dots) {
        glVertex2f(round(dot.x + x), round(dot.y + y));
    }
    glEnd();
}

// Function to draw a line using Bresenham's algorithm
void drawLine(int x1, int x2, int y1, int y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float incx, incy;

    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    incx = (x2 < x1) ? -1 : 1;
    incy = (y2 < y1) ? -1 : 1;

    float x = x1, y = y1;
    glBegin(GL_POINTS);

    if (dx > dy) {
        float e = 2 * dy - dx;
        for (int i = 0; i < dx; i++) {
            dots.push_back(Dot(round(x), round(y)));
            if (e >= 0) {
                y += incy;
                e += 2 * (dy - dx);
            } else {
                e += 2 * dy;
            }
            x += incx;
        }
    } else {
        float e = 2 * dx - dy;
        for (int i = 0; i < dy; i++) {
            dots.push_back(Dot(round(x), round(y)));
            if (e >= 0) {
                x += incx;
                e += 2 * (dx - dy);
            } else {
                e += 2 * dx;
            }
            y += incy;
        }
    }
    glEnd();
}

// Function to handle the display
void displayCB() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCircle(210, 240, 30);
    drawCircle(410, 240, 30);
    drawLine(110, 510, 310, 310);
    drawLine(110, 180, 240, 240);
    drawLine(240, 380, 240, 240);
    drawLine(440, 510, 240, 240);
    drawLine(510, 510, 240, 310);
    drawLine(110, 110, 240, 310);
    drawLine(210, 240, 310, 360);
    drawLine(240, 380, 360, 360);
    drawLine(380, 410, 360, 310);
    drawLine(410, 210, 310, 310);

    glBegin(GL_POINTS);
    for (int i = 0; i < dots.size(); i++) {
        glVertex2f(dots[i].x, dots[i].y);
    }
    glEnd();
    glFlush();

    // Define colors
    Shade newShade = {1.0f, 0.95f, 0.85f}; // Cream color
    Shade oldShade = {1.0f, 1.0f, 1.0f};   // White color
    performFloodFill(310, 280, oldShade, newShade);

    Shade newShade1 = {0.0f, 1.0f, 0.0f};  // Green color
    performFloodFill(210, 240, oldShade, newShade1);
    performFloodFill(410, 240, oldShade, newShade1);

    Shade newShade2 = {0.0f, 0.0f, 0.8f};   // Dark blue color
    performFloodFill(260, 335, oldShade, newShade2);

    glFlush();
}

// Main function
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Drawing the Car");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);

    glutDisplayFunc(displayCB);
    glutMainLoop();
    return 0;
}
