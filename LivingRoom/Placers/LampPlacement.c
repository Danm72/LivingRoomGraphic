#import "LampPlacement.h"

void placeLampBase(GLuint list, GLfloat trans [], GLfloat rotate []) {
    glPushMatrix();
    //glColor3f(0, 0, 0);

    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glCallList(list);
    // glTranslatef(0.0, 0.0, -3.0);
    // gluDisk(quadObj, 0, .5, 30, 30);

    glPopMatrix();
}

void placeLampPole(GLuint list, GLfloat trans [], GLfloat rotate []) {
    glPushMatrix();
    //glColor3f(0, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glCallList(list);
    glPopMatrix();

}

void placeLampCone(GLuint list, GLfloat trans [], GLfloat rotate []) {

    glPushMatrix();
    ////glColor3f(0, 0, 1);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);

    glCallList(list);
    glPopMatrix();
}