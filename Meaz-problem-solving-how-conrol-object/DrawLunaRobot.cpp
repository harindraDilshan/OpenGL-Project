#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void drawCylinder(double length, double radius1, double radius2) {
	// glPushMatrix();
	// glTranslatef(0, .5, 0);
	// glScalef(1, 1, 1);
	// glRotatef(-90.0, 1, 0, 0);

	GLUquadric* quad = gluNewQuadric();
	gluCylinder(quad, radius2, radius1, length, 100, 100);

	// glPopMatrix();
}

void drawSphare(double radius) {
	glPushMatrix();

	// Scale the sphere to create an egg shape
	glScalef(1.0, 1.2, 1.0); // Stretch along the Y-axis

	// Rotate to adjust orientation if needed
	glRotatef(-90.0, 1, 0, 0);

	// Create and draw the scaled sphere
	GLUquadric* quad = gluNewQuadric();
	gluSphere(quad, radius, 100, 100);

	glPopMatrix();
}

void drawRing(double innerRadius, double outerRadius) {
	glutSolidTorus(innerRadius, outerRadius, 100, 100);
}



double radiusOfWeel = 1.5;
double widthOfWeel = 1.5;
double lenghtOfWeelAxis = widthOfWeel * 5;
double radiusOfWeelAxis = 0.2;
// Draw weel
void drawWeel() {
	glColor3f(0.0, 0.0, 0.0);
	drawCylinder(widthOfWeel, radiusOfWeel, radiusOfWeel);
	// weelCup 1
	glColor3f(0.2, 0.2, 0.3);
	drawCylinder(widthOfWeel - 0.5, 0, radiusOfWeel);

	// WeelCup 2
	glPushMatrix();
	glTranslatef(0, 0, widthOfWeel);
	glRotatef(-180, 0, 1, 0);
	glColor3f(0.2, 0.2, 0.3);
	drawCylinder(widthOfWeel - 0.5, 0, radiusOfWeel);
	glPopMatrix();

	// axis cup 1
	glColor3f(0.2, 0.2, 0.3);
	drawCylinder(widthOfWeel - 0.8, 0, radiusOfWeelAxis);

	// axis cup 2
	glPushMatrix();
	glTranslatef(0, 0, widthOfWeel);
	glRotatef(-180, 0, 1, 0);
	glColor3f(0.2, 0.2, 0.3);
	drawCylinder(widthOfWeel - 0.8, 0, radiusOfWeelAxis);
	glPopMatrix();

}


// Draw weel axis
void drawWeelAxis() {
	glColor3f(0, 0, 0);
	drawCylinder(lenghtOfWeelAxis, radiusOfWeelAxis, radiusOfWeelAxis);
}

// Draw weel with axis
void drawWellWithAxis() {

	glColor3f(0, 1, 0);
	drawWeel();

	glColor3f(0, 0, 1);
	drawWeelAxis();

	glPushMatrix();
	glTranslatef(0, 0, lenghtOfWeelAxis - widthOfWeel);
	glColor3f(0, 1, 0);
	drawWeel();
	glPopMatrix();
}

// Draw weel system
double seperation1 = 3.5;
double seperation2 = 5.0;
void drawWeelSystem() {
	drawWellWithAxis();

	glPushMatrix();
	glTranslatef(seperation1, 0, 0);
	drawWellWithAxis();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(seperation1 + seperation2, 0, 0);
	drawWellWithAxis();
	glPopMatrix();
}


void drawPoygon(double array[][3], int number_of_vertext) {
	glBegin(GL_POLYGON);
	for (int i = 0; i <= number_of_vertext; i++) {
		glVertex3f(array[i][0], array[i][1], array[i][2]);
	}
	glEnd();
}

