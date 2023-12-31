#include <GL/glut.h>

void drawHouse() {
  // Define house colors
  const float roofColor[] = {0.7f, 0.3f, 0.1f};
  const float wallColor[] = {0.8f, 0.8f, 0.8f};
  const float doorColor[] = {0.6f, 0.4f, 0.2f};
  const float windowColor[] = {0.9f, 0.9f, 0.9f};

  // Draw walls (quads)
  glBegin(GL_QUADS);
    glColor3fv(wallColor);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
  glEnd();

  // Draw roof (triangle)
  glBegin(GL_TRIANGLES);
    glColor3fv(roofColor);
    glVertex2f(0.0f, 0.9f);
    glVertex2f(-0.5f, 0.5f);
    glVertex2f(0.5f, 0.5f);
  glEnd();

  // Draw door (rectangle)
  glBegin(GL_QUADS);
    glColor3fv(doorColor);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(-0.2f, 0.3f);
  glEnd();

  // Draw windows (smaller rectangles)
  glBegin(GL_QUADS);
    glColor3fv(windowColor);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glVertex2f(-0.3f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
  glEnd();
  glBegin(GL_QUADS);
    glColor3fv(windowColor);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.3f, 0.4f);
  glEnd();

  // Add details (lines, circles)
  glColor3f(0.0f, 0.0f, 0.0f);
  glBegin(GL_LINES);
    glVertex2f(-0.1f, 0.3f);
    glVertex2f(-0.1f, 0.0f);
  glEnd(); // Door handle
  glPushMatrix();
    glTranslatef(-0.04f, 0.15f, 0.0f);
    glutSolidSphere(0.02f, 10, 10); // Doorknob
  glPopMatrix();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawHouse();
  glutSwapBuffers();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutCreateWindow("My Cozy House");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
