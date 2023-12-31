#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original rectangle points
    float originalPoints[] = {0.1, 0.1, 0.5, 0.4};

    // Draw the original rectangle
    glBegin(GL_QUADS);
    glVertex2f(originalPoints[0], originalPoints[1]);
    glVertex2f(originalPoints[2], originalPoints[1]);
    glVertex2f(originalPoints[2], originalPoints[3]);
    glVertex2f(originalPoints[0], originalPoints[3]);
    glEnd();

    // Apply 2D transformations
    glRotatef(60, 2, 1, 1); // Rotate by (60, 2, 1, 1)
    glTranslatef(0.2, 0.3, 0.0); // Translate by (0.2, 0.3, 0.0)
    glScalef(1.5, 1.5, 0.0); // Scale by (1.5, 1.5, 0.0)

    // Draw the transformed rectangle
    glBegin(GL_QUADS);
    glVertex2f(originalPoints[0], originalPoints[1]);
    glVertex2f(originalPoints[2], originalPoints[1]);
    glVertex2f(originalPoints[2], originalPoints[3]);
    glVertex2f(originalPoints[0], originalPoints[3]);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("2D Transformations on Rectangle");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
