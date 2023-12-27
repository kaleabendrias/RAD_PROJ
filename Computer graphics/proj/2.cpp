#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    int numRectangles = 10;
    float initialSize = 0.5f;
    float stepSize = initialSize / numRectangles;

    for (int i = 0; i < numRectangles; i++) {
        float size = initialSize - i * stepSize;
        float x0 = -size;
        float x1 = size;
        float y0 = -size;
        float y1 = size;

        float t = static_cast<float>(i) / numRectangles;
        glColor3f(1.0f - t, 1.0f - t, 1.0f - t);  // Set color to gray scale
        glBegin(GL_QUADS);
        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y1);
        glVertex2f(x0, y1);
        glEnd();
    }
    
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Pattern of Rectangles");
    glutDisplayFunc(display);
    glutMainLoop();
    
    return 0;
}
