#ifndef GLOBALS_H
#define GLOBALS_H
#include <GL/glut.h>
#include <string>
#include <vector>

// Declare variables as extern
extern int numOfLines;
extern std::string* grid;
extern std::string currentDirection;
extern int frameNumber;

//variables to move the camera
extern GLfloat camX; extern GLfloat camY; extern GLfloat camZ;

//variables to move the scene
extern GLfloat sceRX; extern GLfloat sceRY; extern GLfloat sceRZ;
extern GLfloat sceTX; extern GLfloat sceTY; extern GLfloat sceTZ;

////variables to move the objects
extern GLfloat objRX; extern GLfloat objRY; extern GLfloat objRZ;
extern GLfloat objTX; extern GLfloat objTY; extern GLfloat objTZ;

#endif