double bottomPartLenght = seperation1 + seperation2 + 1.0;
double bottomPartWidth = lenghtOfWeelAxis / 2;
/// double height = bottomPartWidth/2;
double PI = 3.14;
double angle = 15;
/*
void lowerBodyPart() {

	// Bottom
	double boxside_1_coordinat_array[][3] = { {0, 0, 0}, {bottomPartLenght, 0, 0}, {bottomPartLenght, 0, bottomPartWidth}, {0, 0, bottomPartWidth} };
	glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_1_coordinat_array, 3);

	// side 1
	glPushMatrix();
	glRotatef(-angle, 1, 0, 0);
	double boxside_2_coordinat_array[][3] = { {0, 0, 0}, {bottomPartLenght, 0, 0}, {bottomPartLenght + height / tan(PI/3), height, 0}, { -height / tan(PI / 3), height, 0}};
	glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_2_coordinat_array, 3);
	glPopMatrix();

	// side 2
	glPushMatrix();
	glTranslatef(0, 0, bottomPartWidth);
	glRotatef(angle, 1, 0, 0);
	double boxside_3_coordinat_array[][3] = { {0, 0, 0}, {bottomPartLenght, 0, 0}, {bottomPartLenght + height / tan(PI / 3), height, 0}, { -height / tan(PI / 3), height, 0} };
	glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_3_coordinat_array, 3);
	glPopMatrix();

	// side 3
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glRotatef(angle, 1, 0, 0);
	double boxside_4_coordinat_array[][3] = { {0, 0, 0}, {bottomPartWidth, 0, 0}, {bottomPartWidth + height / tan(PI / 3), height, 0}, { -height / tan(PI / 3), height, 0} };
	glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_4_coordinat_array, 3);
	glPopMatrix();

	glPopMatrix();

	// side 4
	glPushMatrix();
	glTranslatef(bottomPartLenght, 0, 0);
	glRotatef(-90, 0, 1, 0);

	glPushMatrix();
	glRotatef(-angle, 1, 0, 0);
	double boxside_5_coordinat_array[][3] = { {0, 0, 0}, {bottomPartWidth, 0, 0}, {bottomPartWidth + height / tan(PI / 3), height, 0}, { -height / tan(PI / 3), height, 0} };
	glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_5_coordinat_array, 3);
	glPopMatrix();

	glPopMatrix();
}
*/
double uppwerPartWidth = bottomPartWidth + 2;
double upperPartLenght = bottomPartLenght + 2;
double height = 3.0;
void lowerBodyPart() {
	// Bottom
	double boxside_1_coordinat_array[][3] = { {0, 0, 0}, {bottomPartLenght, 0, 0}, {bottomPartLenght, 0, bottomPartWidth}, {0, 0, bottomPartWidth} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_1_coordinat_array, 3);

	// Upper part
	double boxside_2_coordinat_array[][3] = {
	{-(upperPartLenght - bottomPartLenght) / 2, height, -(uppwerPartWidth - bottomPartWidth) / 2},
	{(upperPartLenght + bottomPartLenght) / 2, height, -(uppwerPartWidth - bottomPartWidth) / 2},
	{(upperPartLenght + bottomPartLenght) / 2, height, (uppwerPartWidth + bottomPartWidth) / 2},
	{-(upperPartLenght - bottomPartLenght) / 2, height, (uppwerPartWidth + bottomPartWidth) / 2} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_2_coordinat_array, 3);
	// side 1
	double boxside_3_coordinat_array[][3] = {
	{-(upperPartLenght - bottomPartLenght) / 2, height, -(uppwerPartWidth - bottomPartWidth) / 2},
	{(upperPartLenght + bottomPartLenght) / 2, height, -(uppwerPartWidth - bottomPartWidth) / 2},
	{bottomPartLenght, 0, 0},
	{0, 0, 0} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_3_coordinat_array, 3);
	// side 2
	double boxside_4_coordinat_array[][3] = {
	{bottomPartLenght, 0, 0},
	{(upperPartLenght + bottomPartLenght) / 2, height, -(uppwerPartWidth - bottomPartWidth) / 2},
	{(upperPartLenght + bottomPartLenght) / 2, height, (uppwerPartWidth + bottomPartWidth) / 2},
	{bottomPartLenght, 0, bottomPartWidth} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_4_coordinat_array, 3);
	// side 3
	double boxside_5_coordinat_array[][3] = {
	{0, 0, bottomPartWidth},
	{-(upperPartLenght - bottomPartLenght) / 2, height, (uppwerPartWidth + bottomPartWidth) / 2},
	{(upperPartLenght + bottomPartLenght) / 2, height, (uppwerPartWidth + bottomPartWidth) / 2},
	{bottomPartLenght, 0, bottomPartWidth} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_5_coordinat_array, 3);
	// side 4
	double boxside_6_coordinat_array[][3] = {
	{0, 0, bottomPartWidth},
	{-(upperPartLenght - bottomPartLenght) / 2, height, (uppwerPartWidth + bottomPartWidth) / 2},
	{-(upperPartLenght - bottomPartLenght) / 2, height, -(uppwerPartWidth - bottomPartWidth) / 2},
	{0, 0, 0} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_6_coordinat_array, 3);
}

double upperBacklength = upperPartLenght * 3 / 2 + 2.0;
double upperBackWidth = uppwerPartWidth;
double upperBackHight = 1.5;

double upperFrontLength = 2.0;
double upperFrontWidth = upperBackWidth;

void drawMainGlass() {
	double boxside_1_coordinat_array[][3] = { {0, 0, 0}, {upperFrontLength, upperBackHight, 0}, {upperFrontLength, upperBackHight, upperFrontWidth}, {0, 0, upperFrontWidth} };
	glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_1_coordinat_array, 3);
}

