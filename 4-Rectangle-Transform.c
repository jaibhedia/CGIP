#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/glut.h>

// Function to display the objects and perform geometric operations
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glClearColor(1.0, 1.0, 1.0, 1); // Set the clear color to white
    glMatrixMode(GL_MODELVIEW); // Set the matrix mode to modelview

    // Draw the original rectangle in blue
    glColor3f(0.0, 0.0, 1.0); // Set the color to blue
    glRecti(250, 300, 400, 350); // Draw a rectangle with bottom-left corner at (250, 300) and top-right corner at (400, 350)

    // Perform translation on the rectangle
    glPushMatrix(); // Save the current transformation matrix
    glColor3f(1.0, 0.0, 0.0); // Set the color to red
    glTranslatef(-100.0, -50, 0.0); // Translate the rectangle by (-100, -50)
    glRecti(250, 300, 400, 350); // Draw the translated rectangle
    glPopMatrix(); // Restore the original transformation matrix

    // Perform rotation on the rectangle
    glPushMatrix(); // Save the current transformation matrix
    glRotatef(20, 0.0, 0.0, 1.0); // Rotate the rectangle by 20 degrees around the z-axis
    glRecti(250, 300, 400, 350); // Draw the rotated rectangle
    glPopMatrix(); // Restore the original transformation matrix

    // Perform scaling on the rectangle
    glPushMatrix(); // Save the current transformation matrix
    glScalef(0.5, 1.0, 1.0); // Scale the rectangle by 0.5 along the x-axis and 1.0 along the y-axis
    glRecti(250, 300, 400, 350); // Draw the scaled rectangle
    glPopMatrix(); // Restore the original transformation matrix

    glFlush(); // Flush the output buffer to ensure all commands are executed
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(1000, 1000); // Set the window size
    glutCreateWindow("Geometric Operations on 2D Objects"); // Create the window with a title
    glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
    glLoadIdentity(); // Load the identity matrix
    gluOrtho2D(0, 500, 0, 500); // Set up a 2D orthographic viewing region
    glutDisplayFunc(display); // Set the display callback function
    glutMainLoop(); // Enter the GLUT event processing loop
}
