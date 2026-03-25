#include <GL/glut.h>

// Rotation angles
float angleX = 20.0f;
float angleY = 30.0f;

// Draw cube with colored faces
void drawCube() {
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1, 0, 0);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);

    // Back face (green)
    glColor3f(0, 1, 0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);

    // Left face (blue)
    glColor3f(0, 0, 1);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5, -0.5);

    // Right face (yellow)
    glColor3f(1, 1, 0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.5,  0.5, -0.5);
    glVertex3f(0.5,  0.5,  0.5);
    glVertex3f(0.5, -0.5,  0.5);

    // Top face (cyan)
    glColor3f(0, 1, 1);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.5, 0.5,  0.5);
    glVertex3f( 0.5, 0.5,  0.5);
    glVertex3f( 0.5, 0.5, -0.5);

    // Bottom face (magenta)
    glColor3f(1, 0, 1);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f(-0.5, -0.5,  0.5);

    glEnd();
}

// Display callback
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -3.0f);  // Move cube back
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    drawCube();
    glutSwapBuffers();
}

// Arrow keys for rotation
void specialKeys(int key, int x, int y) {
    const float step = 5.0f;
    if(key == GLUT_KEY_UP)    angleX -= step;
    if(key == GLUT_KEY_DOWN)  angleX += step;
    if(key == GLUT_KEY_LEFT)  angleY -= step;
    if(key == GLUT_KEY_RIGHT) angleY += step;
    glutPostRedisplay();
}

// Window reshape
void reshape(int w, int h) {
    if(h == 0) h = 1;
    float aspect = (float)w / h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow("3D Cube with Rotation");

    glEnable(GL_DEPTH_TEST);       // Enable depth testing
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
