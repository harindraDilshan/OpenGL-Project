#include <GL/glut.h>
#include <SOIL2.h>
#include <iostream>

unsigned char* image2;  // For texture
GLuint skytex;            // For texture ID
int width2, height2;     // Texture dimensions

void loadSkyTextures() {
    // Generate a texture ID
    glGenTextures(1, &skytex);
    glBindTexture(GL_TEXTURE_2D, skytex);

    // Load the texture image
    image2 = SOIL_load_image("8k_stars_milky_way.jpg", &width2, &height2, 0, SOIL_LOAD_RGB);
    if (image2 == NULL) {
        std::cerr << "Error loading texture: " << SOIL_last_result() << std::endl;
        exit(EXIT_FAILURE);
    }

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    // Upload texture data to GPU
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width2, height2, 0, GL_RGB, GL_UNSIGNED_BYTE, image2);

    // Free the image from memory
    SOIL_free_image_data(image2);

    // Unbind the texture
    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawSky() {
    // Enable texture mapping
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, skytex);

    // Create a GLUquadric object
    GLUquadric* quad = gluNewQuadric();

    // Enable texture mapping for the quadric
    gluQuadricTexture(quad, GL_TRUE);

    // Draw the sphere
    gluSphere(quad, 150.0, 32, 32);

    // Delete the quadric object
    gluDeleteQuadric(quad);

    // Disable texture mapping
    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
}
