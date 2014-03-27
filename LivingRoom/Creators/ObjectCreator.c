#include <stdlib.h>
#include <stdio.h>
#import "ObjectCreator.h"
#import "SolidCube_Tex.h"
void defineDrawStyle(GLUquadricObj *qobj, GLuint startList) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList, GL_COMPILE);
}

void createTableLayer(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
//    materials(&copper);
    glEnable(GL_TEXTURE_2D);

    LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 100, 100);
    glutSolidCube_tex(0.1);

    glDisable(GL_TEXTURE_2D);

    glEndList();
}

void createWall(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
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

void createTableInnerBeam(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    materials(&brass);
    gluCylinder(obj, 0.05, 0.05, .5, 4, 10);
    glEndList();
}


void createTableLeg(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    materials(&black_plastic);
    glutSolidCube_tex(0.1);
    glEndList();
}

void createLampBase(GLUquadricObj *qobj) {
    defineDrawStyle(qobj, startList + 2);
    materials(&ruby);

    gluCylinder(qobj, 0.5, 0.5, 0.5, 30, 10);
    gluDisk(qobj, 0, .5, 30, 30);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEndList();
}


void createLampPole(GLUquadricObj *qobj) {
    defineDrawStyle(qobj, startList + 1);
    materials(&brass);

    gluCylinder(qobj, 0.05, 0.05, 2, 15, 15);
    glEndList();
}

void createLampCone(GLUquadricObj *qobj) {
    materials(&emerald);

    //defineDrawStyle(qobj, startList);
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_SMOOTH);
    glNewList(startList, GL_COMPILE);

    gluCylinder(qobj, 0.5, 0.25, 1, 7, 5);
    glEndList();

}

