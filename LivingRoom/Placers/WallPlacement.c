#import "WallPlacement.h"

void placeWall(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat scale []) {
    glPushMatrix();
    //glColor3f(0,0,1);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glScalef(scale[0], scale[1], scale[2]);
    glCallList(list);
    glPopMatrix();
}
