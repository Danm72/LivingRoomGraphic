#import "LampDrawer.h"
#include "MaterialTypes.h"


void defineDrawStyle_Lamp(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawCone() {
//    glLoadIdentity();
    GLUquadricObj *quadObj = gluNewQuadric();
//
    GLfloat trans [] = {-3, 4.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    GLfloat scale[] = {0,0,0};

    glPushMatrix();
    placeItem(startList + LAMP_CONE, trans, rotate,scale);

    materials(&emerald);

    defineDrawStyle_Lamp(quadObj, startList);

    gluCylinder(quadObj, 0.5, 0.25, 1, 7, 5);
    glPopMatrix();
}

void drawPole() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat trans [] = {-3, 2.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    GLfloat scale[] = {0,0,0};


    glPushMatrix();
    placeItem(startList + LAMP_POLE, trans, rotate,scale);
    defineDrawStyle_Lamp(quadObj, startList + 1);
    materials(&brass);


    gluCylinder(quadObj, 0.05, 0.05, 2, 15, 15);

    glPopMatrix();
}

void drawBase() {
    GLUquadricObj *quadObj = gluNewQuadric();


//    glDisable(GL_COLOR_MATERIAL);

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat trans [] = {-3, 2.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    GLfloat scale[] = {0,0,0};

    glPushMatrix();
    placeItem(startList + LAMP_BASE, trans, rotate,scale);

    defineDrawStyle_Lamp(quadObj, startList + 2);
    materials(&ruby);


    gluCylinder(quadObj, 0.5, 0.5, 0.5, 30, 10);
    gluDisk(quadObj, 0, .5, 30, 30);

    glPopMatrix();
}




