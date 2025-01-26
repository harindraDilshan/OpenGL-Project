#include <GL/glut.h>


void drawCube() {
	glPushMatrix();
	glTranslatef(23, 1, 19);
	glutSolidCube(1.0);
	glPopMatrix();
}