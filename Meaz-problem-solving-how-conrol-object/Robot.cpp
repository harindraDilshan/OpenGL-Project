#include <GL/glut.h>
#include <SOIL2.h>
#include <iostream>
#include "globals.h"

unsigned char* image3;  // For texture
GLuint robotex;            // For texture ID
int width3, height3;     // Texture dimensions

void loadRoboTextures() {
    // Generate a texture ID
    glGenTextures(1, &robotex);
    glBindTexture(GL_TEXTURE_2D, robotex);

    // Load the texture image
    image3 = SOIL_load_image("ball-robot-tex.png", &width3, &height3, 0, SOIL_LOAD_RGB);
    if (image3 == NULL) {
        std::cerr << "Error loading texture: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width3, height3, 0, GL_RGB, GL_UNSIGNED_BYTE, image3);

    // Free the image from memory
    SOIL_free_image_data(image3);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawRoboWithoutAnination() {
    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, robotex);

    // Create a GLUquadric object
    GLUquadric* quad = gluNewQuadric();

    // Enable texture mapping for the quadric
    gluQuadricTexture(quad, GL_TRUE);

    // Draw the sphere
    gluSphere(quad, 1.0, 32, 32);

    // Delete the quadric object
    gluDeleteQuadric(quad);

    // Disable texture mapping
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void drawRobotHead() {
    glPushMatrix();
    glTranslatef(0, 2.0, 0);
    glScalef(0.5, 0.5, 0.5);
    drawRoboWithoutAnination();
    glPopMatrix();

}


void drawRobo() {
    drawRobotHead();
    glPushMatrix();
    glTranslatef(0, 1.0, 0);
    glRotatef(frameNumber * 2 ,1, 0, 0);
    drawRoboWithoutAnination();
    glPopMatrix();
}