#include <GL/glut.h>
#include <SOIL2.h>
#include <iostream>

unsigned char* image;  // For texture
GLuint tex;            // For texture ID
int width, height;     // Texture dimensions

void loadTextures() {
    // Generate a texture ID
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    // Load the texture image
    image = SOIL_load_image("2k_moon.jpg", &width, &height, 0, SOIL_LOAD_RGB);
    if (image == NULL) {
        std::cerr << "Error loading texture: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    // Free the image from memory
    SOIL_free_image_data(image);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawSurface() {
    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex);

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

void drawFlow(double x, double y, double z) {
    glPushMatrix();
    glScalef(x, y, z);
    // glColor3f(1, 1, 0);  // This color is ignored when the texture is applied
    drawSurface();
    glPopMatrix();
}
