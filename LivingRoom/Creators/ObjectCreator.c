#import "ObjectCreator.h"

void defineDrawStyle(GLUquadricObj *qobj, GLuint startList) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList, GL_COMPILE);
}

void createFlatSurface(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    glutSolidCube(0.1);
    glEndList();
}

void createTableLeg(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    gluCylinder(obj, 0.05, 0.05, 1, 30, 10);
    glEndList();
}

void createLampBase(GLUquadricObj *qobj) {
    defineDrawStyle(qobj, startList + 2);
    gluCylinder(qobj, 0.5, 0.5, 0.5, 30, 10);
   // gluDisk(qobj, 0, .5, 30, 30);
//    glutSolidCube(2);
//    glScalef(1, 0, 0);
    glEndList();
}

void createLampPole(GLUquadricObj *qobj) {
    defineDrawStyle(qobj, startList + 1);
    gluCylinder(qobj, 0.05, 0.05, 2, 15, 15);
    glEndList();
}

void createLampCone(GLUquadricObj *qobj) {
    //glColor3f(1, 0, 0);
    defineDrawStyle(qobj, startList);
    materials(&brass);
   // glColor3ub(1, 2, 3);
    gluCylinder(qobj, 0.5, 0.25, 1, 30, 10);
    glEndList();
}