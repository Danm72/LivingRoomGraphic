#import "LampDrawer.h"
#import "LampPlacement.h"
#include "MaterialTypes.h"


void defineDrawStyle_Lamp(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList1, GL_COMPILE);
}

void drawCone() {
//    glLoadIdentity();
    GLUquadricObj *quadObj = gluNewQuadric();
//    glTranslatef(-3, 1, -5);

    materials(&emerald);

    defineDrawStyle_Lamp(quadObj, startList);
//    gluQuadricDrawStyle(qobj, GLU_FILL);
//    gluQuadricNormals(qobj, GLU_SMOOTH);
//    glNewList(startList, GL_COMPILE);

    gluCylinder(quadObj, 0.5, 0.25, 1, 7, 5);
    glEndList();
    GLfloat trans [] = {-3, 4.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    placeLampCone(startList + LAMP_CONE, trans, rotate);
}

void drawPole() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Lamp(quadObj, startList + 1);
    materials(&brass);

    gluCylinder(quadObj, 0.05, 0.05, 2, 15, 15);
    glEndList();    GLfloat trans [] = {-3, 2.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    placeLampPole(startList + LAMP_POLE, trans, rotate);
}

void drawBase() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Lamp(quadObj, startList + 2);
    materials(&ruby);

    gluCylinder(quadObj, 0.5, 0.5, 0.5, 30, 10);
    gluDisk(quadObj, 0, .5, 30, 30);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEndList();    GLfloat trans [] = {-3, 2.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    placeLampBase(startList + LAMP_BASE, trans, rotate);
}




