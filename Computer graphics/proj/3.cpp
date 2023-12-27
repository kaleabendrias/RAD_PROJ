#include <GL/glut.h>

void drawCar() {
  // Define car body color
  glColor3f(0.8f, 0.2f, 0.0f);

  // Draw car body (rectangle)
  glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(-0.5f, -0.5f);
  glEnd();

// front part of the car
  glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.25);
    glVertex2f(-0.8, 0.25);
    glVertex2d(-0.8, -0.5);
    glVertex2d(-0.5, -0.5);
  glEnd();

// trunk
  glBegin(GL_QUADS);
    glVertex2d(0.5, 0.25);
    glVertex2d(0.8, 0.25);
    glVertex2d(0.8, -0.5);
    glVertex2d(0.5, -0.5);
  glEnd();

// front window
  glColor3f(0.0f, 0.5f, 1.0f);
  glBegin(GL_QUADS);
    glVertex2d(0, 0.4);
    glVertex2d(0.4, 0.4);
    glVertex2d(0.4, 0.25);
    glVertex2d(0, 0.25);
  glEnd();

// back window
  glColor3f(0.0f, 0.5f, 1.0f);
  glBegin(GL_QUADS);
    glVertex2d(-0.1, 0.4);
    glVertex2d(-0.4, 0.4);
    glVertex2d(-0.4, 0.25);
    glVertex2d(-0.1, 0.25);
  glEnd();
 
  // Draw wheels (circles with smaller circles inside)
  glPushMatrix(); // This saves the current matrix on the stack.
    glTranslatef(-0.5f, -0.5f, 0.4f); //This translates the current matrix by the specified amount in the x, y, and z directions.
    glutSolidSphere(0.35f, 10, 10); // This draws a solid sphere with the specified radius and number of slices and stacks.
    glColor3f(1.0f, 1.0f, 1.0f); // This sets the current color to white.
    glutSolidSphere(0.1f, 10, 10); // This draws a smaller solid sphere with the specified radius and number of slices and stacks inside the larger sphere.
  glPopMatrix(); // This restores the current matrix from the stack.
  glPushMatrix();
    glTranslatef(0.5f, -0.5f, 0.4f);
    glutSolidSphere(0.35f, 10, 10);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.1f, 10, 10);
  glPopMatrix();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawCar();
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutCreateWindow("My Cute Car");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
