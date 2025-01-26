#include "API.h"

// Define the shared variables
double cubeX = 1.0;
double cubeY = 0.0;
double cubeZ = 1.0;

// Function to set the cube position
void setCubePosition(double x, double y, double z) {
    cubeX = x;
    cubeY = y;
    cubeZ = z;
}

// Function to get the current cube position
void getCubePosition(double& x, double& y, double& z) {
    x = cubeX;
    y = cubeY;
    z = cubeZ;
}