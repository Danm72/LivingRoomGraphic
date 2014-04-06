#import "TableDrawer.h"
#include "SolidCube_Tex.h"
#include "MaterialTypes.h"


void defineDrawStyle_Table(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
}

void drawTableLayer1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat layer1[] = {0.0, 2.0, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};
    glTranslatef(0, 1, -15.0);

    glPushMatrix();

    placeItem(startList + TABLE_LAYER_1, layer1, rotate, scale);
    createTableLayer(quadObj, startList + TABLE_LAYER_1);
    glPopMatrix();

}

void drawTableLayer2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat layer2[] = {0.0, 1.5, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    glPushMatrix();
    placeItem(startList + TABLE_LAYER_2, layer2, rotate, scale);
    createTableLayer(quadObj, startList + TABLE_LAYER_2);
    glPopMatrix();
}


void drawTableInner1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {-3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};
    GLfloat scale[] = {0, 0, 0};
    glPushMatrix();

    placeItem(startList + TABLE_INNER_1, leg, rotate, scale);
    createTableInnerBeam(quadObj, startList + TABLE_INNER_1);
    glPopMatrix();

}


void drawTableInner2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};
    GLfloat scale[] = {0, 0, 0};
    glPushMatrix();

    placeItem(startList + TABLE_INNER_2, leg, rotate, scale);
    createTableInnerBeam(quadObj, startList + TABLE_INNER_2);
    glPopMatrix();

}


void drawTableLeg1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {-3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};
    glPushMatrix();
    placeItem(startList + TABLE_LEG_1, leg, rotate, scale);
    createTableLeg(quadObj, startList + TABLE_LEG_1);

    glPopMatrix();
}

void drawTableLeg2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    glPushMatrix();

    placeItem(startList + TABLE_LEG_2, leg, rotate, scale);
    createTableLeg(quadObj, startList + TABLE_LEG_2);
    glPopMatrix();

}

void drawTableLeg3() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {-3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    glPushMatrix();
    placeItem(startList + TABLE_LEG_3, leg, rotate, scale);
    createTableLeg(quadObj, startList + TABLE_LEG_3);
    glPopMatrix();

}


void drawTableLeg4() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};
    glPushMatrix();
    placeItem(startList + TABLE_LEG_4, leg, rotate, scale);
    createTableLeg(quadObj, startList + TABLE_LEG_4);
    glPopMatrix();

}


void createTableInnerBeam(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
    materials(&brass);
    gluCylinder(obj, 0.05, 0.05, .5, 4, 10);
}


void createTableLeg(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
    materials(&black_plastic);
    glutSolidCube_tex(0.1, 1);
}

void createTableLayer(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
//    materials(&copper);
//    glEnable(GL_TEXTURE_2D);
////    glPushMatrix();
//    GLuint texture = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 100, 100);
    glutSolidCube_tex(0.1, 1);
//
//    freeTexture(texture);
//
//    glDisable(GL_TEXTURE_2D);
//    glPopMatrix();
}