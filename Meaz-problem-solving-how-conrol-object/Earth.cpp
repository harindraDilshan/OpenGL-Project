#include <GL/glut.h>
#include <SOIL2.h>
#include <iostream>
#include "globals.h"


unsigned char* image5;  // For texture
GLuint earthtex;            // For texture ID
int width5, height5;     // Texture dimensions

void loadEarthtextures() {
    // Generate a texture ID
    glGenTextures(1, &earthtex);
    glBindTexture(GL_TEXTURE_2D, earthtex);

    // Load the texture image
    image5 = SOIL_load_image("8k_earth_daymap.jpg", &width5, &height5, 0, SOIL_LOAD_RGB);
    if (image5 == NULL) {
        std::cerr << "Error loading texture: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width5, height5, 0, GL_RGB, GL_UNSIGNED_BYTE, image5);

    // Free the image from memory
    SOIL_free_image_data(image5);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawEarthWithoutAnimation() {
    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, earthtex);

    // Create a GLUquadric object
    GLUquadric* quad = gluNewQuadric();

    // Enable texture mapping for the quadric
    gluQuadricTexture(quad, GL_TRUE);

    // Draw the sphere
    gluSphere(quad, 20.0, 32, 32);

    // Delete the quadric object
    gluDeleteQuadric(quad);

    // Disable texture mapping
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void drawEarth() {
    glPushMatrix();
    glRotatef(frameNumber * 0.1, 0, 1, 0);
    drawEarthWithoutAnimation();
    glPopMatrix();
}
