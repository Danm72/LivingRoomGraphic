#include <stdio.h>
#import "ChairDrawer.h"

item_mover *item_move;

/*
void initItemMover(item_mover *item_move1) {
    item_move = item_move1;
}
*/

void defineDrawStyle_chair(GLUquadricObj *qobj) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawChairLegs() {
    int cn = CHAIR_NUM;
    if (item_move->itemToMove == cn) {
//        glPushMatrix();

        glTranslatef(item_move->x, item_move->y, item_move->z);
//        glPopMatrix();
    }

    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {0, 0.35, -5.5};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {0.75, .75, 0.75};
    materials(&black_plastic);
    defineDrawStyle_chair(quadObj);
    glPushMatrix();

    placeItem(location, rotate, scale);

    glLineWidth(20.0);

    glBegin(GL_LINES);

    glVertex3f(0.0f, 0.0f, 0.0f);    // A
    glVertex3f(0.0f, 0.0f, 1.0f);    // B

    glVertex3f(0.0f, 0.0f, 0.0f);    // A
    glVertex3f(1.0f, 0.0f, 1.0);    // B

    glVertex3f(0.0f, 0.0f, 0.0f);    // C
    glVertex3f(1.0f, 0.0f, -1.25f);    // C

    glVertex3f(0.0f, 0.0f, 0.0f);    // C
    glVertex3f(-1.0f, 0.0f, -1.25f);    // B

    glVertex3f(0.0f, 0.0f, 0.0f);    // D
    glVertex3f(-1.0f, 0.0f, 1.0);    // E

    glEnd();

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawChairFeet() {

    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat rotate[] = {90.0, 1.0, 0.0, 0.0};
    GLfloat scale[] = {0.5, 0.5, 1.0};
    materials(&black_plastic);
    defineDrawStyle_chair(quadObj);

    glPushMatrix();

    GLfloat ball1[] = {-0.7f, 0.2f, -6.4f};
    placeItem(ball1, rotate, scale);
    gluSphere(quadObj, .2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    GLfloat ball2[] = {.7f, 0.2f, -6.4f};
    placeItem(ball2, rotate, scale);
    gluSphere(quadObj, .2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    GLfloat ball3[] = {0.0f, 0.2f, -4.8f};
    placeItem(ball3, rotate, scale);
    gluSphere(quadObj, .2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    GLfloat ball5[] = {-0.7f, 0.2f, -4.8f};
    placeItem(ball5, rotate, scale);
    gluSphere(quadObj, .2, 100, 100);
    glPopMatrix();

    glPushMatrix();
    GLfloat ball6[] = {0.7f, 0.2f, -4.8f};
    placeItem(ball6, rotate, scale);
    gluSphere(quadObj, .2, 100, 100);
    glPopMatrix();

    gluDeleteQuadric(quadObj);

}


void drawChairStand() {
    glPushMatrix();

    GLfloat location2[] = {0, 0.35, -5.5};
    GLfloat rotate2[] = {0.0, 1.0, 0.0, 0.0};
    GLfloat scale2[] = {2.0, 2.0, 2.0};
    placeItem(location2, rotate2, scale2);
    glLineWidth(10.0);
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_chair(quadObj);

    materials(&black_plastic);

    glBegin(GL_LINES);
    glVertex3f(0, 0, 0);    // G
    glVertex3f(0.0f, 0.5f, 0.0f);    // G
    glEnd();

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawChairSeat() {
    glPushMatrix();
    materials(&white);
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_chair(quadObj);

    GLfloat location2[] = {0, 1.5, -5.5};
    GLfloat rotate2[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale2[] = {15.0, 2.0, 10.0};
    placeItem(location2, rotate2, scale2);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->leather);
    glutSolidCube_tex(.1, 1);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawChairBack() {

    glPushMatrix();
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_chair(quadObj);

    GLfloat location2[] = {0, 3, -6.0};
    GLfloat rotate2[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale2[] = {15.0, 30.0, 2.0};
    placeItem(location2, rotate2, scale2);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->leather);
    glutSolidCube_tex(.1, 1);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawChairArm_left() {
    glPushMatrix();
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_chair(quadObj);
    materials(&white);
    GLfloat location2[] = {.7, 2.5, -5.5};
    GLfloat rotate2[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale2[] = {2.0, 2.0, 12.5};
    placeItem(location2, rotate2, scale2);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->leather);
    glutSolidCube_tex(.1, 1);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawChairArm_right() {
    glPushMatrix();
    materials(&white);

    GLfloat location2[] = {-.7, 2.5, -5.5};
    GLfloat rotate2[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale2[] = {2.0, 2.0, 12.5};
    placeItem(location2, rotate2, scale2);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->leather);
    glutSolidCube_tex(.1, 1);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}


void setupChair() {


    glPushMatrix();
    glScalef(1.5, 1.0, 1.5);
    glTranslatef(0, 0, 1);
    glGetFloatv(GL_MODELVIEW, chair_legs_node.m);
    chair_legs_node.drawingFunction = drawChairLegs;
    chair_legs_node.sibling = NULL;
    chair_legs_node.child = &chair_stand_node;
    glPopMatrix();

    glGetFloatv(GL_MODELVIEW, chair_stand_node.m);
    chair_stand_node.drawingFunction = drawChairStand;
    chair_stand_node.sibling = NULL;
    chair_stand_node.child = &chair_feet_node;

    glGetFloatv(GL_MODELVIEW, chair_feet_node.m);
    chair_feet_node.drawingFunction = drawChairFeet;
    chair_feet_node.sibling = NULL;
    chair_feet_node.child = &chair_seat_node;

    glGetFloatv(GL_MODELVIEW, chair_seat_node.m);
    chair_seat_node.drawingFunction = drawChairSeat;
    chair_seat_node.sibling = NULL;
    chair_seat_node.child = &chair_back_node;

    glGetFloatv(GL_MODELVIEW, chair_back_node.m);
    chair_back_node.drawingFunction = drawChairBack;
    chair_back_node.sibling = NULL;
    chair_back_node.child = &chair_arm_left_node;

    glGetFloatv(GL_MODELVIEW, chair_arm_left_node.m);
    chair_arm_left_node.drawingFunction = drawChairArm_left;
    chair_arm_left_node.sibling = NULL;
    chair_arm_left_node.child = &chair_arm_right_node;

    glGetFloatv(GL_MODELVIEW, chair_arm_right_node.m);
    chair_arm_right_node.drawingFunction = drawChairArm_right;
    chair_arm_right_node.sibling = NULL;
    chair_arm_right_node.child = NULL;
}