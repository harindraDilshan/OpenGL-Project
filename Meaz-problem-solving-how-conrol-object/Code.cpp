#include <GL/glut.h>
#include <math.h>
#include "API.h"
#include <stdio.h>
#include "globals.h"

#define M_PI 3.14159265358979323846





void timer(int v) {
	frameNumber++;
	glutPostRedisplay();
	glutTimerFunc(30, timer, 0);
}






//Grid and coordinate axes for better visualization
void drawGrid() {
	GLfloat step = 1.0f;
	GLint line;

	glBegin(GL_LINES);
	for (line = -20; line <= 20; line += step) {
		glVertex3f(line, -0.4, 20);
		glVertex3f(line, -0.4, -20);

		glVertex3f(20, -0.4, line);
		glVertex3f(-20, -0.4, line);
	}
	glEnd();
}



/////////////////////////////////////////////////////////////////////////////////////////////

// Add mouse control variables
int mouseX = 0, mouseY = 0;
bool mouseLeftDown = false;
bool mouseRightDown = false;
float mouseRotX = 0.0f;
float mouseRotY = 0.0f;
float mouseRotZ = 0.0f;
float mouseSensitivity = 0.2f;
float mouseZoom = 5.0f;

// [Previous code remains the same until the new mouse functions]

void mouseFunc(int button, int state, int x, int y) {
	mouseX = x;
	mouseY = y;

	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			mouseLeftDown = true;
		}
		else if (state == GLUT_UP) {
			mouseLeftDown = false;
		}
	}
	else if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN) {
			mouseRightDown = true;
		}
		else if (state == GLUT_UP) {
			mouseRightDown = false;
		}
	}
}

void mouseMotionFunc(int x, int y) {
	int deltaX = x - mouseX;
	int deltaY = y - mouseY;
	mouseX = x;
	mouseY = y;

	if (mouseLeftDown) {
		// Rotate camera
		mouseRotY += deltaX * mouseSensitivity;
		mouseRotX += deltaY * mouseSensitivity;

		// Limit vertical rotation to prevent camera flipping
		if (mouseRotX > 89.0f) mouseRotX = 89.0f;
		if (mouseRotX < -89.0f) mouseRotX = -89.0f;
	}
	else if (mouseRightDown) {
		// Zoom in/out
		mouseZoom += deltaY * 0.1f;
		if (mouseZoom < 1.0f) mouseZoom = 1.0f;
		if (mouseZoom > 20.0f) mouseZoom = 20.0f;
	}
	glutPostRedisplay();
}



/////////////////////////////////////////////////////////////////////////////////////









void drawAxes() {

	glBegin(GL_LINES);

	glLineWidth(1.5);

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-200, 0, 0);
	glVertex3f(200, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, -200, 0);
	glVertex3f(0, 200, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, -200);
	glVertex3f(0, 0, 200);

	glEnd();
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);

	numOfLines = getNumberOfLinse();
	grid = generateGridArray();

	loadTextures();
	loadSunTextures();
	loadSkyTextures();
	loadRoboTextures();
	loadFlagTextures();
	loadEarthtextures();
}

void drawMovingObject() {
	glPushMatrix();
	glTranslatef(cubeX, cubeY, cubeZ); // Use cube position from API
	glScalef(0.5, 2.0, 0.5);
	glColor3f(1, 1, 0);
	drawRobo();
	glPopMatrix();
}

void seen() {
	drawMovingObject();
	drawMaze();
}


void display(void) {
	controlCube();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	// Modified primary camera with mouse controls
	float camPosX = mouseZoom * sin(mouseRotY * M_PI / 180.0f) * cos(mouseRotX * M_PI / 180.0f);
	float camPosY = mouseZoom * sin(mouseRotX * M_PI / 180.0f);
	float camPosZ = mouseZoom * cos(mouseRotY * M_PI / 180.0f) * cos(mouseRotX * M_PI / 180.0f);

	gluLookAt(camPosX + camX, camPosY + camY, camPosZ + camZ,
		0.0, 0.0, 0.0,
		0.0, 1.0, 0.0);

	// move the scene (all the rendered environment) using keyboard keys
	glTranslatef(sceTX, sceTY, sceTZ);
	glRotatef(sceRY, 0.0, 1.0, 0.0);

	// Draw a grid on the xz plane
	//glColor3f(1, 1, 1);
	// drawGrid();
	//draw the three axes
	//drawAxes();

	setLightingAndShading();

	glPushMatrix();
	glTranslatef(-42, 0, -51);
	glScalef(1.5, 0.5, 1.5);
	seen();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glColor3f(1, 1, 1);
	drawFlow(150, 1.0, 150);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(90.0, 50.0, 90.0);
	drawSun();
	glPopMatrix();

	glPushMatrix();
	// glTranslatef(100.0, 25.0, 100.0);
	drawSky();
	glPopMatrix();

	//glPushMatrix();
	//// glTranslatef(100.0, 25.0, 100.0);
	//drawRobo();
	//glPopMatrix();

	/*glPushMatrix();
	glRotatef(frameNumber * 0.1, 0, 1, 0);*/
	drawRoverSet();
	//glPopMatrix();

	// drawFlag();

	glPushMatrix();
	glTranslatef(-90.0, 50.0, -90.0);
	drawEarth();
	glPopMatrix();


	glPopMatrix();
	glutSwapBuffers();
}

void reshape(GLsizei w, GLsizei h) {
	glViewport(0, 0, w, h);
	GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();


	gluPerspective(75.0, aspect_ratio, 0.1, 200.0);
	// gluPerspective(120.0, aspect_ratio, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW);

}


int main(void) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Moon Maze Solver");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(keyboardSpecial);

	// Add mouse callback functions
	glutMouseFunc(mouseFunc);
	glutMotionFunc(mouseMotionFunc);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(200, timer, 0);
	glutTimerFunc(200, timer2, 0);
	init();
	glutMainLoop();
	return 0;
}