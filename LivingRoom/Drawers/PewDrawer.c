#import "StageDrawer.h"
#include "SolidCube_Tex.h"
#include "Placement.h"
#import "PewDrawer.h"

void defineDrawStyle_Pew(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
}

void drawPew() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList + PEW_1);
//    materials(&copper);
//    glEnable(GL_TEXTURE_2D);
//
//    GLuint texture = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 720, 620);
//    glutSolidCube_tex(0.1, 1);
//
//    freeTexture(&texture);
//    glDisable(GL_TEXTURE_2D);


    GLfloat location[] = {0.0, 0.5, -17.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    placeItem(startList + PEW_1, location, rotate, scale);

}



