#import "TableDrawer.h"

void drawTableLayer1() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createFlatSurface(quadObj, startList + 3);

    GLfloat layer1[] = {3.0, 0.0, -4.5};
    placeTableLayer(startList+3, layer1);
}

void drawTableLayer2() {
    GLUquadricObj *quadObj = gluNewQuadric();
    createFlatSurface(quadObj, startList + 4);

    GLfloat layer2[] = {3.0, 0.0, -4.0};
    placeTableLayer(startList+4, layer2);}


void drawTableLeg1() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 5);
    GLfloat leg[] = {3.5, 0.5, -5.0};
    placeTableLeg(startList + 5, leg);
}


void drawTableLeg2() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 6);
    GLfloat leg[] = {3.5, -0.5, -5.0};
    placeTableLeg(startList +6, leg);
}


void drawTableLeg3() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 7);
    GLfloat leg[] = {2.5, -0.5, -5.0};
    placeTableLeg(startList + 7, leg);

}


void drawTableLeg4() {
    GLUquadricObj *quadObj = gluNewQuadric();

    createTableLeg(quadObj, startList + 8);
    GLfloat leg[] = {2.5, 0.5, -5.0};
    placeTableLeg(startList + 8, leg);

}