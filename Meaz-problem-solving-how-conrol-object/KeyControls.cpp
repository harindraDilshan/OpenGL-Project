#include <GL/glut.h>
#include <math.h>
#include "API.h"
#include <stdio.h>
#include "globals.h"



static float dRot;

void keyboardSpecial(int key, int x, int y) {
	if (key == GLUT_KEY_UP)
		camY += 1;

	if (key == GLUT_KEY_DOWN)
		camY -= 1;

	if (key == GLUT_KEY_RIGHT)
		camX += 1;

	if (key == GLUT_KEY_LEFT)
		camX -= 1;

	if (key == GLUT_KEY_PAGE_UP)
		camZ += 1;

	if (key == GLUT_KEY_PAGE_DOWN)
		camZ -= 1;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'o')
		if (dRot != 120)
			dRot += 2;
	if (key == 'c')
		if (dRot != 0)
			dRot -= 2;

	if (key == 'l')
		objRY += 1;

	if (key == 'r')
		objRY -= 1;

	if (key == 'Z')
		sceTZ += 4;

	if (key == 'z')
		sceTZ -= 4;

	if (key == 'w')
		sceTX += 1;

	if (key == 's')
		sceTX -= 1;

	if (key == 'y')
		sceRY += 4;

	if (key == 'Y')
		sceRY -= 4;

	if (key == '1')  // Enable light
		glEnable(GL_LIGHT0);


	if (key == '2')  // Disable light
		glDisable(GL_LIGHT0);

	if (key == '3')  // Enable light
		glEnable(GL_LIGHT1);


	if (key == '4')  // Disable light
		glDisable(GL_LIGHT1);

	if (key == '5')  // Enable light
		glEnable(GL_LIGHT2);


	if (key == '6')  // Disable light
		glDisable(GL_LIGHT2);

	glutPostRedisplay();
}
