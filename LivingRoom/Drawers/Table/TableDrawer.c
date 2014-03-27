#import "TableDrawer.h"

void drawTableLayer1() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createTableLayer(quadObj, startList + 3);

    GLfloat layer1[] = {0.0, 2.0, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    placeTableLayer(startList + 3, layer1, rotate, scale);
}

void drawTableLayer2() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createTableLayer(quadObj, startList + 4);

    GLfloat layer2[] = {0.0, 1.5, -3.75};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {75.0, 1.0, 25.0};

    placeTableLayer(startList + 4, layer2, rotate, scale);
}


void drawTableInner1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableInnerBeam(quadObj, startList + 5);
    GLfloat leg[] = {-3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};

    placeTableInnerBeam(startList + 5, leg, rotate);
}


void drawTableInner2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableInnerBeam(quadObj, startList + 6);
    GLfloat leg[] = {3.5, 2.0, -2.75};
    GLfloat rotate[] = {90, 1, 0.0, 0.0};

    placeTableInnerBeam(startList + 6, leg, rotate);
}


void drawTableLeg1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 7);
    GLfloat leg[] = {-3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + 7, leg, rotate, scale);
}

void drawTableLeg2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 8);
    GLfloat leg[] = {3.5, 0.7, -2.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + 8, leg, rotate, scale);
}

void drawTableLeg3() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 11);
    GLfloat leg[] = {-3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + 11, leg, rotate, scale);
}


void drawTableLeg4() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 12);
    GLfloat leg[] = {3.5, 0.7, -4.75};
    GLfloat rotate[] = {0, 0, 0.0, 0.0};
    GLfloat scale[] = {2.5, 15, 2.5};

    placeTableLeg(startList + 12, leg, rotate, scale);
}