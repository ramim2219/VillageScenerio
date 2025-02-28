/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <unistd.h>
#include<cmath>
float waveOffset = 1.50f;
float PI = 3.14157;
struct Color {
    float r, g, b;
};
float manX = -0.4f; // Initial X position of the man
float manY = -1.0f; // Initial Y position of the man
bool isMoving = true; // Flag to stop animation when the man reaches the destination
void drawCircle(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.14159f / 180.0f;
        float dx = cos(angle) * radius;
        float dy = sin(angle) * radius;
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}
void drawCloud(float x, float y) {
    // Drawing the cloud with multiple circles
   glColor3f(0.7373f, 0.8118f, 0.9333f);

    // Large center circle
    drawCircle(x, y, 0.1f);

    // Smaller circles around the center to create the fluffy effect
    drawCircle(x - 0.12f, y + 0.01f, 0.07f);  // Top-left
    drawCircle(x + 0.12f, y + 0.01f, 0.07f);  // Top-right
    drawCircle(x - 0.1f, y - 0.1f, 0.07f);   // Bottom-left
    drawCircle(x + 0.1f, y - 0.1f, 0.07f);   // Bottom-right
    drawCircle(x, y - 0.12f, 0.07f);          // Center-bottom
}
float dx=0.6f;
void boat4() {
    float dy = 0.6f; // Offset to move boat to (1.0, 0.7)

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.3f + dx, -0.25f + dy);
    glVertex2f(0.35f + dx, -0.3f + dy);
    glVertex2f(0.65f + dx, -0.3f + dy);
    glVertex2f(0.7f + dx, -0.25f + dy);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 153, 0);
    glVertex2f(0.37f + dx, -0.25f + dy);
    glVertex2f(0.39f + dx, -0.17f + dy);
    glVertex2f(0.412f + dx, -0.13f + dy);
    glVertex2f(0.63f + dx, -0.13f + dy);
    glVertex2f(0.64f + dx, -0.16f + dy);
    glVertex2f(0.65f + dx, -0.25f + dy);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 25, 25);
    glVertex2f(0.462f + dx, -0.08f + dy);
    glVertex2f(0.462f + dx, 0.08f + dy);
    glVertex2f(0.465f + dx, 0.1f + dy);
    glVertex2f(0.564f + dx, 0.08f + dy);
    glVertex2f(0.565f + dx, 0.06f + dy);
    glVertex2f(0.565f + dx, -0.1f + dy);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(136, 204, 0);
    glVertex2f(0.5f + dx, -0.13f + dy);
    glVertex2f(0.5f + dx, 0.14f + dy);
    glVertex2f(0.51f + dx, 0.14f + dy);
    glVertex2f(0.51f + dx, -0.13f + dy);
    glEnd();
}
void boat2() {
    float dx = 0.5f, dy = 0.23f; // Offset to move boat to (1.0, 0.1)

    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex2f(0.63f + dx, -0.53f + dy);
    glVertex2f(0.53f + dx, -0.53f + dy);
    glVertex2f(0.43f + dx, -0.5f + dy);
    glVertex2f(0.53f + dx, -0.6f + dy);
    glVertex2f(0.78f + dx, -0.6f + dy);
    glVertex2f(0.88f + dx, -0.5f + dy);
    glVertex2f(0.78f + dx, -0.53f + dy);
    glVertex2f(0.73f + dx, -0.53f + dy);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(122, 122, 82);
    glVertex2f(0.43f + dx, -0.5f + dy);
    glVertex2f(0.53f + dx, -0.53f + dy);
    glVertex2f(0.63f + dx, -0.53f + dy);
    glVertex2f(0.73f + dx, -0.53f + dy);
    glVertex2f(0.78f + dx, -0.53f + dy);
    glVertex2f(0.88f + dx, -0.5f + dy);
    glVertex2f(0.78f + dx, -0.48f + dy);
    glVertex2f(0.73f + dx, -0.48f + dy);
    glVertex2f(0.63f + dx, -0.48f + dy);
    glVertex2f(0.53f + dx, -0.48f + dy);
    glVertex2f(0.43f + dx, -0.5f + dy);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.88f + dx, -0.5f + dy);
    glVertex2f(0.78f + dx, -0.48f + dy);
    glVertex2f(0.78f + dx, -0.48f + dy);
    glVertex2f(0.73f + dx, -0.48f + dy);
    glVertex2f(0.73f + dx, -0.48f + dy);
    glVertex2f(0.63f + dx, -0.48f + dy);
    glVertex2f(0.63f + dx, -0.48f + dy);
    glVertex2f(0.53f + dx, -0.48f + dy);
    glVertex2f(0.53f + dx, -0.48f + dy);
    glVertex2f(0.43f + dx, -0.5f + dy);
    glEnd();

    glLineWidth(9);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.53f + dx, -0.48f + dy);
    glVertex2f(0.53f + dx, -0.535f + dy);
    glVertex2f(0.63f + dx, -0.48f + dy);
    glVertex2f(0.63f + dx, -0.535f + dy);
    glVertex2f(0.73f + dx, -0.48f + dy);
    glVertex2f(0.73f + dx, -0.535f + dy);
    glVertex2f(0.81f + dx, -0.48f + dy);
    glVertex2f(0.81f + dx, -0.535f + dy);
    glEnd();

    glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(204, 153, 0);
    glVertex2f(0.38f + dx, -0.38f + dy);
    glVertex2f(0.4f + dx, -0.53f + dy);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3ub(153, 153, 102);
    glVertex2f(0.38f + dx, -0.42f + dy);
    glVertex2f(0.43f + dx, -0.5f + dy);
    glEnd();
}

