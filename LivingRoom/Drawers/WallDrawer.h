#import "GLUT/glut.h"

static const int RIGHT_WALL = 14;

static const int LEFT_WALL = 13;

static const int BACK_WALL = 10;

static const int FLOOR = 9;

void drawBackWall();

void drawFloor();
void drawLeftWall();
void drawRightWall();
void createWall(GLUquadricObj *obj, GLuint list);
