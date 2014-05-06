#include <sys/_types/_null.h>
#import "TreeNode.h"


void traverse(treenode *root) {
    if (root == NULL) return;
    glPushMatrix();
    glMultMatrixf(root->m);
    root->drawingFunction();
    if (root->child != NULL)
        traverse(root->child);
    glPopMatrix();
    if (root->sibling != NULL)
        traverse(root->sibling);
}

