
#include <GLUT/GLUT.h>

GLuint startList;

void placeLampCone(GLuint list, GLfloat trans [], GLfloat rotate []);

void placeLampPole(GLuint list, GLfloat trans [], GLfloat rotate []);

void placeLampBase(GLuint list, GLfloat trans [], GLfloat rotate []);

void placeTeapot(GLfloat trans [], GLfloat rotate []);

void placeTable();

void placeTableLayer(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat pDouble []);

void placeTableInnerBeam(GLuint list, GLfloat trans [], GLfloat rotate []);

void placeWall(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat pDouble []);

void placeTableLeg(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat scale []);

void placeLamp();