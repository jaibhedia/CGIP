#include <GL/freeglut.h>
#include <stdio.h>

GLfloat ctrlpoints[4][3] = {
    {-4.0, -4.0, 0.0},
    {-2.0, 4.0, 0.0},
    {2.0, -4.0, 0.0},
    {4.0, 4.0, 0.0}
};

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black
    glPointSize(5.0); // Set the point size
    glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // Set up a 2D orthographic viewing region
}

void display(void) {
    int i;
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    // Draw the control points
    glColor3f(1.0, 0.0, 0.0); // Set the color to red
    glBegin(GL_POINTS);
    for (i = 0; i < 4; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();

    // Draw the Bezier curve
    glColor3f(0.0, 0.0, 0.0); // Set the color to black
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]); // Define a 1D evaluator
    glEnable(GL_MAP1_VERTEX_3); // Enable the 1D evaluator
    glBegin(GL_LINE_STRIP);
    for (i = 0; i <= 30; i++)
        glEvalCoord1f((GLfloat)i / 30.0); // Evaluate and draw the Bezier curve
    glEnd();

    glFlush(); // Flush the output buffer to ensure all commands are executed
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // Set the viewport
    glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
    glLoadIdentity(); // Load the identity matrix
    gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // Set up a 2D orthographic viewing region
    glMatrixMode(GL_MODELVIEW); // Set the matrix mode to modelview
    glLoadIdentity(); // Load the identity matrix
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(500, 500); // Set the window size
    glutInitWindowPosition(100, 100); // Set the window position
    glutCreateWindow("Bezier Curve"); // Create the window with a title
    init(); // Call the initialization function
    glutDisplayFunc(display); // Set the display callback function
    glutReshapeFunc(reshape); // Set the reshape callback function
    glutMainLoop(); // Enter the GLUT event processing loop
    return 0;
}
