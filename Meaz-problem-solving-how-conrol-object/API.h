#ifndef API_H
#define API_H


// Test code
void drawSecondCube();

// Controling cube
void controlCube();

// Timer unction
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


// Add lighting
void setLightingAndShading();

void InitializeTerrain();
void addRandomValues();
//void SmoothTerrain();

void drawRandomMountance();


#endif // API_H