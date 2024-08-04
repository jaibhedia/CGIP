#include <stdio.h>
#include <GL/glut.h>

float v[4][3] = { {-1,-0.25,0},{1,-0.25,0}, {0,1,0}, {0,0,1} };
int n;

void myinit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
}

void draw_triangle(float *a, float *b, float *c) {
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();
}

void draw_tetra(float *a, float *b, float *c, float *d) {
    glColor3f(1.0, 0.0, 0.0);
    draw_triangle(a, b, c);
    glColor3f(0.0, 0.0, 1.0);
    draw_triangle(a, c, d);
    glColor3f(0.0, 1.0, 0.0);
    draw_triangle(c, b, d);
    glColor3f(0.0, 0.0, 0.0);
    draw_triangle(a, b, d);
}

void divide_tetra(float *a, float *b, float *c, float *d, int m) {
    float ab[3], ac[3], ad[3], bc[3], bd[3], cd[3];
    int j;
    if (m > 0) {
        for (j = 0; j < 3; j++) {
            ab[j] = (a[j] + b[j]) / 2;
            ac[j] = (a[j] + c[j]) / 2;
            ad[j] = (a[j] + d[j]) / 2;
            bc[j] = (b[j] + c[j]) / 2;
            bd[j] = (d[j] + b[j]) / 2;
            cd[j] = (c[j] + d[j]) / 2;
        }
        divide_tetra(a, ab, ac, ad, m - 1);
        divide_tetra(ab, b, bc, bd, m - 1);
        divide_tetra(ac, bc, c, cd, m - 1);
        divide_tetra(ad, bd, cd, d, m - 1);
    } else {
        draw_tetra(a, b, c, d);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    divide_tetra(v[0], v[1], v[2], v[3], n);
    glFlush();
}

int main(int argc, char **argv) {
    n = 2;
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Transformation on 3D Objects");
    myinit();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutMainLoop();
}
