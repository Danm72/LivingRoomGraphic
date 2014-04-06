#import "WallDrawer.h"
#include "MaterialTypes.h"
#include "Placement.h"
#include "SolidCube_Tex.h"


void defineDrawStyle_Walls(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawFloor() {
    GLUquadricObj *quadObj = gluNewQuadric();


    GLfloat location[] = {0.0, 0.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 1.0, 400.0};

    glPushMatrix();
    placeItem(startList + FLOOR, location, rotate, scale);
    createWall(quadObj, startList + FLOOR);
    glPopMatrix();
}


void drawBackWall() {
    GLUquadricObj *quadObj = gluNewQuadric();

//    createFlatSurface(quadObj, startList + 11);
//    createFlatSurface(quadObj, startList + 12);
    GLfloat location1[] = {0.0, 10.0, -20.0};
    GLfloat rotate1[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 200.0, 1.0};
    glPushMatrix();

    placeItem(startList + BACK_WALL, location1, rotate1, scale);
    createWall(quadObj, startList + BACK_WALL);

    glPopMatrix();

}


void drawLeftWall() {
    GLUquadricObj *quadObj = gluNewQuadric();


    GLfloat location[] = {-10.0, 10.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {1.0, 200.0, 400.0};
    glPushMatrix();

    placeItem(startList + LEFT_WALL, location, rotate, scale);
    createWall(quadObj, startList + LEFT_WALL);
    glPopMatrix();
}


void drawRightWall() {
    GLUquadricObj *quadObj = gluNewQuadric();


    GLfloat location[] = {10.0, 10.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {1.0, 200.0, 400.0};

    glPushMatrix();
    placeItem(startList + RIGHT_WALL, location, rotate, scale);
    createWall(quadObj, startList + RIGHT_WALL);
    glPopMatrix();
}


void createWall(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Walls(obj, list);
    materials(&obsidian);

    /*   gluBuild2DMipmaps(GL_TEXTURE_2D, 3,
               256,
               256,
               GL_RGB,
               GL_UNSIGNED_BYTE,
               100);*/
    glutSolidCube_tex(0.1, 1);

    GLuint texture = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/cream_32.bmp", 32, 32);


    glEnable(GL_TEXTURE_2D);
    glBindTexture( GL_TEXTURE_2D, texture );


    freeTexture(texture);

    glDisable(GL_TEXTURE_2D);


}
