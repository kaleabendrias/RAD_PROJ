#include <GL/glut.h>
#include <vector>

int startX, startY, endX, endY;
bool isDrawing = false;
std::vector<std::pair<int, int>> lines; // Vector to store line segments, like a list of int

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw all stored line segments
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (const auto& line : lines) {
        glVertex2f(line.first, line.second);
    }
    glEnd();

    // Draw the current line being drawn
    if (isDrawing) {
        glBegin(GL_LINES);
        glVertex2f(startX, startY);
        glVertex2f(endX, endY);
        glEnd();
    }

    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        startX = endX = x;
        startY = endY = glutGet(GLUT_WINDOW_HEIGHT) - y;  // Invert Y-coordinate
        isDrawing = true;
    } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        endX = x;
        endY = glutGet(GLUT_WINDOW_HEIGHT) - y;  // Invert Y-coordinate
        isDrawing = false;

        // Store the drawn line segment
        lines.push_back({startX, startY});
        lines.push_back({endX, endY});
    }

    glutPostRedisplay();
}

void motion(int x, int y) {
    endX = x;
    endY = glutGet(GLUT_WINDOW_HEIGHT) - y;  // Invert Y-coordinate screen vs opengl
    glutPostRedisplay();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set clear color to white
    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Draw Line with Mouse");
    glutInitWindowSize(400, 400);

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glutMainLoop();
    return 0;
}
