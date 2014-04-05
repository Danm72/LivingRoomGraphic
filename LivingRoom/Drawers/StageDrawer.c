#import "StagePlacement.h"
#import "StageDrawer.h"
#include "MaterialTypes.h"
#include "SolidCube_Tex.h"

void defineDrawStyle_Stage(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList1, GL_COMPILE);
}

void drawLvl1(){
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList+16);
//    materials(&copper);
    glEnable(GL_TEXTURE_2D);

    LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 100, 100);
    glutSolidCube_tex(0.1, 1);

    glDisable(GL_TEXTURE_2D);

    glEndList();

    GLfloat location[] = {0.0, 0.5, -20.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    placeStage(startList + STAGE_LVL1, location, rotate, scale);

}


void drawLvl2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList+ STAGE_LVL2);
//    materials(&copper);
    glEnable(GL_TEXTURE_2D);

    LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 100, 100);
    glutSolidCube_tex(0.1, 1);

    glDisable(GL_TEXTURE_2D);

    glEndList();

    GLfloat location[] = {0.0, 1.0, -15};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    placeStage(startList + STAGE_LVL2, location, rotate, scale);

}

