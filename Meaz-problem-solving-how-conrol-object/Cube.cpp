#include <GL/glut.h>

void drawSecondCube(double x, double y, double z) {
	glPushMatrix();
	glTranslatef(x, y, z);
	glutSolidCube(1.0);
	glPopMatrix();
}