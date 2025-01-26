#include <GL/glut.h>

void setLightingAndShading() {
    glEnable(GL_LIGHTING);

    /***** Light 0 *****/
    GLfloat l0_amb[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat l0_diff[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat l0_spec[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat l0_pos[] = { -10.0, 1.0, -0.5, 1.0 }; // Position for LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, l0_amb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_diff);
    glLightfv(GL_LIGHT0, GL_SPECULAR, l0_spec);
    glLightfv(GL_LIGHT0, GL_POSITION, l0_pos);

    /***** Light 1 *****/
    GLfloat l1amb[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat l1diff[] = { 0.8, 0.8, 0.8, 1.0 };
    GLfloat l1spec[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat l1pos[] = { 10.0, 1.0, -0.5, 1.0 }; // Position for LIGHT1
    glLightfv(GL_LIGHT1, GL_AMBIENT, l1amb);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, l1diff);
    glLightfv(GL_LIGHT1, GL_SPECULAR, l1spec);
    glLightfv(GL_LIGHT1, GL_POSITION, l1pos);


    // Enable color material to make objects respond to lighting
    glEnable(GL_COLOR_MATERIAL);
    glShadeModel(GL_SMOOTH);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    // Set specular reflection for material
    GLfloat specRef[] = { 0.7, 0.7, 0.7, 1.0 };
    int shinness = 128;
    glMateriali(GL_FRONT, GL_SHININESS, shinness);
}