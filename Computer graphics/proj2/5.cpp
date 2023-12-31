#include <GL/glut.h>

int carX = 200, carY = 200; // Initial position of the car

void drawCar() {
    // Draw car body
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_POLYGON);
    glVertex2f(carX, carY);
    glVertex2f(carX + 50, carY);
    glVertex2f(carX + 50, carY + 30);
    glVertex2f(carX, carY + 30);
    glEnd();

    // Draw car roof (window)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(carX + 10, carY + 30);
    glVertex2f(carX + 40, carY + 30);
    glVertex2f(carX + 30, carY + 50);
    glVertex2f(carX + 20, carY + 50);
    glEnd();

    // Draw car tires
    glColor3f(0.0, 0.0, 0.0); // Black color
    // Left tire
    glBegin(GL_POLYGON);
    glVertex2f(carX + 10, carY);
    glVertex2f(carX + 15, carY);
    glVertex2f(carX + 15, carY - 10);
    glVertex2f(carX + 10, carY - 10);
    glEnd();
    // Right tire
    glBegin(GL_POLYGON);
    glVertex2f(carX + 35, carY);
    glVertex2f(carX + 40, carY);
    glVertex2f(carX + 40, carY - 10);
    glVertex2f(carX + 35, carY - 10);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawCar();

    glFlush();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            carY += 10; // Move the car up
            break;
        case GLUT_KEY_DOWN:
            carY -= 10; // Move the car down
            break;
        case GLUT_KEY_LEFT:
            carX -= 10; // Move the car left
            break;
        case GLUT_KEY_RIGHT:
            carX += 10; // Move the car right
            break;
    }

    glutPostRedisplay();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set clear color to white
    gluOrtho2D(0, 400, 0, 400); // Set the orthographic view
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Move the Car");
    glutInitWindowSize(400, 400);

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys); // Register the special keys callback

    glutMainLoop();
    return 0;
}
