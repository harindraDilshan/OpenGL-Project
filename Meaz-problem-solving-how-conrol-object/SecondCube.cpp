#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <iostream>


#define MAP_X 25    // Width of terrain
#define MAP_Z 25    // Depth of terrain
#define MAP_SCALE 0.5f // Scale of terrain
#define AMPLITUDE 0.5f
// Terrain height map
float terrain[MAP_X][MAP_Z];

// Random function for roughness
float RandomHeight(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

// Initialize terrain with roughness
void InitializeTerrain() {
    srand(time(0)); // Seed for random heights
    for (int z = 0; z < MAP_Z; z++) {
        for (int x = 0; x < MAP_X; x++) {
            // Base height with some randomness
            terrain[x][z] = sin((float)x / MAP_X * 3.14f) * 3.0f
                + cos((float)z / MAP_Z * 3.14f) * 2.0f
                + RandomHeight(-1.0f, 1.0f) * AMPLITUDE; // Adds natural roughness
        }
    }
}

float randomRotateValues[4];

float radomTranslateXValues[4];
float radomTranslateYValues[4];
float radomTranslateZValues[4];

float randomScaleYValues[4];

float getRandomValue(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

void addRandomValues() {
    for (int i = 0; i < 4; i++) {
        randomRotateValues[i] = getRandomValue(0, 180);
        radomTranslateXValues[i] = getRandomValue(0, 1);
        radomTranslateYValues[i] = getRandomValue(0, 1);
        radomTranslateZValues[i] = getRandomValue(0, 1);
        randomScaleYValues[i] = getRandomValue(0.5, 1);
    }
}

void SmoothTerrain() {
    float temp[MAP_X][MAP_Z];

    for (int z = 1; z < MAP_Z - 1; z++) {
        for (int x = 1; x < MAP_X - 1; x++) {
            // Average the height with neighbors
            temp[x][z] = (terrain[x][z]
                + terrain[x - 1][z]
                + terrain[x + 1][z]
                + terrain[x][z - 1]
                + terrain[x][z + 1]) / 5.0f;
        }
    }

    // Copy smoothed values back to the terrain array
    for (int z = 1; z < MAP_Z - 1; z++) {
        for (int x = 1; x < MAP_X - 1; x++) {
            terrain[x][z] = temp[x][z];
        }
    }
}

void drawTerrain() {
    // Draw terrain
    for (int z = 0; z < MAP_Z - 1; z++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int x = 0; x < MAP_X; x++) {
            // Vertex 1
            glColor3f(0.8f, terrain[x][z] / 5.0f + 0.5f, 0.0f);
            glVertex3f(x * MAP_SCALE, terrain[x][z], z * MAP_SCALE);

            // Vertex 2
            glColor3f(0.0f, terrain[x][z + 1] / 5.0f + 0.5f, 0.0f);
            glVertex3f(x * MAP_SCALE, terrain[x][z + 1], (z + 1) * MAP_SCALE);
        }
        glEnd();
    }
}

void drawMountan() {
    glPushMatrix();
    glScalef(1, 2.0, 1);
    drawTerrain();
    glPopMatrix();

    glPushMatrix();
    glScalef(1, 2.0, 1);
    glRotatef(180, 0, 1, 0);
    glTranslatef(-MAP_X / 2, 0, -0.3);
    drawTerrain();
    glPopMatrix();
}

void drawRandomMountance() {

    glPushMatrix();
    glScalef(1, randomScaleYValues[0], 1);
    glRotatef(randomRotateValues[0], 0, 1, 0);
    glTranslatef(radomTranslateXValues[0], radomTranslateYValues[0], radomTranslateZValues[0]);
    drawMountan();
    glPopMatrix();


    glPushMatrix();
    glScalef(1, randomScaleYValues[1], 1);
    glRotatef(randomRotateValues[1], 0, 1, 0);
    glTranslatef(radomTranslateXValues[1], radomTranslateYValues[1], radomTranslateZValues[1]);
    drawMountan();
    glPopMatrix();


    glPushMatrix();
    glScalef(1, randomScaleYValues[2], 1);
    glRotatef(randomRotateValues[2], 0, 1, 0);
    glTranslatef(radomTranslateXValues[2], radomTranslateYValues[2], radomTranslateZValues[2]);
    drawMountan();
    glPopMatrix();


    glPushMatrix();
    glScalef(1, randomScaleYValues[3], 1);
    glRotatef(randomRotateValues[3], 0, 1, 0);
    glTranslatef(radomTranslateXValues[3], radomTranslateYValues[3], radomTranslateZValues[3]);
    drawMountan();
    glPopMatrix();
}
