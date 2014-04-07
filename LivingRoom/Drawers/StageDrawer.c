#import "StageDrawer.h"
#include "MaterialTypes.h"
#include "SolidCube_Tex.h"
#include "Placement.h"
#include "TreeNode.h"



void defineDrawStyle_Stage(GLUquadricObj *qobj, GLuint startList1) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
}

void drawLvl1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList + STAGE_LVL1);
    materials(&white);

    glPushMatrix();

    GLfloat location[] = {0.0, 0.5, -17.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    glEnable(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, tex->oak);

    placeItem( location, rotate, scale);
    glutSolidCube_tex(0.1, 1);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    gluDeleteQuadric(quadObj);
}


void drawLvl2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    defineDrawStyle_Stage(quadObj, startList + STAGE_LVL2);
    materials(&white);

    glPushMatrix();

    GLfloat location[] = {0.0, 1.0, -17.5};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 10.0, 50.0};

    glEnable(GL_TEXTURE_2D);

    glBindTexture( GL_TEXTURE_2D, tex->oak);

    placeItem(location, rotate, scale);
    glutSolidCube_tex(0.1, 1);

    glDisable(GL_TEXTURE_2D);


    glPopMatrix();
    gluDeleteQuadric(quadObj);

}



void setupStage() {
    glPushMatrix();
    glTranslatef(0, 2, 0);
    glGetFloatv(GL_MODELVIEW, stage_level1_node.m);
    stage_level1_node.drawingFunction = drawLvl1;
    stage_level1_node.sibling = NULL;
    stage_level1_node.child = &stage_level2_node;

    glPopMatrix();

    glGetFloatv(GL_MODELVIEW, stage_level2_node.m);
    stage_level2_node.drawingFunction = drawLvl2;
    stage_level2_node.sibling = &bookcase_node;
    stage_level2_node.child = NULL;

}
