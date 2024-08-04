#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <gl/glut.h>

// Global variables to store the coordinates of the two points
GLint X1, Y1, X2, Y2;

// Function to draw a line using Bresenham's algorithm
void LineBres(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    int dx = abs(X2 - X1); // Calculate the difference in x coordinates
    int dy = abs(Y2 - Y1); // Calculate the difference in y coordinates
    int p = 2 * dy - dx; // Initial decision parameter
    int twoDy = 2 * dy; // Two times the difference in y coordinates
    int twoDyDx = 2 * (dy - dx); // Two times the difference in y and x coordinates

    int x, y;
    // Determine which point to start from
    if (X1 > X2) {
        x = X2;
        y = Y2;
        X2 = X1;
    } else {
        x = X1;
        y = Y1;
        X2 = X2;
    }
    
    glBegin(GL_POINTS); // Start specifying point vertices
    glVertex2i(x, y); // Draw the initial point
    
    while (x < X2) { // Loop until the end point is reached
        x++;
        if (p < 0) {
            p += twoDy; // Update the decision parameter
        } else {
            y++;
            p += twoDyDx; // Update the decision parameter and y coordinate
        }
        glVertex2i(x, y); // Draw the next point
    }
    glEnd(); // End specifying point vertices
    
    glFlush(); // Flush the output buffer to ensure all commands are executed
}

// Initialization function
void Init() {
    glClearColor(1.0, 1.0, 1.0, 0); // Set the clear color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black
    glPointSize(4.0); // Set the point size
    glViewport(0, 0, 50, 50); // Set the viewport
    glMatrixMode(GL_PROJECTION); // Set the matrix mode to projection
    glLoadIdentity(); // Load the identity matrix
    gluOrtho2D(0, 50, 0, 50); // Set up a 2D orthographic viewing region
}

int main(int argc, char **argv) {
    printf("Enter two points for draw line Bresenham:\n");
    printf("\nEnter point1(X1, Y1):");
    scanf("%d%d", &X1, &Y1); // Get the first point from the user
    printf("\nEnter point2(X2, Y2):");
    scanf("%d%d", &X2, &Y2); // Get the second point from the user
    
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(300, 400); // Set the window size
    glutInitWindowPosition(0, 0); // Set the window position
    glutCreateWindow("Line Bresenham"); // Create the window with a title
    Init(); // Call the initialization function
    glutDisplayFunc(LineBres); // Set the display callback function
    glutMainLoop(); // Enter the GLUT event processing loop
}
