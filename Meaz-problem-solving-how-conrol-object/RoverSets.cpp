#include <GL/glut.h>
#include <math.h>
#include "API.h"
#include <stdio.h>
#include "globals.h"


int frameNumber2 = 0;
int direction = 0;  // 0: right, 1: up, 2: left, 3: down

void timer2(int v) {
	frameNumber2++;
	glutPostRedisplay();
	glutTimerFunc(30, timer2, 0);
}

float squareSize = 100.0f;
void drawMovingRover1() {
	glPushMatrix();

	// Calculate the maximum steps for each side
	int stepsPerSide = 500;  // You can adjust this for speed
	float stepSize = squareSize / stepsPerSide;

	// Calculate current position and rotation
	float x = 0.0f, z = 0.0f;
	float rotation = 0.0f;

	// Determine which side of the square we're on
	int currentSide = (frameNumber2 / stepsPerSide) % 4;
	int progress = frameNumber2 % stepsPerSide;

	switch (currentSide) {
	case 0: // Moving right
		x = progress * stepSize - (squareSize / 2);
		z = -squareSize / 2;
		rotation = 0.0f;
		break;
	case 1: // Moving up
		x = squareSize / 2;
		z = progress * stepSize - (squareSize / 2);
		rotation = -90.0f;
		break;
	case 2: // Moving left
		x = squareSize / 2 - (progress * stepSize);
		z = squareSize / 2;
		rotation = -180.0f;
		break;
	case 3: // Moving down
		x = -squareSize / 2;
		z = squareSize / 2 - (progress * stepSize);
		rotation = -270.0f;
		break;
	}

	// Position and rotate the rover
	glTranslatef(x, 1.5f, z);
	glRotatef(rotation, 0, 1, 0);

	// Draw the rover
	drawRover();

	glPopMatrix();
}


float squareSize2 = 100.0f;
void drawMovingRover2() {
	glPushMatrix();

	// Calculate the maximum steps for each side
	int stepsPerSide = 1000;  // You can adjust this for speed
	float stepSize = squareSize2 / stepsPerSide;

	// Calculate current position and rotation
	float x = 0.0f, z = 0.0f;
	float rotation = 0.0f;

	// Determine which side of the square we're on
	int currentSide = (frameNumber2 / stepsPerSide) % 4;
	int progress = frameNumber2 % stepsPerSide;

	switch (currentSide) {
	case 0: // Moving right
		x = progress * stepSize - (squareSize2 / 2);
		z = -squareSize2 / 2;
		rotation = 0.0f;
		break;
	case 1: // Moving up
		x = squareSize2 / 2;
		z = progress * stepSize - (squareSize2 / 2);
		rotation = -90.0f;
		break;
	case 2: // Moving left
		x = squareSize2 / 2 - (progress * stepSize);
		z = squareSize2 / 2;
		rotation = -180.0f;
		break;
	case 3: // Moving down
		x = -squareSize2 / 2;
		z = squareSize2 / 2 - (progress * stepSize);
		rotation = -270.0f;
		break;
	}

	// Position and rotate the rover
	glTranslatef(x, 1.5f, z);
	glRotatef(rotation, 0, 1, 0);

	// Draw the rover
	drawRover();

	glPopMatrix();
}

float squareSize3 = 150.0f;
void drawMovingRover3() {
	glPushMatrix();

	// Calculate the maximum steps for each side
	int stepsPerSide = 100;  // You can adjust this for speed
	float stepSize = squareSize3 / stepsPerSide;

	// Calculate current position and rotation
	float x = 0.0f, z = 0.0f;
	float rotation = 0.0f;

	// Determine which side of the square we're on
	int currentSide = (frameNumber2 / stepsPerSide) % 4;
	int progress = frameNumber2 % stepsPerSide;

	switch (currentSide) {
	case 0: // Moving right
		x = progress * stepSize - (squareSize3 / 2);
		z = -squareSize3 / 2;
		rotation = 0.0f;
		break;
	case 1: // Moving up
		x = squareSize3 / 2;
		z = progress * stepSize - (squareSize3 / 2);
		rotation = -90.0f;
		break;
	case 2: // Moving left
		x = squareSize3 / 2 - (progress * stepSize);
		z = squareSize3 / 2;
		rotation = -180.0f;
		break;
	case 3: // Moving down
		x = -squareSize3 / 2;
		z = squareSize3 / 2 - (progress * stepSize);
		rotation = -270.0f;
		break;
	}

	// Position and rotate the rover
	glTranslatef(x, 1.5f, z);
	glRotatef(rotation, 0, 1, 0);

	// Draw the rover
	drawRover();

	glPopMatrix();
}

float squareSize4 = 100.0f;
void drawMovingRover4() {
	glPushMatrix();

	// Calculate the maximum steps for each side
	int stepsPerSide = 50;  // You can adjust this for speed
	float stepSize = squareSize4 / stepsPerSide;

	// Calculate current position and rotation
	float x = 0.0f, z = 0.0f;
	float rotation = 0.0f;

	// Determine which side of the square we're on
	int currentSide = (frameNumber2 / stepsPerSide) % 4;
	int progress = frameNumber2 % stepsPerSide;

	switch (currentSide) {
	case 0: // Moving right
		x = progress * stepSize - (squareSize4 / 2);
		z = -squareSize4 / 2;
		rotation = 0.0f;
		break;
	case 1: // Moving up
		x = squareSize4 / 2;
		z = progress * stepSize - (squareSize4 / 2);
		rotation = -90.0f;
		break;
	case 2: // Moving left
		x = squareSize4 / 2 - (progress * stepSize);
		z = squareSize4 / 2;
		rotation = -180.0f;
		break;
	case 3: // Moving down
		x = -squareSize4 / 2;
		z = squareSize4 / 2 - (progress * stepSize);
		rotation = -270.0f;
		break;
	}

	// Position and rotate the rover
	glTranslatef(x, 1.5f, z);
	glRotatef(rotation, 0, 1, 0);

	// Draw the rover
	drawRover();

	glPopMatrix();
}


void drawRoverSet() {
	drawMovingRover1();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	drawMovingRover2();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawMovingRover3();
	glPopMatrix();

	glPushMatrix();
	glRotatef(100, 0, 1, 0);
	drawMovingRover4();
	glPopMatrix();
}