#import "Placement.h"

void placeTable() {
    GLfloat layer1[] = {3.0, 0.0, -4.0};
    placeTableLayer(startList + 3, layer1);
    GLfloat layer2[] = {3.0, 0.0, -3.5};
    placeTableLayer(startList + 4, layer2);

    for (int i = 5; i < 9; i++) {
        GLfloat leg[] = {2.5, 0.0, -4.5};
        placeTableLeg(startList + i, leg);
    }
}

void placeTableLayer(GLuint list, GLfloat trans []) {
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glScalef(10.0, 10.0, 0.5);
    glRotatef(0.0, 0.0, 0.0, 0.0);
    glCallList(list);
    glPopMatrix();
}

void placeWall(GLuint list, GLfloat trans [], GLfloat rotate []) {
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(rotate[0], rotate[1], rotate[2], rotate[3]);
    glScalef(100.0, 100.0, 1.0);
    glCallList(list);
    glPopMatrix();
}

void placeTeapot() {
    glPushMatrix();
    glColor3f(0, 1.0, 0);
    glTranslatef(1.0, -2.0, -4.5);
    glRotatef(90.0, 0.0, .0, 0.0);
    glutSolidTeapot(0.5);
    glPopMatrix();
}

void placeLampBase() {
    glPushMatrix();
   // glColor3f(1, 0, 0);
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(0.0, 0.0, .0, 0.0);
    glCallList(startList + 2);
   // glTranslatef(0.0, 0.0, -3.0);
   // gluDisk(quadObj, 0, .5, 30, 30);
    glPopMatrix();
}

void placeLampPole() {
    glPushMatrix();
    //glColor3f(0, 1, 0);
    glTranslatef(0.0, 0.0, -5.0);
    glRotatef(0.0, 0.0, 0.0, 0.0);
    glCallList(startList + 1);
    glPopMatrix();
}

void placeLampCone() {
    glPushMatrix();
   // glColor3f(1, 0, 0);
    glTranslatef(0.0, 0.0, -3.5);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glCallList(startList);
    glPopMatrix();
}

void placeTableLeg(GLint list, GLfloat trans []) {
    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(trans[0], trans[1], trans[2]);
    glRotatef(0.0, 1.0, 0.0, 0.0);
    glCallList(list);
    glPopMatrix();
}