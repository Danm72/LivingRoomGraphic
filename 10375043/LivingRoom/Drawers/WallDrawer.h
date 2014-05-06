#import "GLUT/glut.h"
#import "Drawer.h"
#include "SolidCube_Tex.h"

treenode wall_back_node;
treenode wall_floor_node;
treenode wall_left_node;
treenode wall_right_node;
treenode wall_roof1_node;
treenode wall_roof2_node;
treenode wall_roof3_node;

static const int BACK_WALL = 10;

static const int FLOOR = 9;

void drawBackWall();

void drawFloor();

void drawLeftWall();

void drawRightWall();

void createWall(GLUquadricObj *obj, int repeats);

void drawRoof2();

void drawRoof1();

void drawRoofBack();

void setupWallNodes();
