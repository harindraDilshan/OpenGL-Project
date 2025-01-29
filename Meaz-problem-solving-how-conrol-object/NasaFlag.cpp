#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <SOIL2.h>
#include <iostream>
#include "globals.h"


unsigned char* image4;  // For texture
GLuint flagtex;            // For texture ID
int width4, height4;     // Texture dimensions

void loadFlagTextures() {
    // Generate a texture ID
    glGenTextures(1, &flagtex);
    glBindTexture(GL_TEXTURE_2D, flagtex);

    // Load the texture image
    image4 = SOIL_load_image("nasa_logo.png", &width4, &height4, 0, SOIL_LOAD_RGB);
    if (image4 == NULL) {
        std::cerr << "Error loading texture: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width4, height4, 0, GL_RGB, GL_UNSIGNED_BYTE, image4);

    // Free the image from memory
    SOIL_free_image_data(image4);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawCylinderFroFlag(double length, double radius1, double radius2) {

	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, radius2, radius1, length, 100, 100);

}

void drawFlagWithoutBar() {
    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, flagtex);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    // For each vertex, specify texture coordinates (glTexCoord2f) 
    // before the vertex position (glVertex3f)
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0, 0, 0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0, 2.0, 0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0, 2.0, 0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0, 0, 0);
    glEnd();

    // Disable texture mapping
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}

void drawFlag() {

    glPushMatrix();
    glTranslatef(0, 8.0, 0);
    drawFlagWithoutBar();
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90, 1, 0, 0);
    glColor3f(0, 0, 0);
    drawCylinderFroFlag(10.0, 0.2, 0.2);
    glPopMatrix();
}