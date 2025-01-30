#ifndef API_H
#define API_H
#include<string>

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

void drawFlow(double x, double y, double z);

int getNumberOfLinse();

std::string* generateGridArray();

void drawRover();

void loadTextures();

void loadSunTextures();
void drawSun();

void loadSkyTextures();
void drawSky();

void loadRoboTextures();
void drawRobo();

void loadFlagTextures();
void drawFlag();

void loadEarthtextures();
void drawEarth();

void drawRoverSet();

void timer2(int v);

void keyboardSpecial(int key, int x, int y);

void keyboard(unsigned char key, int x, int y);

#endif // API_H