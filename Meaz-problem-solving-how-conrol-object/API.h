#ifndef API_H
#define API_H


void drawCube();

void controlCube(); // Declare the function

void timer(int v);


// Extern declarations for shared variables
extern double cubeX; // Position of the cube
extern double cubeY;
extern double cubeZ;

// Function declarations
void setCubePosition(double x, double y, double z);
void getCubePosition(double& x, double& y, double& z);

// Deine the drawMaze method
void drawMaze();

#endif // API_H