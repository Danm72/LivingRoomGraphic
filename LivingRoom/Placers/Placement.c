#import "Placement.h"

void placeTableLayer(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat scale []) {
    glPushMatrix();
   // //glColor3f(1, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glScalef(scale[0], scale[1], scale[2]);
    glCallList(list);
    glPopMatrix();
}

void placeWall(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat scale []) {
    glPushMatrix();
    //glColor3f(0,0,1);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glScalef(scale[0], scale[1], scale[2]);
    glCallList(list);
    glPopMatrix();
}

void placeTeapot(GLfloat trans [], GLfloat rotate []) {
    glPushMatrix();
    ////glColor3f(0, 1.0, 0);
    glTranslatef(3.0, 1.0, 2);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glutSolidTeapot(0.5);

    glPopMatrix();
}

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

void placeTableInnerBeam(GLuint list, GLfloat trans [], GLfloat rotate []) {
    glPushMatrix();
    ////glColor3f(1, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glCallList(list);
    glPopMatrix();
}


void placeTableLeg(GLuint list, GLfloat trans [], GLfloat rotate [], GLfloat scale []) {
    glPushMatrix();
    // //glColor3f(1, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glScalef(scale[0], scale[1], scale[2]);
    glCallList(list);
    glPopMatrix();
}