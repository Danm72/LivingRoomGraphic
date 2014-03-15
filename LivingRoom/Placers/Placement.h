
#include <GLUT/GLUT.h>

GLuint startList;

void placeLampCone();

void placeLampPole();

void placeLampBase();

void placeTeapot();

void placeTable();

void placeTableLayer(GLuint list, GLfloat trans []);

void placeTableLeg(GLint, GLfloat []);

void placeWall(GLuint list, GLfloat trans [], GLfloat rotate []);

void placeLamp();