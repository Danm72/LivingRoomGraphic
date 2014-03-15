#include <GLUT/GLUT.h>
#import "Placement.h"
#import "MaterialTypes.h"

void defineDrawStyle(GLUquadricObj *qobj, GLuint);

void createLampCone(GLUquadricObj *qobj);

void createLampPole(GLUquadricObj *qobj);

void createLampBase(GLUquadricObj *qobj);

void createFlatSurface(GLUquadricObj *, GLuint);

void createTableLeg(GLUquadricObj *, GLuint);

void createLamp();

void createLightingEnv();
