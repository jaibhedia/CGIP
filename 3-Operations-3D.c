#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

// Vertex coordinates for a cube
float v[8][3] = {
    {-1, -1, 1}, {-1, 1, 1}, {1, 1, 1}, {1, -1, 1},
    {-1, -1, -1}, {-1, 1, -1}, {1, 1, -1}, {1, -1, -1}
};

// Colors for each vertex
float c[8][3] = {
    {0, 0, 1}, {0, 1, 1}, {1, 1, 1}, {1, 0, 1},
    {0, 0, 0}, {0, 1, 0}, {1, 1, 0}, {1, 0, 0}
};

// Rotation angles for the cube
float theta[3] = {0, 0, 0};
int flag = 2;

// Initialization function
void myinit() {
    glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
    glLoadIdentity(); // Load the identity matrix
    glOrtho(-2, 2, -2, 2, -2, 2); // Set up an orthographic projection
    glMatrixMode(GL_MODELVIEW); // Set the matrix mode to modelview
}

// Idle function for animation
void idlefunc() {
    theta[flag]++; // Increment the rotation angle for the current axis
    if (theta[flag] > 360) theta[flag] = 0; // Reset the angle if it exceeds 360
    glutPostRedisplay(); // Mark the current window as needing to be redisplayed
}

// Mouse function to change the axis of rotation
void mousefunc(int button, int status, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
        flag = 2; // Rotate around the z-axis
    if (button == GLUT_MIDDLE_BUTTON && status == GLUT_DOWN)
        flag = 1; // Rotate around the y-axis
    if (button == GLUT_RIGHT_BUTTON && status == GLUT_DOWN)
        flag = 0; // Rotate around the x-axis
}

// Function to draw a polygon with the given vertices and colors
void drawpoly(int a, int b, int c1, int d) {
    glBegin(GL_POLYGON); // Start specifying the vertices of a polygon
    glColor3fv(c[a]); // Set the color for the first vertex
    glVertex3fv(v[a]); // Specify the first vertex
    glColor3fv(c[b]); // Set the color for the second vertex
    glVertex3fv(v[b]); // Specify the second vertex
    glColor3fv(c[c1]); // Set the color for the third vertex
    glVertex3fv(v[c1]); // Specify the third vertex
    glColor3fv(c[d]); // Set the color for the fourth vertex
    glVertex3fv(v[d]); // Specify the fourth vertex
    glEnd(); // End specifying vertices
}

// Function to draw the color cube
void colorcube() {
    drawpoly(0, 1, 2, 3); // Front face
    drawpoly(0, 1, 5, 4); // Left face
    drawpoly(1, 5, 6, 2); // Top face
    drawpoly(4, 5, 6, 7); // Back face
    drawpoly(3, 2, 6, 7); // Right face
    drawpoly(0, 4, 7, 3); // Bottom face
}

// Display function
void display() {
    glClearColor(1, 1, 1, 1); // Set the clear color to white
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers
    glColor3f(1, 0, 0); // Set the drawing color to red
    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glLoadIdentity(); // Load the identity matrix
    glRotatef(theta[0], 1, 0, 0); // Rotate the cube around the x-axis
    glRotatef(theta[1], 0, 1, 0); // Rotate the cube around the y-axis
    glRotatef(theta[2], 0, 0, 1); // Rotate the cube around the z-axis
    colorcube(); // Draw the color cube
    glFlush(); // Flush the output buffer
    glutSwapBuffers(); // Swap the front and back buffers
}

// Main function
void main(int argc, char **argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Set the display mode
    glutInitWindowPosition(100, 100); // Set the window position
    glutInitWindowSize(500, 500); // Set the window size
    glutCreateWindow("Cube Rotation"); // Create the window with a title
    myinit(); // Call the initialization function

    glutDisplayFunc(display); // Set the display callback function
    glutMouseFunc(mousefunc); // Set the mouse callback function
    glutIdleFunc(idlefunc); // Set the idle callback function
    glutMainLoop(); // Enter the GLUT event processing loop
}
