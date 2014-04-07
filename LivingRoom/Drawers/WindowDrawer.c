#include <sys/_types/_null.h>
#import "BookshelfDrawer.h"
#include "MaterialTypes.h"
#include "Placement.h"
#include "SolidCube_Tex.h"
#include "Textures.h"
#include "TreeNode.h"



void defineDrawStyle_window(GLUquadricObj *qobj);

void defineDrawStyle_window(GLUquadricObj *qobj) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawWindowFace1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {-9, 4, -19.5};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {3.5, 4.0, 10.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->frame);


    placeItem( location, rotate, scale);
//    defineDrawStyle_shelf(quadObj);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);
    glTexCoord2f(1.1, 0);
    glVertex3f(1, 0, 0);
    glTexCoord2f(1.1, 1);
    glVertex3f(1, 1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(0, 1, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
//    materials(&pearl);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawWindowFace2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {6, 4, -19.5};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {3.5, 4.0, 10.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->frame);


    placeItem( location, rotate, scale);
//    defineDrawStyle_shelf(quadObj);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);
    glTexCoord2f(1.1, 0);
    glVertex3f(1, 0, 0);
    glTexCoord2f(1.1, 1);
    glVertex3f(1, 1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(0, 1, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
//    materials(&pearl);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void setupWindows() {

    glGetFloatv(GL_MODELVIEW, frame1_node.m);
    frame1_node.drawingFunction = drawWindowFace1;
    frame1_node.sibling = &frame2_node;
    frame1_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, frame2_node.m);
    frame2_node.drawingFunction = drawWindowFace2;
    frame2_node.sibling = NULL;
    frame2_node.child = NULL;

}