void upperBodyPartFront() {
	double boxside_1_coordinat_array[][3] = { {0, 0, 0}, {upperFrontLength, upperBackHight, 0}, {upperFrontLength, upperBackHight, upperFrontWidth}, {0, 0, upperFrontWidth} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_1_coordinat_array, 3);

	double boxside_2_coordinat_array[][3] = { {0, 0, 0}, {upperFrontLength, upperBackHight, 0}, {upperFrontLength, 0, 0}, {0, 0, 0} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_2_coordinat_array, 3);

	double boxside_3_coordinat_array[][3] = { {0, 0, upperFrontWidth}, {upperFrontLength, upperBackHight, upperFrontWidth}, {upperFrontLength, 0, upperFrontWidth}, {0, 0, upperFrontWidth} };
	// glColor3f(1.0, 0.0, 0.0);
	drawPoygon(boxside_3_coordinat_array, 3);
}
void upperBodyPart() {
	glPushMatrix();
	glScalef(upperBacklength / 2, upperBackHight, upperBackWidth);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-upperBacklength / 4 - upperFrontWidth / 2.9, -upperBackHight / 2, -upperBackWidth / 2);
	glColor3f(0.4, 0.4, 0.5);
	upperBodyPartFront();
	glPopMatrix();
}

double lengthOfLightbar = upperFrontWidth - 0.4;
double widthOfLightBar = 1.0;
void drawFrontLightBar() {
	glPushMatrix();
	glScalef(widthOfLightBar, widthOfLightBar, lengthOfLightbar);
	glColor3f(0.2, 0.2, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -lengthOfLightbar / 2 + 0.4);
	glScalef(1, 0.4, 0.4);
	glColor3f(0, 0, 0);
	drawSphare(1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, lengthOfLightbar / 2 - 0.4);
	glScalef(1, 0.4, 0.4);
	glColor3f(0, 0, 0);
	drawSphare(1.0);
	glPopMatrix();
}

double radiusOfSideCylinder = 0.5;
double lengthOfSideCylinder = upperBackWidth * 1.5;
void drawSideCylinder() {
	drawCylinder(lengthOfSideCylinder, radiusOfSideCylinder, radiusOfSideCylinder);

	glPushMatrix();
	glTranslatef(0, 0, 0);
	glColor3f(0, 0, 0);
	drawSphare(radiusOfSideCylinder - 0.1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, lengthOfSideCylinder);
	glColor3f(0, 0, 0);
	drawSphare(radiusOfSideCylinder - 0.2);
	glPopMatrix();

}

void drawBody() {
	glPushMatrix();
	glTranslatef(bottomPartLenght / 2 + (upperPartLenght - bottomPartLenght) / 2, height + upperBackHight / 2, bottomPartWidth / 2);
	glColor3f(0.2, 0.2, 0.3);
	upperBodyPart();
	glPopMatrix();

	glColor3f(0.4, 0.4, 0.5);
	lowerBodyPart();

	glPushMatrix();
	glTranslatef(-0.6, height, lengthOfLightbar / 2 - 0.83);
	drawFrontLightBar();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, height + 0.2, upperBackWidth - 0.5);
	glRotatef(90, 0, 1, 0);
	glColor3f(0.2, 0.2, 0.3);
	drawSideCylinder();
	glPopMatrix();
}

double coverWidth = lenghtOfWeelAxis;
void drawUpWeelCover(double coverLenght) {
	glPushMatrix();
	glScalef(coverLenght, 0.2, coverWidth);
	glColor3f(0.2, 0.2, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();
}
void drawWeelCover(double coverLenght) {
	glPushMatrix();
	glTranslatef(-coverLenght / 2 - coverLenght / 8 * cos(45), -coverLenght / 8 * sin(45), 0);
	glRotatef(45, 0, 0, 1);
	drawUpWeelCover(coverLenght / 4);
	glPopMatrix();

	drawUpWeelCover(coverLenght);

	glPushMatrix();
	glTranslatef(coverLenght / 2 + coverLenght / 8 * cos(45), -coverLenght / 8 * sin(45), 0);
	glRotatef(-45, 0, 0, 1);
	drawUpWeelCover(coverLenght / 4);
	glPopMatrix();

}



void drawRoverTem() {

	glPushMatrix();
	glTranslatef(0, 0.0, (lenghtOfWeelAxis - bottomPartWidth) / 2);
	drawBody();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.0, 0, 0);
	drawWeelSystem();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(seperation1 - 0.6, radiusOfWeel + 1.0, lenghtOfWeelAxis / 2);
	drawWeelCover(seperation1 + 1.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(seperation1 + seperation2, radiusOfWeel + 1.0, lenghtOfWeelAxis / 2);
	drawWeelCover(seperation1 - 1.0);
	glPopMatrix();
}


void drawRover() {
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	drawRoverTem();
	glPopMatrix();
}
