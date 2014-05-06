#import "Drawer.h"
#import "GLUT/glut.h"
#include "TreeNode.h"

treenode stage_level1_node;
treenode stage_level2_node;

static const int STAGE_LVL1 = 16;

static const int STAGE_LVL2 = 17;

void drawLvl1();

void drawLvl2();

void defineDrawStyle_Stage(GLUquadricObj *qobj, GLuint startList1);

void setupStage();
