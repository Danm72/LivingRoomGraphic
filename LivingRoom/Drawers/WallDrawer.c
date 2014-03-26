#include "ObjectCreator.h"
#import "WallDrawer.h"

void drawBackWall(){
    GLUquadricObj *quadObj = gluNewQuadric();

    createWall(quadObj, startList + 10);
//    createFlatSurface(quadObj, startList + 11);
//    createFlatSurface(quadObj, startList + 12);
    GLfloat location1[] = {0.0, 5.0, -5.0};
    GLfloat rotate1[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {100.0, 100.0, 1.0};

    placeWall(startList + 10, location1, rotate1, scale);
}

void drawFloor(){
    GLUquadricObj *quadObj = gluNewQuadric();

    createWall(quadObj, startList + 9);

    GLfloat location[] = {0.0, 0.0, 0.0};
    GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
    GLfloat scale[] = {100.0, 1.0, 100.0};

    placeWall(startList + 9, location, rotate, scale);

}