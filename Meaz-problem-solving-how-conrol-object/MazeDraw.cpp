#include <GL/glut.h>
#include<string>
#include<iostream>
#include "API.h"

// [row][col]
std::string grid[20] = {
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


void oneEntity() {
	glPushMatrix();
	glScalef(0.1, 0.1, 0.1);
	drawRandomMountance();
	glPopMatrix();
}

void drawCube(double x, double y, double z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	oneEntity();
	glPopMatrix();
}


void drawMaze() {
	int numOfRows = 20;
	int numofcols = 46;

	for (int z = 0; z < numofcols; z++) {
		for (int x = 0; x < numOfRows; x++) {
			char character = grid[x][z];
			double screen_x = x;
			double screen_z = z;

			if (character == '+') {
				glColor3f(0, 1, 0);
				drawCube(screen_x, 0, screen_z);
			}
			if (character == 'e') {
				glColor3f(1, 0, 0);
				drawCube(screen_x, 0, screen_z);
				std::cout << "Cube Position: (" << screen_x << ", " << screen_z << ")" << std::endl;
			}
		}
		// std::cout << grid[i] << "\n";
	}
}