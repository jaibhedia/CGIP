#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/glut.h>

// Function to display the objects and perform geometric operations
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glClearColor(1.0, 1.0, 1.0, 1); // Set the clear color to white
    glMatrixMode(GL_MODELVIEW); // Set the matrix mode to modelview

    // Define the vertices of a triangle
    int p1[] = {50, 100};
    int p2[] = {200, 100};
    int p3[] = {125, 200};

    // Draw the original triangle in blue
    glColor3f(0.0, 0.0, 1.0); // Set the color to blue
    glBegin(GL_TRIANGLES); // Start specifying the vertices of a triangle
    glVertex2iv(p1); // Specify the first vertex
    glVertex2iv(p2); // Specify the second vertex
    glVertex2iv(p3); // Specify the third vertex
    glEnd(); // End specifying vertices

    // Perform scaling on the triangle
    int sx = 1; int sy = 2; // Scaling factors
    p1[0] = p1[0] * sx; // Scale the x-coordinate of the first vertex
    p1[1] = p1[1] * sy; // Scale the y-coordinate of the first vertex
    p2[0] = p2[0] * sx; // Scale the x-coordinate of the second vertex
    p2[1] = p2[1] * sy; // Scale the y-coordinate of the second vertex
    p3[0] = p3[0] * sx; // Scale the x-coordinate of the third vertex
    p3[1] = p3[1] * sy; // Scale the y-coordinate of the third vertex

    // Draw the scaled triangle in green
    glColor3f(0.0, 1.0, 0.0); // Set the color to green
    glBegin(GL_TRIANGLES); // Start specifying the vertices of a triangle
    glVertex2iv(p1); // Specify the first vertex
    glVertex2iv(p2); // Specify the second vertex
    glVertex2iv(p3); // Specify the third vertex
    glEnd(); // End specifying vertices

    // Perform translation on the triangle
    int tx = 100; int ty = 100; // Translation amounts
    p1[0] = p1[0] + tx; // Translate the x-coordinate of the first vertex
    p1[1] = p1[1] + ty; // Translate the y-coordinate of the first vertex
    p2[0] = p2[0] + tx; // Translate the x-coordinate of the second vertex
    p2[1] = p2[1] + ty; // Translate the y-coordinate of the second vertex
    p3[0] = p3[0] + tx; // Translate the x-coordinate of the third vertex
    p3[1] = p3[1] + ty; // Translate the y-coordinate of the third vertex

    // Draw the translated triangle in red
    glColor3f(1.0, 0.0, 0.0); // Set the color to red
    glBegin(GL_TRIANGLES); // Start specifying the vertices of a triangle
    glVertex2iv(p1); // Specify the first vertex
    glVertex2iv(p2); // Specify the second vertex
    glVertex2iv(p3); // Specify the third vertex
    glEnd(); // End specifying vertices

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
