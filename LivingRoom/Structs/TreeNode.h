#include "GLUT/glut.h"

typedef struct treenode {
    GLfloat m[16];

    void (*drawingFunction)();

    struct treenode *sibling;
    struct treenode *child;
} treenode;

void traverse(treenode *root);