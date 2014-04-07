#import "Drawer.h"
#import  "Placement.h"

#import "TableDrawer.h"
#include "TreeNode.h"

treenode table_layer1_node;
treenode table_layer2_node;
treenode table_inner1_node;
treenode table_inner2_node;
treenode table_leg1_node;
treenode table_leg2_node;
treenode table_leg3_node;
treenode table_leg4_node;

void setupTableNodes();

void drawTableLayer1();

void drawTableLayer2();

void drawTableInner1();

void drawTableInner2();

void drawTableLeg1();

void drawTableLeg2();

void drawTableLeg3();

void drawTableLeg4();
void createTableLayer(GLUquadricObj *obj, GLuint list) ;

void createTableLeg(GLUquadricObj *obj, GLuint list);
void createTableInnerBeam(GLUquadricObj *obj, GLuint list);

