#include <GL/glut.h>

int x_coor = 200;
int y_coor = 300;

void displayCB(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a colored polygon
    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.4, 0.2);  // color
    glVertex2i(x_coor, y_coor);
    glVertex2i(x_coor + 50, y_coor);
    glVertex2i(x_coor + 30, y_coor + 150);
    glVertex2i(x_coor + 80 , y_coor + 150);
    glEnd();

    glFlush();
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        y_coor += 10;
        break;
    case GLUT_KEY_DOWN:
        y_coor -= 20;
        break;
    case GLUT_KEY_LEFT:
        x_coor -= 30;
        break;
    case GLUT_KEY_RIGHT:
        x_coor += 40;
        break;
    }

    if(x_coor<0) x_coor = 0;
    if(x_coor>600) x_coor = 600;
    if(y_coor<0) y_coor = 0;
    if(y_coor>600) y_coor = 600;

    glutPostRedisplay();  // Request a redraw to update the display
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Colored Polygon Shifting");

    glClearColor(1, 1, 1, 0.0);
    gluOrtho2D(0, 600, 0, 600);
    glutDisplayFunc(displayCB);
    glutSpecialFunc(specialKeys);  // Register the special keys callback

    glutMainLoop();

    return 0;
}
