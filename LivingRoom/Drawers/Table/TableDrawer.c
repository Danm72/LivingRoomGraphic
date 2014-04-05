#import "TableDrawer.h"
#import "TablePlacement.h"
#include "SolidCube_Tex.h"
#include "MaterialTypes.h"


void defineDrawStyle_Table(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList1, GL_COMPILE);
}

void drawTableLayer1() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createTableLayer(quadObj, startList + TABLE_LAYER_1);

    glTranslatef(0, 2, -10.0);
    GLfloat layer1[] = {0.0, 2.0, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    placeTableLayer(startList + TABLE_LAYER_1, layer1, rotate, scale);
}

void drawTableLayer2() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createTableLayer(quadObj, startList + TABLE_LAYER_2);

    GLfloat layer2[] = {0.0, 1.5, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    placeTableLayer(startList + TABLE_LAYER_2, layer2, rotate, scale);
}


void drawTableInner1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableInnerBeam(quadObj, startList + TABLE_INNER_1);
    GLfloat leg[] = {-3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};

    placeTableInnerBeam(startList + TABLE_INNER_1, leg, rotate);
}


void drawTableInner2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableInnerBeam(quadObj, startList + TABLE_INNER_2);
    GLfloat leg[] = {3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};

    placeTableInnerBeam(startList + TABLE_INNER_2, leg, rotate);
}


void drawTableLeg1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + TABLE_LEG_1);
    GLfloat leg[] = {-3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + TABLE_LEG_1, leg, rotate, scale);
}

void drawTableLeg2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + TABLE_LEG_2);
    GLfloat leg[] = {3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + TABLE_LEG_2, leg, rotate, scale);
}

void drawTableLeg3() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + TABLE_LEG_3);
    GLfloat leg[] = {-3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + TABLE_LEG_3, leg, rotate, scale);
}


void drawTableLeg4() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + TABLE_LEG_4);
    GLfloat leg[] = {3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + TABLE_LEG_4, leg, rotate, scale);
}


void createTableInnerBeam(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
    materials(&brass);
    gluCylinder(obj, 0.05, 0.05, .5, 4, 10);
    glEndList();
}


void createTableLeg(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
    materials(&black_plastic);
    glutSolidCube_tex(0.1, 1);
    glEndList();
}

void createTableLayer(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
//    materials(&copper);
    glEnable(GL_TEXTURE_2D);

    LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 100, 100);
    glutSolidCube_tex(0.1, 1);

    glDisable(GL_TEXTURE_2D);

    glEndList();
}