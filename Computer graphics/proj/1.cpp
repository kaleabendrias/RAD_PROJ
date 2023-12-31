#include <GL/glut.h>

void display() {
   glClear(GL_COLOR_BUFFER_BIT);

   // Draw a point
   glBegin(GL_POINTS);
   glVertex2f(0.0, 0.0);
   glEnd();

   // Draw a line
   // glBegin(GL_LINES);
   // glVertex2f(-0.5, 0.0);
   // glVertex2f(0.5, -0.5);
   // glEnd();

   // Draw a triangle
   // glBegin(GL_TRIANGLES);
   // glVertex2f(-0.5, -0.5);
   // glVertex2f(0.5, -0.5);
   // glVertex2f(0.0, 0.5);
   // glEnd();

   // Draw a rectangle
   // glBegin(GL_QUADS);
   // glVertex2f(-0.5, -0.5);
   // glVertex2f(-0.5, 0.5);
   // glVertex2f(0.5, 0.5);
   // glVertex2f(0.5, -0.5);
   // glEnd();

   // Draw a polygon
   // glBegin(GL_POLYGON);
   // glVertex2f(-0.5, -0.5);
   // glVertex2f(-0.25, 0.25);
   // glVertex2f(0.25, 0.25);
   // glVertex2f(0.5, -0.5);
   // glVertex2f(0.0, -0.75);
   // glEnd();

   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutCreateWindow("Graphical Primitives");
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
