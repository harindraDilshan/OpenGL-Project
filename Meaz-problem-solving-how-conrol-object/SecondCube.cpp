#include <GL/glut.h>
#include <random>   // For modern random number generation
#include <ctime>    // For time-based seed

const int gridSize = 20;  // Define the size of the terrain grid
float heightMap[gridSize][gridSize];  // Array to store cube height values

// Function to draw a scaled cube at a specific position with given height
void drawScaledCube(double x, double y, double z, double scaleY) {
    glPushMatrix();
    glTranslatef(x, y + scaleY / 2.0, z);  // Adjust cube position based on height
    glScalef(1.0, scaleY, 1.0);  // Scale the cube along the y-axis
    glutSolidCube(1.0);
    glPopMatrix();
}

// Function to generate random terrain heights using C++ <random>
void generateHeightMap() {
    std::random_device rd;  // Seed for random generator
    std::mt19937 gen(rd());  // Mersenne Twister random number engine
    std::uniform_real_distribution<> dis(0.5, 3.0);  // Random height range [0.5, 3.0]

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            heightMap[i][j] = dis(gen);  // Assign random heights to the grid
        }
    }
}

// Function to render the terrain using scaled cubes
void renderTerrain() {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            float x = i - gridSize / 2.0;  // Center the terrain
            float z = j - gridSize / 2.0;
            drawScaledCube(x, 0, z, heightMap[i][j]);
        }
    }
}



void drawSecondCube() {
    renderTerrain();
}