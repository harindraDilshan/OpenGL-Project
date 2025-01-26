#include <GL/glut.h>
#include "API.h"
#include <iostream>

int frameNumber = 0;
void timer(int v) {
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}


// End pos : (23, 19)

static std::string grid[20] = {
    "++++++++++++++++++++++++++++++++++++++++++++++",
    "+ s             +                            +",
    "+  ++++++++++  +++++++++++++  +++++++  ++++  +",
    "+           +                 +        +     +",
    "+  +++++++  +++++++++++++  +++++++++++++++++++",
    "+  +     +  +           +  +                 +",
    "+  +  +  +  +  +  ++++  +  +  +++++++++++++  +",
    "+  +  +  +  +  +  +     +  +  +  +        +  +",
    "+  +  ++++  +  ++++++++++  +  +  ++++  +  +  +",
    "+  +     +  +              +           +  +  +",
    "+  ++++  +  ++++++++++++++++  +++++++++++++  +",
    "+     +  +                    +              e",
    "++++  +  ++++++++++++++++++++++  ++++++++++  +",
    "+  +  +                    +     +     +  +  +",
    "+  +  ++++  +++++++++++++  +  ++++  +  +  +  +",
    "+  +  +     +     +     +  +  +     +     +  +",
    "+  +  +  +++++++  ++++  +  +  +  ++++++++++  +",
    "+                       +  +  +              +",
    "++++  +  +  ++++++++++  +  +  +  +++++++++++++",
    "++++++++++++++++++++++++++++++++++++++++++++++",
};


double endposX = 23;
double endposZ = 19;


std::pair<int, int> currentPosition = { 1, 1 };
std::string currentDirection = "EAST";

// Determine the coordinates of the cell to the left
std::pair<int, int> getLeftCell() {
    int x = currentPosition.first;
    int z = currentPosition.second;

    if (currentDirection == "NORTH") return { x - 1, z };
    if (currentDirection == "EAST") return { x, z - 1};
    if (currentDirection == "SOUTH") return { x + 1, z };
    if (currentDirection == "WEST") return { x, z + 1 };
    return { x, z };
}

// Determine the coordinates of the cell in front
std::pair<int, int> getFrontCell() {
    int x = currentPosition.first;
    int z = currentPosition.second;

    if (currentDirection == "NORTH") return { x, z - 1 };
    if (currentDirection == "EAST") return { x + 1, z};
    if (currentDirection == "SOUTH") return { x, z + 1};
    if (currentDirection == "WEST") return { x - 1, z};
    return { x, z };
}

// Check specific conditions
bool checkConditions(const std::string& condition) {
    int x = currentPosition.first;
    int z = currentPosition.second;

    if (condition == "END") {
        return grid[x][z] == 'e';
    }
    else if (condition == "WALL_LEFT") {
        // auto [leftX, leftY] = getLeftCell();
        return grid[getLeftCell().first][getLeftCell().second] == '+'; // Wall to the left
    }
    else if (condition == "FREE_FRONT") {
        // auto [frontX, frontY] = getFrontCell();
        return grid[getLeftCell().first][getLeftCell().second] != '+'; // Not a wall
    }
    return false;
}

// Move the cube forward
void moveCubeForward() {
    if (currentDirection == "NORTH") { currentPosition.second--; setCubePosition(currentPosition.first, 0, currentPosition.second); }
    else if (currentDirection == "EAST") { currentPosition.first++; setCubePosition(currentPosition.first, 0, currentPosition.second); }
    else if (currentDirection == "SOUTH") { currentPosition.second++; setCubePosition(currentPosition.first, 0, currentPosition.second); }
    else if (currentDirection == "WEST") { currentPosition.first--; setCubePosition(currentPosition.first, 0, currentPosition.second); }
}

// Rotate the cube counter-clockwise
void rotateCubeCCW() {
    if (currentDirection == "NORTH") currentDirection = "WEST";
    else if (currentDirection == "WEST") currentDirection = "SOUTH";
    else if (currentDirection == "SOUTH") currentDirection = "EAST";
    else if (currentDirection == "EAST") currentDirection = "NORTH";
}

// Rotate the cube clockwise
void rotateCubeCW() {
    if (currentDirection == "NORTH") currentDirection = "EAST";
    else if (currentDirection == "EAST") currentDirection = "SOUTH";
    else if (currentDirection == "SOUTH") currentDirection = "WEST";
    else if (currentDirection == "WEST") currentDirection = "NORTH";
}



void controlCube() {

    double x, y, z;
    getCubePosition(x, y, z);
    currentPosition = { x, z };
    // controlLogic(x, z);

    std::cout << getLeftCell().first;
    std::cout << getLeftCell().second;

    // std::cout << checkConditions("WALL_LEFT");
    // moveCubeForward();

    // rotateCubeCCW();

    //// To reduce the frome speed /////
    static int moveDelayCounter = 0;

    if (++moveDelayCounter < 5) { // Adjust this number for further delay
        return; // Skip cube control logic for this cycle
    }
    moveDelayCounter = 0;

    //////////////////////////////////

    // Check if the endpoint is reached
    if (checkConditions("END")) {
        /*std::cout << x << std::endl;
        std::cout << z << std::endl;*/
        return;
    }

    // Follow left-hand wall-following logic
    if (!checkConditions("WALL_LEFT")) {
        rotateCubeCCW();
        moveCubeForward();
    }
    else if (checkConditions("FREE_FRONT")) {
        moveCubeForward();
    }
    else {
        rotateCubeCW();
    }
}