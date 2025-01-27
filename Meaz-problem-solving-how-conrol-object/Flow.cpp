#include <GL/glut.h>

void drawFlow(double x, double y, double z) {
	glPushMatrix();
	glScalef(x, y, z);
	glColor3f(1, 0, 0);
	glutSolidCube(1.0);
	glPopMatrix();
}