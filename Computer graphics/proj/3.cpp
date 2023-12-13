#include <GL/glut.h>

void drawCar() {
  // Define car body color
  glColor3f(0.8f, 0.2f, 0.0f);

  // Draw car body (rectangle)
  glBegin(GL_QUADS);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(-0.5f, -0.3f);
  glEnd();

  // Draw headlights (circles)
  glColor3f(1.0f, 1.0f, 1.0f);
  glPushMatrix();
    glTranslatef(-0.3f, 0.2f, 0.0f);
    glutSolidSphere(0.1f, 10, 10);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.3f, 0.2f, 0.0f);
    glutSolidSphere(0.1f, 10, 10);
  glPopMatrix();

  // Draw wheels (circles with smaller circles inside)
  glColor3f(0.0f, 0.0f, 0.0f);
  glPushMatrix();
    glTranslatef(-0.4f, -0.2f, 0.0f);
    glutSolidSphere(0.15f, 10, 10);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.1f, 10, 10);
  glPopMatrix();
  glPushMatrix();
    glTranslatef(0.4f, -0.2f, 0.0f);
    glutSolidSphere(0.15f, 10, 10);
    glColor3f(1.0f, 1.0f, 1.0f);
    glutSolidSphere(0.1f, 10, 10);
  glPopMatrix();

  // Draw windows (triangles)
  glColor3f(0.0f, 0.5f, 1.0f);
  glBegin(GL_TRIANGLES);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.1f, 0.3f);
  glEnd();
  glBegin(GL_TRIANGLES);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(0.4f, 0.1f);
    glVertex2f(0.3f, 0.3f);
  glEnd();
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
