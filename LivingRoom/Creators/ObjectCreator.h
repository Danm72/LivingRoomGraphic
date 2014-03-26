#include <GLUT/GLUT.h>
#import "Placement.h"
#import "MaterialTypes.h"

void defineDrawStyle(GLUquadricObj *qobj, GLuint);

void createLampCone(GLUquadricObj *qobj);

void createLampPole(GLUquadricObj *qobj);

void createLampBase(GLUquadricObj *qobj);

void createTableInnerBeam(GLUquadricObj *, GLuint);

void createLamp();

void createLightingEnv();
void createTableLeg(GLUquadricObj *obj, GLuint list);

void createTableLayer(GLUquadricObj *obj, GLuint list);

void createWall(GLUquadricObj *obj, GLuint list);

