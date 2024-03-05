#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
// float x1, x2, y1, y2;
struct point{
    int x,y;
    point(int a=0,int b=0){
        x=a,y=b;
    }
};
struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}
bool checkrightdown(GLint x, GLint y ,Color oldColor){
    Color color1;
	color1 = getPixelColor(x+1, y);
    Color color2;
	color2 = getPixelColor(x, y-1);
    int ct=0;
    if(color1.r == oldColor.r && color1.g == oldColor.g && color1.b == oldColor.b){
        ct++;
    }
    if(color2.r == oldColor.r && color2.g == oldColor.g && color2.b == oldColor.b){
        ct++;
    }
    return ct==2;
    
}
bool checkrightup(GLint x, GLint y ,Color oldColor){
    Color color1;
	color1 = getPixelColor(x+1, y);
    Color color2;
	color2 = getPixelColor(x, y+1);
    int ct=0;
    if(color1.r == oldColor.r && color1.g == oldColor.g && color1.b == oldColor.b){
        ct++;
    }
    if(color2.r == oldColor.r && color2.g == oldColor.g && color2.b == oldColor.b){
        ct++;
    }
    return ct==2;
    
}
bool checkleftup(GLint x, GLint y ,Color oldColor){
    Color color1;
	color1 = getPixelColor(x, y+1);
    Color color2;
	color2 = getPixelColor(x-1, y);
    int ct=0;
    if(color1.r == oldColor.r && color1.g == oldColor.g && color1.b == oldColor.b){
        ct++;
    }
    if(color2.r == oldColor.r && color2.g == oldColor.g && color2.b == oldColor.b){
        ct++;
    }
    return ct==2;
    
}
bool checkleftdown(GLint x, GLint y ,Color oldColor){
    Color color1;
	color1 = getPixelColor(x-1, y);
    Color color2;
	color2 = getPixelColor(x, y-1);
    int ct=0;
    if(color1.r == oldColor.r && color1.g == oldColor.g && color1.b == oldColor.b){
        ct++;
    }
    if(color2.r == oldColor.r && color2.g == oldColor.g && color2.b == oldColor.b){
        ct++;
    }
    return ct==2;
    
}
void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);
    
	if(color.r != oldColor.r && color.g != oldColor.g && color.b != oldColor.b)
	{ 

		setPixelColor(x, y, newColor);

		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
        // if(!checkrightdown(x,y,oldColor)){
        // floodFill(x+1, y-1, oldColor, newColor);
        // }
        // if(!checkrightup(x,y,oldColor)){
        // floodFill(x+1, y+1, oldColor, newColor);
        // }
        
	    // if(!checkleftup(x,y,oldColor)){
		// floodFill(x-1, y+1, oldColor, newColor);
        // }
        // if(!checkleftdown(x,y,oldColor)){
		// floodFill(x-1, y-1, oldColor, newColor);
        // }
	}
	return;
}
vector<point> points;

void Breshens(int x1,int y1,int r)
{
    
    int X = 0, Y = r;
    int d = 3 - 2*r;
    while(X <= Y)
    {
        points.push_back(point(X,Y));
        points.push_back(point(Y,X));
        points.push_back(point(-1*X,Y));
        points.push_back(point(-1*Y,X));
        points.push_back(point(X,-1*Y));
        points.push_back(point(Y,-1*X));
        points.push_back(point(-1*X,-1*Y));
        points.push_back(point(-1*Y,-1*X));

        if(d < 0)
        {
            d = d + 4*X + 6;
            X++;
        }
        else
        {
            d = d + 4*(X-Y) + 10;
            X++;
            Y--;
        }
    }
    
    
    glBegin(GL_POINTS);
    for(auto i : points){
      
        glVertex2f(round(i.x + x1),round(i.y + y1));
    }
    glEnd();
 

}


void draw_line(int x1, int x2, int y1, int y2) {
	float dx, dy, i, e;
	float incx, incy, inc1, inc2;
	float x,y;
    glBegin(GL_POINTS);
	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		 glVertex2f(round(x), round(y));  
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			 glVertex2f(round(x), round(y));  
		}

	} else {
		 glVertex2f(round(x), round(y));  
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			 glVertex2f(round(x), round(y));  
		}
	}
    glEnd();
}

void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    Breshens(200,230,30);
    Breshens(400,230,30);
	draw_line(100,500,300,300);
    draw_line(100,170,230,230);
    draw_line(230,370,230,230);
    draw_line(430,500,230,230);
    draw_line(500,500,230,300);
    draw_line(100,100,230,300);
    draw_line(200,230,300,350);
    draw_line(230,370,350,350);
    draw_line(370,400,350,300);
    draw_line(400,200,300,300);
   
   
	Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {1.0f, 1.0f, 1.0f};

	floodFill(300, 270, oldColor, newColor);
    Color newColor1={0.0f, 1.0f, 0.0f};
    floodFill(200, 230, oldColor, newColor1);
    floodFill(400, 230, oldColor, newColor1);
    Color newColor2={1.0f, 1.0f, 1.0f};
    floodFill(250, 325, oldColor, newColor2);
	glFlush();
}

void myInit (void) {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 600.0, 0.0, 600.0);
}

int main(int argc, char ** argv) {



  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(600, 600);
//   glutInitWindowPosition(100, 150);
  glutCreateWindow("");
  myInit ();
  glutDisplayFunc(myDisplay);
  glutMainLoop();
}