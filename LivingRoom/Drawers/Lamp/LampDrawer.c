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
    placeItem(trans, rotate,scale);

    materials(&emerald);
//    float no_mat [] = {1.0f, 1.0f, 1.0f, 1.0f};
//    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, no_mat);

    defineDrawStyle_Lamp(quadObj, startList);

    gluCylinder(quadObj, 0.5, 0.25, 1, 7, 5);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawPole() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat trans [] = {-3, 2.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    GLfloat scale[] = {0,0,0};


    glPushMatrix();
    placeItem(trans, rotate,scale);
    defineDrawStyle_Lamp(quadObj, startList + 1);
    materials(&brass);


    gluCylinder(quadObj, 0.05, 0.05, 2, 15, 15);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawBase() {
    GLUquadricObj *quadObj = gluNewQuadric();


//    glDisable(GL_COLOR_MATERIAL);

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat trans [] = {-3, 2.0, -4.5};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    GLfloat scale[] = {0,0,0};

    glPushMatrix();
    placeItem(trans, rotate,scale);

    defineDrawStyle_Lamp(quadObj, startList + 2);
    materials(&ruby);


    gluCylinder(quadObj, 0.5, 0.5, 0.5, 30, 10);

     glTranslatef(0, 0, .5);
    gluDisk(quadObj, 0, .5, 30, 30);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}



void setupLampNodes() {


    glPushMatrix();
    glTranslatef(0, 0, 1.5);

    glGetFloatv(GL_MODELVIEW, lamp_cone_node.m);
    lamp_cone_node.drawingFunction = drawCone;
    lamp_cone_node.sibling = NULL;
    lamp_cone_node.child = &lamp_pole_node;
    glPopMatrix();

    glGetFloatv(GL_MODELVIEW, lamp_pole_node.m);
    lamp_pole_node.drawingFunction = drawPole;
    lamp_pole_node.sibling = NULL;
    lamp_pole_node.child = &lamp_base_node;

    glGetFloatv(GL_MODELVIEW, lamp_base_node.m);
    lamp_base_node.drawingFunction = drawBase;
    lamp_base_node.sibling = &lamp_cone2_node;
    lamp_base_node.child = NULL;

    //stage_level1_node
    //Second lamp

    glPushMatrix();
    glTranslatef(6, 0, 0);

    glGetFloatv(GL_MODELVIEW, lamp_cone2_node.m);
    lamp_cone2_node.drawingFunction = drawCone;
    lamp_cone2_node.sibling = NULL;
    lamp_cone2_node.child = &lamp_pole2_node;
    glPopMatrix();
    glGetFloatv(GL_MODELVIEW, lamp_pole2_node.m);
    lamp_pole2_node.drawingFunction = drawPole;
    lamp_pole2_node.sibling = NULL;
    lamp_pole2_node.child = &lamp_base2_node;

    glGetFloatv(GL_MODELVIEW, lamp_base2_node.m);
    lamp_base2_node.drawingFunction = drawBase;
    lamp_base2_node.sibling = NULL;
    lamp_base2_node.child = NULL;

}



