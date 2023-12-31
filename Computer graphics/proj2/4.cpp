#include <GL/glut.h>
#include <iostream>

// Function to handle menu events
void menuHandler(int choice) {
    switch (choice) {
        case 1:
            std::cout << "New selected\n";
            break;
        case 2:
            std::cout << "Open selected\n";
            break;
        case 3:
            std::cout << "Save selected\n";
            break;
        case 4:
            std::cout << "Print selected\n";
            break;
        case 6:
            std::cout << "Close selected\n";
            break;
        case 21:
            std::cout << "Microsoft Word selected\n";
            break;
        case 22:
            std::cout << "Adobe Reader selected\n";
            break;
        case 23:
            std::cout << "Microsoft Edge selected\n";
            break;
        case 24:
            std::cout << "Foxit Reader selected\n";
            break;
        case 25:
            std::cout << "Google Chrome selected\n";
            break;
        default:
            break;
    }
}

// Function to handle display
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Menu Example");

    // Register display function
    glutDisplayFunc(display);

    // Create submenus
    int openWithMenu = glutCreateMenu(menuHandler);
    glutAddMenuEntry("Microsoft Word", 21);
    glutAddMenuEntry("Adobe Reader", 22);
    glutAddMenuEntry("Microsoft Edge", 23);
    glutAddMenuEntry("Foxit Reader", 24);
    glutAddMenuEntry("Google Chrome", 25);

    // Create main menu
    int mainMenu = glutCreateMenu(menuHandler);
    glutAddMenuEntry("New", 1);
    glutAddMenuEntry("Open", 2);
    glutAddMenuEntry("Save", 3);
    glutAddMenuEntry("Print", 4);
    glutAddSubMenu("Open with", openWithMenu); // Attach the sub-menu
    glutAddMenuEntry("Close", 6);

    // Attach the main menu to the right mouse button
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