bool doorOpen = false;
void tree(GLfloat xpos, GLfloat ypos){
    // Tree base polygon
    glBegin(GL_POLYGON);
    glColor3ub(102, 51, 0);
        glVertex2f(xpos-0.72f, ypos-0.15f);
        glVertex2f(xpos-0.65f, ypos-0.2f);
        glVertex2f(xpos-0.735f, ypos-0.17f);
        glVertex2f(xpos-0.74f, ypos-0.25f);
        glVertex2f(xpos-0.775f, ypos-0.17f);
        glVertex2f(xpos-0.85f, ypos-0.2f);
        glVertex2f(xpos-0.78f, ypos-0.15f);
    glEnd();

    // Tree trunk
    glBegin(GL_QUADS);
        glColor3ub(102, 51, 0);
        glVertex2f(xpos-0.78f, ypos-0.15f);
        glVertex2f(xpos-0.78f, ypos+0.23f);
        glVertex2f(xpos-0.72f, ypos+0.23f);
        glVertex2f(xpos-0.72f, ypos-0.15f);
    glEnd();

    // Top trunk
    glBegin(GL_QUADS);
        glColor3ub(102, 51, 0);
        glVertex2f(xpos-0.76f, ypos+0.23f);
        glVertex2f(xpos-0.76f, ypos+0.3f);
        glVertex2f(xpos-0.74f, ypos+0.3f);
        glVertex2f(xpos-0.74f, ypos+0.23f);
    glEnd();

    // Side branch left
    glBegin(GL_QUADS);
        glColor3ub(102, 51, 0);
        glVertex2f(xpos-0.74f, ypos+0.23f);
        glVertex2f(xpos-0.71f, ypos+0.29f);
        glVertex2f(xpos-0.7f, ypos+0.28f);
        glVertex2f(xpos-0.72f, ypos+0.23f);
    glEnd();

    // Side branch right
    glBegin(GL_QUADS);
        glColor3ub(102, 51, 0);
        glVertex2f(xpos-0.78f, ypos+0.23f);
        glVertex2f(xpos-0.8f, ypos+0.28f);
        glVertex2f(xpos-0.79f, ypos+0.29f);
        glVertex2f(xpos-0.76f, ypos+0.23f);
    glEnd();

    int i;
    GLfloat radius = 0.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    // Tree foliage
    GLfloat x = xpos - 0.75f, y = ypos + 0.33f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat a = xpos - 0.68f, b = ypos + 0.31f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(a, b); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(a + (radius * cos(i * twicePi / triangleAmount)),
                   b + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c = xpos - 0.81f, d = ypos + 0.31f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(c + (radius * cos(i * twicePi / triangleAmount)),
                   d + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e = xpos - 0.87f, f = ypos + 0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e, f); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(e + (radius * cos(i * twicePi / triangleAmount)),
                   f + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g = xpos - 0.61f, h = ypos + 0.35f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(g + (radius * cos(i * twicePi / triangleAmount)),
                   h + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat a1 = xpos - 0.61f, b1 = ypos + 0.4f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(a1, b1); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(a1 + (radius * cos(i * twicePi / triangleAmount)),
                   b1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat c1 = xpos - 0.88f, d1 = ypos + 0.4f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(c, d); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(c1 + (radius * cos(i * twicePi / triangleAmount)),
                   d1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e1 = xpos - 0.87f, f1 = ypos + 0.44f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e1, f1); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(e1 + (radius * cos(i * twicePi / triangleAmount)),
                   f1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat g1 = xpos - 0.61f, h1 = ypos + 0.4f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(g, h); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(g1 + (radius * cos(i * twicePi / triangleAmount)),
                   h1 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e11 = xpos - 0.64f, f11 = ypos + 0.44f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e11, f11); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(e11 + (radius * cos(i * twicePi / triangleAmount)),
                   f11 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e12 = xpos - 0.75f, f12 = ypos + 0.44f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e12, f12); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(e12 + (radius * cos(i * twicePi / triangleAmount)),
                   f12 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    // Tree base rectangle for final decoration
    glBegin(GL_QUADS);
    glColor3ub(51, 204, 51);
    glVertex2f(xpos-0.85f, ypos+0.33f);
    glVertex2f(xpos-0.85f, ypos+0.44f);
    glVertex2f(xpos-0.65f, ypos+0.44f);
    glVertex2f(xpos-0.65f, ypos+0.33f);
    glEnd();

    GLfloat e123 = xpos - 0.8f, f123 = ypos + 0.5f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e123, f123); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(e123 + (radius * cos(i * twicePi / triangleAmount)),
                   f123 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();

    GLfloat e1232 = xpos - 0.7f, f1232 = ypos + 0.5f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(51, 204, 51);
    glVertex2f(e1232, f1232); // center of circle
    for(i = 0; i <= triangleAmount; i++) {
        glVertex2f(e1232 + (radius * cos(i * twicePi / triangleAmount)),
                   f1232 + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
void drawWave() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue

    // Loop through points to create the wave
    for (float x = -0.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(10.0f * (x + waveOffset));  // Further reduced height of the wave
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave2() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue


    // Loop through points to create the wave
    for (float x = -0.0f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(10.0f * (x + waveOffset)) - 0.15f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave3() {
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue

    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(10.0f * (x + waveOffset)) + 0.3f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave4(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue


    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(9.0f * (x + waveOffset)) + 0.35f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave5(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue


    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(7.0f * (x + waveOffset)) + 0.39f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave6(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue


    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(5.0f * (x + waveOffset)) + 0.21f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave7(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue


    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(8.0f * (x + waveOffset)) + 0.15f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave8(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue

    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(8.0f * (x + waveOffset)) + 0.5f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void drawWave9(){
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.5f, 1.0f); // Soft ocean blue

    // Loop through points to create the wave
    for (float x = -1.5f; x <= 1.5f; x += 0.05f) {
        float y = 0.05f * sin(7.0f * (x + waveOffset)) + 0.55f;  // Moved the wave further down
        glVertex2f(x, y);  // Set the vertex for the wave
    }
    glEnd();
}
void soil(){
    glColor3f(107.0f / 255.0f, 142.0f / 255.0f, 35.0f / 255.0f);  // #6B8E23

    glBegin(GL_POLYGON);
        glVertex2f(-1.5f, 1.0f);
        glVertex2f(-1.5f, 0.72f);
        glVertex2f(1.5f, 0.62f);
        glVertex2f(1.5f, 1.0f);

        glVertex2f(-1.5f, 0.1f);
        glVertex2f(-1.5f, -1.5f);
        glVertex2f(1.5f, -1.5f);
        glVertex2f(1.5f, 0.6f);
    glEnd();
}
void drawHill(float cx, float cy, float radius){
    int num_segments = 100;  // Increase for smoother curves
    // Set the hill color (darker green for hills)
    glColor3f(79.0f / 255.0f, 107.0f / 255.0f, 47.0f / 255.0f);  // #4F6B2F

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center point
    for (int i = 0; i <= num_segments; i++) {
        float angle = M_PI * i / num_segments; // From 0 to PI for a semi-circle
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void drawContinuousHills() {
    drawHill(-1.45f, 1.0f, 0.1f);
    drawHill(-1.25f, 1.0f, 0.13f);
    drawHill(-1.05f, 1.0f, 0.09f);
    drawHill(-0.85f, 1.0f, 0.15f);
    drawHill(-0.62f, 1.0f, 0.09f);
    drawHill(-0.35f, 1.0f, 0.21f);
    drawHill(-0.1f, 1.0f, 0.09f);
    drawHill(-0.001f, 1.0f, 0.09f);

    // Additional hills on the right side with reduced gap
    drawHill(0.15f, 1.0f, 0.11f);
    drawHill(0.35f, 1.0f, 0.1f);
    drawHill(0.55f, 1.0f, 0.12f);
    drawHill(0.75f, 1.0f, 0.09f);
    drawHill(0.95f, 1.0f, 0.13f);
    drawHill(1.15f, 1.0f, 0.1f);
    drawHill(1.35f, 1.0f, 0.12f);
    drawHill(1.55f, 1.0f, 0.08f);
    drawHill(1.75f, 1.0f, 0.14f);
    drawHill(1.95f, 1.0f, 0.1f);
}
void sun(){
    int i;

    GLfloat x = 1.2f;  // updated x-coordinate
    GLfloat y = 1.3f;   // updated y-coordinate
    GLfloat radius = 0.06f;
    int triangleAmount = 20;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 204, 0);
        glVertex2f(x, y); // center of circle (updated position)
        for(i = 0; i <= triangleAmount; i++) {
            glVertex2f(
                x + (radius * cos(i * twicePi / triangleAmount)),
                y + (radius * sin(i * twicePi / triangleAmount))
            );
        }
    glEnd();
}

void drawRiver(){
    glColor3f(0.44f, 0.63f, 0.75f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.5f, 0.7f);
        glVertex2f(-1.5f, 0.1f);
        glVertex2f(1.5f, -0.4f);
        glVertex2f(1.5f, 0.6f);
    glEnd();
    glColor3f(0.44f, 0.77f, 0.36f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.5f, 0.72f);
        glVertex2f(-1.5f, 0.7f);
        glVertex2f(1.5f, 0.6f);
        glVertex2f(1.5f, 0.62f);
    glEnd();
    glColor3f(0.44f, 0.77f, 0.36f);
    glBegin(GL_POLYGON);
        glVertex2f(-1.5f, 0.1f);
        glVertex2f(-1.5f, 0.12f);
        glVertex2f(1.5f, -0.42f);
        glVertex2f(1.5f, -0.39f);
    glEnd();
}
void drawSquaresWithGaps2(float offset){
    glColor3f(0.247f, 0.035f, 0.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.053f+offset, -0.16f);
        glVertex2f(-0.053f + 0.04f+offset, -0.16f+0.02f);
        glVertex2f(-0.053f + 0.04f+offset, -0.16f+0.07f);
        glVertex2f(-0.053f+offset, -0.16f+0.05f );
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.053f+offset, -0.08f);
        glVertex2f(-0.053f + 0.04f+offset, -0.08f+0.02f);
        glVertex2f(-0.053f + 0.04f+offset, -0.08f+0.07f);
        glVertex2f(-0.053f+offset, -0.08f+0.05f );
    glEnd();
}
void drawSquaresWithGaps(float offsetx) {
    float startX = -0.053f;
    float startY = -0.16f;
    float squareWidth = 0.049f;
    float squareHeight = 0.049f;
    float gap = 0.01f;
    int rows = 3, cols = 2;
    glColor3f(0.247f, 0.035f, 0.0f);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float x = startX + j * (squareWidth + gap);
            float y = startY + i * (squareHeight + gap);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x+offsetx, y);
                glVertex2f(x + squareWidth+offsetx, y);
                glVertex2f(x + squareWidth+offsetx, y + squareHeight);
                glVertex2f(x+offsetx, y + squareHeight);
            glEnd();
        }
    }
}
void drawMan(float xPos, float yPos) {
    glPushMatrix();
    glTranslatef(xPos, yPos, 0.0f);
    glScalef(0.8f, 0.8f, 1.0f); // Scale down slightly

    if (yPos >= 0.2f && yPos <= 0.6) {
        doorOpen = true;
    } else {
        doorOpen = false;
    }

    // Head (Smaller)
    glColor3f(1.0f, 0.8f, 0.6f);
    float cx = 0.031f, cy = -0.56f, radius = 0.032f; // Reduced radius
    int num_segments = 100;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float angle = 2.0f * M_PI * i / num_segments;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Hands (Scaled Down)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(-0.001f, -0.63f);
    glVertex2f(-0.04f, -0.72f); // Shorter hands
    glVertex2f(0.06f, -0.63f);
    glVertex2f(0.1f, -0.72f);
    glEnd();

    // Body (Smaller)
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.001f, -0.6f);
    glVertex2f(0.06f, -0.6f); // Slightly narrower body
    glVertex2f(0.06f, -0.72f);
    glVertex2f(-0.001f, -0.72f);
    glEnd();

    // Legs (Shorter)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0.03f, -0.72f);
    glVertex2f(-0.01f, -0.85f);
    glVertex2f(0.03f, -0.72f);
    glVertex2f(0.08f, -0.85f);
    glEnd();

    glPopMatrix();
}

void door(float offsetx) {
    if (doorOpen) {

        glColor3f(0.776f, 0.663f, 0.224f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.08f+offsetx, -0.2f);
            glVertex2f(0.08f+offsetx, -0.2f);
            glVertex2f(0.08f+offsetx, 0.05f);
            glVertex2f(-0.08f+offsetx, 0.05f);
        glEnd();
        glColor3f(0.247f, 0.035f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.07f+offsetx, -0.2f);
            glVertex2f(0.07f+offsetx, -0.2f);
            glVertex2f(0.07f+offsetx, 0.03f);
            glVertex2f(-0.07f+offsetx, 0.03f);
        glEnd();
        glColor3f(0.0f, 0.0f, 0.0f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.06f+offsetx, -0.2f);
            glVertex2f(0.06f+offsetx, -0.2f);
            glVertex2f(0.06f+offsetx,  0.02f);
            glVertex2f(-0.06f+offsetx,  0.02f);
        glEnd();
        glColor3f(0.639f, 0.349f, 0.141f);
        glBegin(GL_POLYGON);
            glVertex2f(-0.06f+offsetx, -0.2f);
            glVertex2f(0.03f+offsetx, -0.17f);
            glVertex2f(0.03f+offsetx,  0.017f);
            glVertex2f(-0.06f+offsetx,  0.02f);
        glEnd();
        drawSquaresWithGaps2(offsetx);

    } else {
        // Draw closed door
        Color colors[3] = {
            {0.776f, 0.663f, 0.224f},
            {0.247f, 0.035f, 0.0f},
            {0.639f, 0.349f, 0.141f}
        };

        float sizes[3] = {0.08f, 0.07f, 0.06f};
        float heights[3] = {0.05f, 0.03f, 0.02f};

        for (int i = 0; i < 3; i++) {
            glColor3f(colors[i].r, colors[i].g, colors[i].b);
            glBegin(GL_POLYGON);
                glVertex2f(-sizes[i]+offsetx, -0.2f);
                glVertex2f(sizes[i]+offsetx, -0.2f);
                glVertex2f(sizes[i]+offsetx, heights[i]);
                glVertex2f(-sizes[i]+offsetx, heights[i]);
            glEnd();
        }
        drawSquaresWithGaps(offsetx);
    }


}
void leftWindow(float offsetx){
    glColor3f(0.024f, 0.273f, 0.404f);
    glBegin(GL_POLYGON);
        glVertex2f(0.39f+offsetx, -0.1f);
        glVertex2f(0.2f+offsetx, -0.1f);
        glVertex2f(0.2f+offsetx, 0.1f);
        glVertex2f(0.39f+offsetx, 0.1f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_POLYGON);
        glVertex2f(0.35f+offsetx, -0.1f);
        glVertex2f(0.24f+offsetx, -0.1f);
        glVertex2f(0.24f+offsetx, 0.1f);
        glVertex2f(0.35f+offsetx, 0.1f);
    glEnd();
    glColor3f(0.114f, 0.729f, 0.635f);
    glBegin(GL_POLYGON);
        glVertex2f(0.34f+offsetx, -0.09f);
        glVertex2f(0.25f+offsetx, -0.09f);
        glVertex2f(0.25f+offsetx, 0.09f);
        glVertex2f(0.34f+offsetx, 0.09f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(0.34f+offsetx, 0.03f);
        glVertex2f(0.25f+offsetx, 0.03f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(0.34f+offsetx, -0.03f);
        glVertex2f(0.25f+offsetx, -0.03f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(0.29f+offsetx, -0.09f);
        glVertex2f(0.29f+offsetx, 0.09f);
    glEnd();
}
void centerWindowTop(float offsetx){
    glColor3f(0.024f, 0.273f, 0.404f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.21f+offsetx, 0.37f);
        glVertex2f(0.21f+offsetx, 0.37f);
        glVertex2f(0.21f+offsetx, 0.57f);
        glVertex2f(-0.21f+offsetx, 0.57f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.17f+offsetx, 0.37f);
        glVertex2f(0.17f+offsetx, 0.37f);
        glVertex2f(0.17f+offsetx, 0.57f);
        glVertex2f(-0.17f+offsetx, 0.57f);
    glEnd();
    glColor3f(0.114f, 0.729f, 0.635f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.16f+offsetx, 0.38f);
        glVertex2f(0.16f+offsetx, 0.38f);
        glVertex2f(0.16f+offsetx, 0.56f);
        glVertex2f(-0.16f+offsetx, 0.56f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(-0.10f+offsetx, 0.38f);
        glVertex2f(-0.10f+offsetx, 0.56f);

        glVertex2f(-0.05f+offsetx, 0.38f);
        glVertex2f(-0.05f+offsetx, 0.56f);

        glVertex2f(-0.0f+offsetx, 0.38f);
        glVertex2f(-0.0f+offsetx, 0.56f);

        glVertex2f(0.05f+offsetx, 0.38f);
        glVertex2f(0.05f+offsetx, 0.56f);

        glVertex2f(0.1f+offsetx, 0.38f);
        glVertex2f(0.1f+offsetx, 0.56f);

        glVertex2f(-0.16f+offsetx, 0.47f);
        glVertex2f(0.16f+offsetx, 0.47f);
    glEnd();
}
void leftWindowTop(float offsetx){
    glColor3f(0.024f, 0.273f, 0.404f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.39f+offsetx, 0.37f);
        glVertex2f(-0.25f+offsetx, 0.37f);
        glVertex2f(-0.25f+offsetx, 0.57f);
        glVertex2f(-0.39f+offsetx, 0.57f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.37f+offsetx, 0.37f);
        glVertex2f(-0.27f+offsetx, 0.37f);
        glVertex2f(-0.27f+offsetx, 0.57f);
        glVertex2f(-0.37f+offsetx, 0.57f);
    glEnd();
    glColor3f(0.114f, 0.729f, 0.635f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.36f+offsetx, 0.38f);
        glVertex2f(-0.28f+offsetx, 0.38f);
        glVertex2f(-0.28f+offsetx, 0.56f);
        glVertex2f(-0.36f+offsetx, 0.56f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(-0.32f+offsetx, 0.38f);
        glVertex2f(-0.32f+offsetx, 0.56f);

        glVertex2f(-0.36f+offsetx, 0.47f);
        glVertex2f(-0.28f+offsetx, 0.47f);
    glEnd();
}
void rightWindowTop(float offsetx){
    glColor3f(0.024f, 0.273f, 0.404f);
    glBegin(GL_POLYGON);
        glVertex2f(0.39f+offsetx, 0.37f);
        glVertex2f(0.25f+offsetx, 0.37f);
        glVertex2f(0.25f+offsetx, 0.57f);
        glVertex2f(0.39f+offsetx, 0.57f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_POLYGON);
        glVertex2f(0.37f+offsetx, 0.37f);
        glVertex2f(0.27f+offsetx, 0.37f);
        glVertex2f(0.27f+offsetx, 0.57f);
        glVertex2f(0.37f+offsetx, 0.57f);
    glEnd();
    glColor3f(0.114f, 0.729f, 0.635f);
    glBegin(GL_POLYGON);
        glVertex2f(0.36f+offsetx, 0.38f);
        glVertex2f(0.28f+offsetx, 0.38f);
        glVertex2f(0.28f+offsetx, 0.56f);
        glVertex2f(0.36f+offsetx, 0.56f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(0.32f+offsetx, 0.38f);
        glVertex2f(0.32f+offsetx, 0.56f);

        glVertex2f(0.36f+offsetx, 0.47f);
        glVertex2f(0.28f+offsetx, 0.47f);
    glEnd();
}
void rightWindow(float offsetx){
    glColor3f(0.024f, 0.273f, 0.404f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.39f+offsetx, -0.1f);
        glVertex2f(-0.2f+offsetx, -0.1f);
        glVertex2f(-0.2f+offsetx, 0.1f);
        glVertex2f(-0.39f+offsetx, 0.1f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f+offsetx, -0.1f);
        glVertex2f(-0.24f+offsetx, -0.1f);
        glVertex2f(-0.24f+offsetx, 0.1f);
        glVertex2f(-0.35f+offsetx, 0.1f);
    glEnd();
    glColor3f(0.114f, 0.729f, 0.635f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.34f+offsetx, -0.09f);
        glVertex2f(-0.25f+offsetx, -0.09f);
        glVertex2f(-0.25f+offsetx, 0.09f);
        glVertex2f(-0.34f+offsetx, 0.09f);
    glEnd();
    glColor3f(0.873f, 0.988f, 0.906f);
    glBegin(GL_LINES);
        glVertex2f(-0.34f+offsetx, 0.03f);
        glVertex2f(-0.25f+offsetx, 0.03f);

        glVertex2f(-0.34f+offsetx, -0.03f);
        glVertex2f(-0.25f+offsetx, -0.03f);

        glVertex2f(-0.29f+offsetx, -0.09f);
        glVertex2f(-0.29f+offsetx, 0.09f);
    glEnd();
}

void drawText(const char *text, float x, float y) {
    glRasterPos2f(x, y);  // Position the text at (x, y)
    for (int i = 0; text[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}
void stair(float offsetx){
    //stair area
    //stair area
    glColor3f(0.322f, 0.188f, 0.314f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53f+offsetx, -0.2f);
        glVertex2f(0.53f+offsetx, -0.2f);
        glVertex2f(0.53f+offsetx, -0.29f);
        glVertex2f(-0.53f+offsetx, -0.29f);
    glEnd();

    //stair
    //stair
    glColor3f(0.506f, 0.502f, 0.427f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.09f+offsetx, -0.2f);
        glVertex2f(0.09f+offsetx, -0.2f);
        glVertex2f(0.09f+offsetx, -0.23f);
        glVertex2f(-0.09f+offsetx, -0.23f);
    glEnd();
    glColor3f(0.741f, 0.741f, 0.745f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.10f+offsetx, -0.23f);
        glVertex2f(0.10f+offsetx, -0.23f);
        glVertex2f(0.10f+offsetx, -0.26f);
        glVertex2f(-0.10f+offsetx, -0.26f);
    glEnd();
    glColor3f(0.506f, 0.502f, 0.427f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.11f+offsetx, -0.26f);
        glVertex2f(0.11f+offsetx, -0.26f);
        glVertex2f(0.11f+offsetx, -0.29f);
        glVertex2f(-0.11f+offsetx, -0.29f);
    glEnd();
}
void road(float offsetx){
    glColor3f(52.0f / 255.0f, 50.0f / 255.0f, 51.0f / 255.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.11f+offsetx, -0.29f);
        glVertex2f(-0.5f+offsetx, -1.5f);
        glVertex2f(0.5f+offsetx, -1.5f);
        glVertex2f(0.11f+offsetx, -0.29f);
    glEnd();
    glColor3f(234.0f / 255.0f, 234.0f / 255.0f, 234.0f / 255.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.003f+offsetx, -0.29f);
        glVertex2f(-0.05f+offsetx, -1.5f);
        glVertex2f(0.05f+offsetx, -1.5f);
        glVertex2f(0.003f+offsetx, -0.29f);
    glEnd();

}
void grass2(float x, float y){
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0, 102 + x, 0 + y);


    glVertex2f(0.01f + x - 0.005, -0.35f + y - 0.005);
    glVertex2f(0.0f + x - 0.005, -0.4f + y - 0.005); //

    glVertex2f(0.0135f + x - 0.005, -0.33f + y - 0.005);
    glVertex2f(0.0f + x - 0.005, -0.4f + y - 0.005); //

    glVertex2f(-0.0135f + x - 0.005, -0.33f + y - 0.005);
    glVertex2f(0.0f + x - 0.005, -0.4f + y - 0.005); //

    glVertex2f(0.0f + x - 0.005, -0.3f + y - 0.005);
    glVertex2f(0.0f + x - 0.005, -0.4f + y - 0.005); //

    glVertex2f(-0.04f + x - 0.005, -0.37f + y - 0.005);
    glVertex2f(0.0f + x - 0.005, -0.4f + y - 0.005); //

    glVertex2f(0.0375f + x - 0.005, -0.37f + y - 0.005);
    glVertex2f(0.0f + x - 0.005, -0.4f + y - 0.005); //

    glEnd();
}
void grass1(float x,float y){
    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(0, 102+x, 0+y);
	glVertex2f(-.05f+x, -0.35f+y);
	glVertex2f(-0.0f+x, -0.4f+y);//
	glVertex2f(0.05f+x, -0.35f+y);
	glVertex2f(0.0f+x, -0.4f+y);//
	glVertex2f(0.027f+x, -0.33f+y);
	glVertex2f(0.0f+x, -0.4f+y);//
	glVertex2f(-0.027f+x, -0.33f+y);
	glVertex2f(0.0f+x, -0.4f+y);//
	glVertex2f(0.0f+x, -0.3f+y);
	glVertex2f(0.0f+x, -0.4f+y);//
	glVertex2f(-0.075f+x, -0.37f+y);
	glVertex2f(-0.0f+x, -0.4f+y);//
	glVertex2f(0.0745f+x, -0.37f+y);
	glVertex2f(-0.0f+x, -0.4f+y);//
    glEnd();
	glEnd();
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float offsetX = -0.2f; // Move everything left

    // Background Color
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    soil();

    drawRiver();
    // Roof
    drawWave2();
    drawWave3();
    drawWave4();
    drawWave5();
    drawWave6();
    drawWave7();
    drawWave8();
    drawWave9();
    boat2();
    boat4();
    glColor3f(0.506f, 0.502f, 0.427f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53f + offsetX, 0.23f);
        glVertex2f(0.53f + offsetX, 0.23f);
        glVertex2f(0.53f + offsetX, 0.27f);
        glVertex2f(-0.53f + offsetX, 0.27f);
    glEnd();

    // Top floor
    glColor3f(0.667f, 0.522f, 0.271f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f + offsetX, 0.27f);
        glVertex2f(0.5f + offsetX, 0.27f);
        glVertex2f(0.5f + offsetX, 0.7f);
        glVertex2f(-0.5f + offsetX, 0.7f);
    glEnd();

    rightWindowTop(offsetX);
    centerWindowTop(offsetX);
    leftWindowTop(offsetX);

    glColor3f(0.506f, 0.502f, 0.427f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.53f + offsetX, 0.7f);
        glVertex2f(0.53f + offsetX, 0.7f);
        glVertex2f(0.53f + offsetX, 0.75f);
        glVertex2f(-0.53f + offsetX, 0.75f);
    glEnd();

    glColor3f(0.498f, 0.306f, 0.329f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.45f + offsetX, 0.75f);
        glVertex2f(0.45f + offsetX, 0.75f);
        glVertex2f(0.45f + offsetX, 0.85f);
        glVertex2f(-0.45f + offsetX, 0.85f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText("Premier University, Chittagong", -0.37f + offsetX, 0.78f);
    drawWave();

    stair(offsetX);
    road(offsetX);

    // Down floor
    drawMan(manX + offsetX, manY);

    glColor3f(0.667f, 0.522f, 0.271f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f + offsetX, -0.2f);
        glVertex2f(0.5f + offsetX, -0.2f);
        glVertex2f(0.5f + offsetX, 0.23f);
        glVertex2f(-0.5f + offsetX, 0.23f);
    glEnd();

    rightWindow(offsetX);
    leftWindow(offsetX);
    door(offsetX);
    drawContinuousHills();
    grass1(0,0);
    grass1(0.2,-0.2);
    grass1(0.5,-0.2);
    grass1(0.6,-0.7);
    grass1(-0.5,-0.2);
    grass1(-0.9,-0.3);
    grass1(-1.0,-0.5);
    grass1(-0.9,-0.7);
    grass1(-1.2,-0.1);
    grass1(-1.4,0.1);
    grass1(1.3,-0.5);
    grass1(1.2,-0.7);
    grass1(0.9,-0.4);
    grass1(0.8,-0.7);
    grass1(0.8,-0.3);


    grass2(0.8,1.2);
    grass2(0.9,1.3);
    grass2(1.0,1.2);
    grass2(1.3,1.3);
    grass2(-1.3,1.3);
    grass2(-0.5,1.3);

    //drawTree(0.0f, -0.5f, 0.3f, 0.15f);  // Draw a tree at (0.0, -0.5) with trunk height 0.3 and canopy size 0.15
    tree(-0.5f, 0.0f);
    sun();

    drawCloud(0.0f, 1.5f);

    glFlush();
}


void update(int value){
    waveOffset-=0.01f;
    if(waveOffset<-1.5f)waveOffset=1.5f;
    dx-=0.01f;
    if(dx==1.5f)dx=0.6f;
    if (isMoving) {
        if (manX < -0.05f){
            manX += 0.01f; // Move right
        }
        if (manY < 0.9f) {
            manY += 0.01f; // Move up
        }
        if (manY >= 0.6f) {
            isMoving = false; // Stop moving when reaching the door
        }
    }
    glutPostRedisplay();
        glutTimerFunc(50, update, 0);
}
void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("University");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(50, update, 0);
    glutMainLoop();
    return 0;
}
