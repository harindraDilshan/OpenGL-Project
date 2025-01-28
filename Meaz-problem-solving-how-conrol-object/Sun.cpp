#include <GL/glut.h>
#include <SOIL2.h>
#include <iostream>

unsigned char* image1;  // For texture
GLuint suntex;            // For texture ID
int width1, height1;     // Texture dimensions

void loadSunTextures() {
    // Generate a texture ID
    glGenTextures(1, &suntex);
    glBindTexture(GL_TEXTURE_2D, suntex);

    // Load the texture image
    image1 = SOIL_load_image("8k_sun.jpg", &width1, &height1, 0, SOIL_LOAD_RGB);
    if (image1 == NULL) {
        std::cerr << "Error loading texture: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width1, height1, 0, GL_RGB, GL_UNSIGNED_BYTE, image1);

    // Free the image from memory
    SOIL_free_image_data(image1);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawSun() {
    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, suntex);

    // Create a GLUquadric object
    GLUquadric* quad = gluNewQuadric();

    // Enable texture mapping for the quadric
    gluQuadricTexture(quad, GL_TRUE);

    // Draw the sphere
    gluSphere(quad, 50.0, 32, 32);

    // Delete the quadric object
    gluDeleteQuadric(quad);

    // Disable texture mapping
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}
