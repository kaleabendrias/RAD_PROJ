#include <GL/glut.h>

float red = 1.0f, green = 1.0f, blue = 1.0f; // Initial color is white

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(red, green, blue); // Set the current color
    glVertex2f(0.0, 1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawTriangle();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'r':
        case 'R':
            red = 1.0f;
            green = 0.0f;
            blue = 0.0f;
            break;
        case 'g':
        case 'G':
            red = 0.0f;
            green = 1.0f;
            blue = 0.0f;
            break;
        case 'b':
        case 'B':
            red = 0.0f;
            green = 0.0f;
            blue = 1.0f;
            break;
    }
    glutPostRedisplay(); //used to request a redraw of the window to reflect the color changes.
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Colorful Triangle");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}
