#import "Placement.h"

void placeItem(GLfloat trans [], GLfloat rotate [], GLfloat scale []) {

    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    if (scale[0] != 0 || scale[1] != 0 || scale[2] != 0)
        glScalef(scale[0], scale[1], scale[2]);

}
