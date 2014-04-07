#include <sys/_types/_null.h>
#import "WallDrawer.h"
#include "MaterialTypes.h"
#include "Placement.h"
#include "SolidCube_Tex.h"
#include "Textures.h"
#include "TreeNode.h"



void defineDrawStyle_Walls(GLUquadricObj *qobj) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
//    glNewList(startList1, GL_COMPILE);
}

void drawFloor() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {0.0, 0.0, -10.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 1.0, 200.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    placeItem( location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->oak);

    createWall(quadObj, 10);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);
}

void drawRoof1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {-5.0, 12.0, -10.0};
    GLfloat rotate[] = {20.0, 0.0, 0.0, 1.0};
    GLfloat scale[] = {120.0, 1.0, 200.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    placeItem(  location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);
    materials(&white);

    createWall(quadObj, 10);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);
}


void drawRoof2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {5.0, 12.0, -10.0};
    GLfloat rotate[] = {-20.0, 0.0, 0.0, 1.0};
    GLfloat scale[] = {120.0, 1.0, 200.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    placeItem(  location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);
    materials(&white);

    createWall(quadObj, 10);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);
}


void drawRoofBack() {
    GLUquadricObj *quadObj = gluNewQuadric();

    GLfloat location[] = {0.0, 12.0, -20.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {17.5, 2.75, 0.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    placeItem(  location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);
    materials(&white);
    glBegin(GL_POLYGON);
    glTexCoord2f(0, 0);
    glVertex3f(-0.6, -0.75, 0.5);
    glTexCoord2f(3, 0);
    glVertex3f(0.6, -0.75, 0);
    glTexCoord2f(3, 3);
    glVertex3f(0, 0.75, 0);

    glEnd();


    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);
}


void drawBackWall() {
    GLUquadricObj *quadObj = gluNewQuadric();
    materials(&obsidian);

//    createFlatSurface(quadObj, startList + 11);
//    createFlatSurface(quadObj, startList + 12);
    GLfloat location1[] = {0.0, 5.0, -20.0};
    GLfloat rotate1[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {200.0, 100.0, 1.0};
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);

    placeItem(  location1, rotate1, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);

    createWall(quadObj, 3);
    glDisable(GL_TEXTURE_2D);

    glPopMatrix();
    gluDeleteQuadric(quadObj);

}

void drawLeftWall() {
    GLUquadricObj *quadObj = gluNewQuadric();
    materials(&black_plastic);


    GLfloat location[] = {-10.0, 5.0, -10.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {1.0, 100.0, 200.0};
    glPushMatrix();

    glEnable(GL_TEXTURE_2D);

    placeItem(  location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);

    createWall(quadObj, 3);
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void drawRightWall() {
    GLUquadricObj *quadObj = gluNewQuadric();
    materials(&black_plastic);

    GLfloat location[] = {10.0, 5.0, -10.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {1.0, 100.0, 200.0};

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);

    placeItem(  location, rotate, scale);
    glBindTexture(GL_TEXTURE_2D, tex->wood);
    defineDrawStyle_Walls(quadObj);
    materials(&pearl);
    glutSolidCube_tex(0.1, 3);

    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    gluDeleteQuadric(quadObj);

}


void createWall(GLUquadricObj *obj, int repeats) {
    defineDrawStyle_Walls(obj);
    materials(&pearl);

    glutSolidCube_tex(0.1, repeats);

}



void setupWallNodes() {
    glPushMatrix();
    glTranslatef(0, 2, 0.0);

    glGetFloatv(GL_MODELVIEW, wall_floor_node.m);
    wall_floor_node.drawingFunction = drawFloor;
    wall_floor_node.sibling = &stage_level1_node;
    wall_floor_node.child = &wall_back_node;
    glPopMatrix();

    glGetFloatv(GL_MODELVIEW, wall_back_node.m);
    wall_back_node.drawingFunction = drawBackWall;
    wall_back_node.sibling = NULL;
    wall_back_node.child = &wall_left_node;

    glGetFloatv(GL_MODELVIEW, wall_left_node.m);
    wall_left_node.drawingFunction = drawLeftWall;
    wall_left_node.sibling = NULL;
    wall_left_node.child = &wall_right_node;

    glGetFloatv(GL_MODELVIEW, wall_right_node.m);
    wall_right_node.drawingFunction = drawRightWall;
    wall_right_node.sibling = &table_layer1_node;
    wall_right_node.child = &wall_roof1_node;

    glGetFloatv(GL_MODELVIEW, wall_roof1_node.m);
    wall_roof1_node.drawingFunction = drawRoof1;
    wall_roof1_node.sibling = &wall_roof2_node;
    wall_roof1_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, wall_roof2_node.m);
    wall_roof2_node.drawingFunction = drawRoof2;
    wall_roof2_node.sibling = &wall_roof3_node;
    wall_roof2_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, wall_roof3_node.m);
    wall_roof3_node.drawingFunction = drawRoofBack;
    wall_roof3_node.sibling = &table_layer1_node;
    wall_roof3_node.child = NULL;
}