#import  "Placement.h"

#import "TableDrawer.h"

static const int TABLE_LAYER_1 = 3;

static const int TABLE_LAYER_2 = 4;

static const int TABLE_INNER_1 = 5;

static const int TABLE_INNER_2 = 6;

static const int TABLE_LEG_1 = 7;

static const int TABLE_LEG_2 = 8;

static const int TABLE_LEG_3 = 11;

static const int TABLE_LEG_4 = 12;

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

