#include <sys/_types/_null.h>
#import "TableDrawer.h"

void drawTableLayer1();

void drawTableLayer2();

void drawTableInner1();

void drawTableInner2();

void drawTableLeg1();

void drawTableLeg2();

void drawTableLeg3();

void placeTeapot();

item_mover *item_move;

void defineDrawStyle_Table(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
}

void drawTableLayer1() {

    int tb = TABLE_NUM;
    if (item_move->itemToMove == tb) {
//        glPushMatrix();

        glTranslatef(item_move->x, item_move->y, item_move->z);
//        glPopMatrix();
    }

    GLUquadricObj *quadObj = gluNewQuadric();
//    materials(&white);

    GLfloat layer[] = {0.0, 2.0, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    glPushMatrix();

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex->wood_desk);

    placeItem(layer, rotate, scale);

    createTableLayer(quadObj, 0);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawTableLayer2() {
    GLUquadricObj *quadObj = gluNewQuadric();
//    materials(&white);

    GLfloat layer[] = {0.0, 1.5, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex->wood_desk);

    placeItem(layer, rotate, scale);

    createTableLayer(quadObj, 0);

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawTableInner1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {-3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};
    GLfloat scale[] = {0, 0, 0};
    glPushMatrix();

    placeItem(leg, rotate, scale);
    createTableInnerBeam(quadObj, 0);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawTableInner2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};
    GLfloat scale[] = {0, 0, 0};
    glPushMatrix();

    placeItem(leg, rotate, scale);
    createTableInnerBeam(quadObj, 0);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawTableLeg1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {-3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex->wood_desk);

    placeItem(leg, rotate, scale);
    createTableLeg(quadObj, 0);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawTableLeg2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    glPushMatrix();

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex->wood_desk);

    placeItem(leg, rotate, scale);
    createTableLeg(quadObj, 0);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawTableLeg3() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {-3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex->wood_desk);

    placeItem(leg, rotate, scale);
    createTableLeg(quadObj, 0);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawTableLeg4() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat leg[] = {3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, tex->wood_desk);

    placeItem(leg, rotate, scale);
    createTableLeg(quadObj, 0);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void createTableInnerBeam(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
    materials(&brass);
    gluCylinder(obj, 0.05, 0.05, .5, 4, 10);

}


void createTableLeg(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
//    materials(&white);
    glutSolidCube_tex(0.1, 1);

}

void createTableLayer(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle_Table(obj, list);
    glutSolidCube_tex(0.1, 1);

}


void placeTeapot() {
    glPushMatrix();

    materials(&gold);
    glTranslatef(0.0, 2.5, -3.5);
    glutSolidTeapot(0.5);

    glPopMatrix();
}


void setupTableNodes() {
    glPushMatrix();
    glTranslatef(0, 0, -4.0);

    glGetFloatv(GL_MODELVIEW, table_layer1_node.m);
    table_layer1_node.drawingFunction = drawTableLayer1;
    table_layer1_node.sibling = NULL;
    table_layer1_node.child = &table_layer2_node;

    glPopMatrix();

    glGetFloatv(GL_MODELVIEW, table_layer2_node.m);
    table_layer2_node.drawingFunction = drawTableLayer2;
    table_layer2_node.sibling = NULL;
    table_layer2_node.child = &table_leg1_node;

    glGetFloatv(GL_MODELVIEW, teapot_node.m);
    teapot_node.drawingFunction = placeTeapot;
    teapot_node.sibling = NULL ;
    teapot_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, table_leg1_node.m);
    table_leg1_node.drawingFunction = drawTableLeg1;
    table_leg1_node.sibling = NULL;
    table_leg1_node.child = &table_leg2_node;

    glGetFloatv(GL_MODELVIEW, table_leg2_node.m);
    table_leg2_node.drawingFunction = drawTableLeg2;
    table_leg2_node.sibling = NULL;
    table_leg2_node.child = &table_leg3_node;

    glGetFloatv(GL_MODELVIEW, table_leg3_node.m);
    table_leg3_node.drawingFunction = drawTableLeg3;
    table_leg3_node.sibling = NULL;
    table_leg3_node.child = &table_leg4_node;

    glGetFloatv(GL_MODELVIEW, table_leg4_node.m);
    table_leg4_node.drawingFunction = drawTableLeg4;
    table_leg4_node.sibling = &teapot_node;
    table_leg4_node.child = &table_inner1_node;

    glGetFloatv(GL_MODELVIEW, table_inner1_node.m);
    table_inner1_node.drawingFunction = drawTableInner1;
    table_inner1_node.sibling = NULL;
    table_inner1_node.child = &table_inner2_node;

    glGetFloatv(GL_MODELVIEW, table_inner2_node.m);
    table_inner2_node.drawingFunction = drawTableInner2;
    table_inner2_node.sibling = &chair_legs_node;
    table_inner2_node.child = &lamp_cone_node;
}