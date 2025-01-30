#include "globals.h"

// Define global variables
int numOfLines = 0;
extern std::string* grid = {};
std::string currentDirection = "EAST";
extern int frameNumber = 0;

//variables to move the camera
extern GLfloat camX = 0.0; extern GLfloat camY = 0.0; extern GLfloat camZ = 0.0;

//variables to move the scene
extern GLfloat sceRX = 0.0; extern GLfloat sceRY = 0.0; extern GLfloat sceRZ = 0.0;
extern GLfloat sceTX = 0.0; extern GLfloat sceTY = 0.0; extern GLfloat sceTZ = 0.0;

////variables to move the objects
extern GLfloat objRX = 0.0; extern GLfloat objRY = 0.0; extern GLfloat objRZ = 0.0;
extern GLfloat objTX = 0.0; extern GLfloat objTY = 0.0; extern GLfloat objTZ = 0.0;