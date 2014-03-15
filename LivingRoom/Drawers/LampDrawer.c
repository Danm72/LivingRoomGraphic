#import "LampDrawer.h"

void drawCone() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createLampCone(quadObj);
    placeLampCone();
}

void drawPole() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createLampPole(quadObj);
    placeLampPole();
}

void drawBase() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createLampBase(quadObj);
    placeLampBase();
}

void setupNodes(treenode lamp_cone_node, treenode lamp_pole_node, treenode lamp_base_node) {

}