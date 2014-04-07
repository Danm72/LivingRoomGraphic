#import "Drawer.h"
#import "GLUT/glut.h"
#include "TreeNode.h"

void drawChairLegs();

void drawChairStand();
void drawChairFeet();
void drawChairSeat();
void drawChairArm_left();
void drawChairArm_right();
void drawChairBack();
void setupChair();

treenode chair_legs_node;
treenode chair_stand_node;
treenode chair_feet_node;
treenode chair_seat_node;
treenode chair_back_node;
treenode chair_arm_left_node;
treenode chair_arm_right_node;