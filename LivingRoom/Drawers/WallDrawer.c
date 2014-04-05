#import "WallDrawer.h"
#import "WallPlacement.h"
#include "MaterialTypes.h"


void defineDrawStyle_Walls(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList1, GL_COMPILE);
}

void drawFloor(){
    GLUquadricObj *quadObj = gluNewQuadric();

    createWall(quadObj, startList + FLOOR);

    GLfloat location[] = {0.0, 0.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 1.0, 400.0};

    placeWall(startList + FLOOR, location, rotate, scale);

}


void drawBackWall(){
    GLUquadricObj *quadObj = gluNewQuadric();

    createWall(quadObj, startList + BACK_WALL);
//    createFlatSurface(quadObj, startList + 11);
//    createFlatSurface(quadObj, startList + 12);
    GLfloat location1[] = {0.0, 10.0, -20.0};
    GLfloat rotate1[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 200.0, 1.0};

    placeWall(startList + BACK_WALL, location1, rotate1, scale);
}



void drawLeftWall() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createWall(quadObj, startList + LEFT_WALL);





    GLfloat location[] = {-10.0, 10.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {1.0, 200.0, 400.0};

    placeWall(startList + LEFT_WALL, location, rotate, scale);

}


void drawRightWall() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createWall(quadObj, startList + RIGHT_WALL);

    GLfloat location[] = {10.0, 10.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {1.0, 200.0, 400.0};

    placeWall(startList + RIGHT_WALL, location, rotate, scale);

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

    glutSolidCube(0.1);
    glEndList();

}
