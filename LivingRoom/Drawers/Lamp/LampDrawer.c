#import "LampDrawer.h"

void drawCone() {
    GLUquadricObj *quadObj = gluNewQuadric();
    glTranslatef(-3, 1, -5);
    createLampCone(quadObj);
    GLfloat trans [] = {0.0, 3.0, 1.0};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    placeLampCone(startList, trans, rotate);
}

void drawPole() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createLampPole(quadObj);
    GLfloat trans [] = {0.0, 1.0, 1.0};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    placeLampPole(startList + 1, trans, rotate);
}

void drawBase() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createLampBase(quadObj);
    GLfloat trans [] = {0.0, 1.0, 1.0};
    GLfloat rotate [] = {270, 1, 0.0, 0.0};
    placeLampBase(startList + 2, trans, rotate);
}

void setupNodes(treenode lamp_cone_node, treenode lamp_pole_node, treenode lamp_base_node) {

}