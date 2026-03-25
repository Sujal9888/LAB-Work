#include <GL/glut.h>
#include <GL/glu.h>  // Include GLU for gluOrtho2D

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Original triangle (Red)
    glColor3f(1, 0, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
    glEnd();

    // Translated triangle (Green) by (0.5, 0.5)
    glColor3f(0, 1, 0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f + 0.5f, -0.5f + 0.5f);
        glVertex2f(0.0f + 0.5f, 0.5f + 0.5f);
        glVertex2f(0.5f + 0.5f, -0.5f + 0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle Translation");

    glClearColor(0.0, 0.0, 0.0, 1.0);

    // Set up 2D orthographic projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 2.0, -1.0, 2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
