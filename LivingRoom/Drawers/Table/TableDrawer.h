#ifndef TABLEDRAWER_H_

#import  "TreeNode.h"
#import "SolidCube_Tex.h"
#import "Drawer.h"
#import "Placement.h"

treenode table_layer1_node;
treenode table_layer2_node;
treenode table_inner1_node;
treenode table_inner2_node;
treenode table_leg1_node;
treenode table_leg2_node;
treenode table_leg3_node;
treenode table_leg4_node;
treenode teapot_node;

void setupTableNodes();

void drawTableLeg4();

void createTableLayer(GLUquadricObj *obj, GLuint list);

void createTableLeg(GLUquadricObj *obj, GLuint list);

void createTableInnerBeam(GLUquadricObj *obj, GLuint list);

#endif
