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


//variables to move the camera
GLfloat camX = 0.0; GLfloat camY = 0.0; GLfloat camZ = 0.0;

//variables to move the scene
GLfloat sceRX = 0.0; GLfloat sceRY = 0.0; GLfloat sceRZ = 0.0;
GLfloat sceTX = 0.0; GLfloat sceTY = 0.0; GLfloat sceTZ = 0.0;

////variables to move the objects
GLfloat objRX = 0.0; GLfloat objRY = 0.0; GLfloat objRZ = 0.0;
GLfloat objTX = 0.0; GLfloat objTY = 0.0; GLfloat objTZ = 0.0;

static float dRot;

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

// Add a variable to toggle between cameras
bool useSecondCamera = false;

// Add these global variables at the top with your other globals
GLfloat cameraDistance = 2.0f;  // Distance from camera to object
GLfloat cameraHeight = 2.0f;    // Height of camera above object
GLfloat cameraAngle = 0.0f;     // Camera angle around object

// Replace your setupSecondCamera function with this new version
void setupThirdPersonCamera() {
	// Calculate camera position behind the object
	GLfloat cameraPosX = cubeX - cameraDistance * sin(cameraAngle * M_PI / 180.0f);
	GLfloat cameraPosY = cubeY + cameraHeight;
	GLfloat cameraPosZ = cubeZ - cameraDistance * cos(cameraAngle * M_PI / 180.0f);

	// Look at point is slightly above the object
	GLfloat lookAtX = cubeX;
	GLfloat lookAtY = cubeY + 0.5f;
	GLfloat lookAtZ = cubeZ;

	// Set up the camera
	gluLookAt(cameraPosX, cameraPosY, cameraPosZ,  // Camera position
		lookAtX, lookAtY, lookAtZ,            // Look at point
		0.0f, 1.0f, 0.0f);                    // Up vector
}

// Add a variable to toggle between cameras
bool useSecondCamera1 = false;

void setupSecondCamera() {
	// Define camera offset relative to the moving object
	GLfloat camOffsetX = cubeX + 0.0f;  // Position the camera behind the object
	GLfloat camOffsetY = cubeY + 50.0f;   // Slightly above the object
	GLfloat camOffsetZ = cubeZ + 0.0f;  // Position behind and slightly to the side

	// Look at the moving object's position
	GLfloat lookAtX = cubeX;
	GLfloat lookAtY = cubeY;
	GLfloat lookAtZ = cubeZ;

	// Set up the camera with an appropriate up vector
	gluLookAt(camOffsetX, camOffsetY, camOffsetZ,  // Camera position
		lookAtX, lookAtY, lookAtZ,            // Look-at point (object position)
		0.0, 1.0, 0.0);                       // Up vector (Y-axis up)
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

	if (useSecondCamera) {
		setupThirdPersonCamera();
	}
	else if (useSecondCamera1) {
		setupSecondCamera();
	}
	else {
		// Modified primary camera with mouse controls
		float camPosX = mouseZoom * sin(mouseRotY * M_PI / 180.0f) * cos(mouseRotX * M_PI / 180.0f);
		float camPosY = mouseZoom * sin(mouseRotX * M_PI / 180.0f);
		float camPosZ = mouseZoom * cos(mouseRotY * M_PI / 180.0f) * cos(mouseRotX * M_PI / 180.0f);

		gluLookAt(camPosX + camX, camPosY + camY, camPosZ + camZ,
			0.0, 0.0, 0.0,
			0.0, 1.0, 0.0);
	}

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
	glTranslatef(100.0, 50.0, 100.0);
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

	glMatrixMode(GL_MODELVIEW);

}

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
	//ifs can be replaced with switch...case
	if (key == 'v') {  // Toggle between primary and second camera
		useSecondCamera = !useSecondCamera;
	}
	if (key == 'b') {  // Toggle between primary and second camera
		useSecondCamera1 = !useSecondCamera1;
	}
	if (key == 'q') {
		cameraAngle -= 5.0f;  // Rotate camera left around object
		if (cameraAngle < 0.0f) cameraAngle += 360.0f;
	}
	if (key == 'e') {
		cameraAngle += 5.0f;  // Rotate camera right around object
		if (cameraAngle >= 360.0f) cameraAngle -= 360.0f;
	}
	if (key == 't') {
		cameraDistance -= 0.5f;  // Move camera closer
		if (cameraDistance < 2.0f) cameraDistance = 2.0f;
	}
	if (key == 'g') {
		cameraDistance += 0.5f;  // Move camera farther
		if (cameraDistance > 20.0f) cameraDistance = 20.0f;
	}
	if (key == 'f') {
		cameraHeight += 0.5f;  // Move camera up
	}
	if (key == 'h') {
		cameraHeight -= 0.5f;  // Move camera down
		if (cameraHeight < 0.5f) cameraHeight = 0.5f;
	}
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
		sceTZ += 0.2;

	if (key == 'z')
		sceTZ -= 0.2;

	if (key == 'w')
		sceTX += 1;

	if (key == 's')
		sceTX -= 1;

	if (key == 'y')
		sceRY += 1;

	if (key == 'Y')
		sceRY -= 1;

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