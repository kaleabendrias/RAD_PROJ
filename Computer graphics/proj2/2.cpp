#include <GL/glut.h>
#include <stdlib.h>

int shapeToDraw = 1; // 0: None, 1: Line, 2: Triangle, 3: Rectangle

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (shapeToDraw) {
        case 1:
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_LINES);
            glVertex2f(-0.5, -0.5);
            glVertex2f(0.5, 0.5);
            glEnd();
            break;
        case 2:
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_TRIANGLES);
            glVertex2f(-0.5, -0.5);
            glVertex2f(0.5, -0.5);
            glVertex2f(0.0, 0.5);
            glEnd();
            break;
        case 3:
            glColor3f(0.0, 0.0, 0.0);
            glBegin(GL_QUADS);
            glVertex2f(-0.5, -0.5);
            glVertex2f(0.5, -0.5);
            glVertex2f(0.5, 0.5);
            glVertex2f(-0.5, 0.5);
            glEnd();
            break;
    }

    glFlush();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_F1:
            shapeToDraw = 1; // Line
            break;
        case GLUT_KEY_F2:
            shapeToDraw = 2; // Triangle
            break;
        case GLUT_KEY_F3:
            shapeToDraw = 3; // Rectangle
            break;
    }
    glutPostRedisplay(); // Request a redraw to reflect the changes
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Set display mode
    glutInitWindowSize(400, 400);
    glutCreateWindow("Draw Shapes"); // Create a window with the title "Draw Shapes"
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    glutDisplayFunc(display); // Register the display callback function
    glutSpecialFunc(specialKeys); // Register the special keys callback function
    glutMainLoop(); // Enter the GLUT event processing loop
    return 0;
}
