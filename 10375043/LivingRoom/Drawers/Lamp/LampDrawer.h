#include "Placement.h"
#include <sys/_types/_null.h>
#import "LampDrawer.h"
#import "TreeNode.h"
#import "Drawer.h"

treenode lamp_cone_node;
treenode lamp_pole_node;
treenode lamp_base_node;

treenode lamp_cone2_node;
treenode lamp_pole2_node;
treenode lamp_base2_node;

static const int LAMP_CONE = 0;

static const int LAMP_POLE = 1;

static const int LAMP_BASE = 2;

void drawCone();

void drawPole();

void drawBase();

void setupLampNodes();
