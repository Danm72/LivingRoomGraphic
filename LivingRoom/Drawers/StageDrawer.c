#import "StageDrawer.h"
#include "MaterialTypes.h"
#include "SolidCube_Tex.h"
#include "Placement.h"

void defineDrawStyle_Stage(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawLvl1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList + STAGE_LVL1);
//    materials(&copper);
//    glEnable(GL_TEXTURE_2D);
//
//    GLuint texture = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 720, 620);


//    freeTexture(&texture);
//    glDisable(GL_TEXTURE_2D);

    glPushMatrix();

    GLfloat location[] = {0.0, 0.5, -17.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    placeItem(startList + STAGE_LVL1, location, rotate, scale);
    glutSolidCube_tex(0.1, 1);
    glPopMatrix();
}


void drawLvl2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList + STAGE_LVL2);
//    materials(&copper);

    glPushMatrix();

    GLfloat location[] = {0.0, 1.0, -17.5};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    placeItem(startList + STAGE_LVL2, location, rotate, scale);
//    glEnable(GL_TEXTURE_2D);
//
////    GLuint texture = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 720, 620);
    glutSolidCube_tex(0.1, 1);
////    freeTexture(texture);
//
//    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
}

