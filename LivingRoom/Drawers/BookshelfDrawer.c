#import "BookshelfDrawer.h"
#include "Placement.h"
#include "SolidCube_Tex.h"
#include "TreeNode.h"



void createBookCase(GLUquadricObj *obj, int repeats);

void defineDrawStyle_shelf(GLUquadricObj *qobj) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawBookCase() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {0, 5.5, -19.5};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {100.0, 80.0, 10.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    placeItem( location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);

    createBookCase(quadObj, 2);

    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawBookFace() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {-5, 1.5, -18.9};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {10, 8.0, 10.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, tex->bookshelf);


    placeItem( location, rotate, scale);
//    defineDrawStyle_shelf(quadObj);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);
    glVertex3f(0, 0, 0);
    glTexCoord2f(1, 0);
    glVertex3f(1, 0, 0);
    glTexCoord2f(1, 1);
    glVertex3f(1, 1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(0, 1, 0);
    glEnd();

    glDisable(GL_TEXTURE_2D);
//    materials(&pearl);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void createBookCase(GLUquadricObj *obj, int repeats) {
    defineDrawStyle_shelf(obj);

    glutSolidCube_tex(0.1, repeats);


}


void setupBookCase() {

    glGetFloatv(GL_MODELVIEW, bookcase_node.m);
    bookcase_node.drawingFunction = drawBookCase;
    bookcase_node.sibling = NULL;
    bookcase_node.child = &bookface_node;

    glGetFloatv(GL_MODELVIEW, bookface_node.m);
    bookface_node.drawingFunction = drawBookFace;
    bookface_node.sibling = &frame1_node;
    bookface_node.child = NULL;
}
