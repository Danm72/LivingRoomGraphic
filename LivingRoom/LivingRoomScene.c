//
//  main.c
//  LivingRoom
//
//  Created by Dan Malone on 10/03/2014.
//
//

#import "LivingRoomScene.h"
#import <stdio.h>
#import <stdlib.h>
#import "Input.h"
#import "WallDrawer.h"
#include "MaterialTypes.h"
#include "LampDrawer.h"
#import "StageDrawer.h"

static GLfloat theta [] = {0.0, 0.0, 0.0};
static GLint axis = 2;
//camera cam1;
camera *cam;

GLfloat lightpos1[] = {0.0, 5.0, 3.0, 1.0};
GLfloat lightpos2[] = {0.0, 1.0, -1.0, 1.0};

GLfloat whiteSpecularLight[] = {1.0, 1.0, 1.0};
GLfloat blackAmbientLight[] = {0.0, 0.0, 0.0};
GLfloat whiteDiffuseLight[] = {1.0, 1.0, 1.0};

treenode lamp_cone_node;
treenode lamp_pole_node;
treenode lamp_base_node;

treenode table_layer1_node;
treenode table_layer2_node;
treenode table_inner1_node;
treenode table_inner2_node;
treenode table_leg1_node;
treenode table_leg2_node;
treenode table_leg3_node;
treenode table_leg4_node;

treenode wall_back_node;
treenode wall_floor_node;
treenode wall_left_node;
treenode wall_right_node;

treenode stage_level1_node;
treenode stage_level2_node;

void errorCallback(GLenum errorCode) {
    const GLubyte *estring;
    estring = gluErrorString(errorCode);
    fprintf(stderr, "Quadric Error: %s\n", estring);
    exit(0);
}

//void (^translateBlock)(GLfloat []) = ^(GLfloat translateCoOrds []) {
//
//    glTranslatef(translateCoOrds[0], translateCoOrds[1],translateCoOrds[2]);
//};

void init(void) {
    initInputHandler(cam);
    createLightingEnv();

    cam = malloc(sizeof *cam);

    cam->eyeX = 0;
    cam->eyeY = 1;
    cam->eyeZ = -5;
    cam->centerX = 0;
    cam->centerY = 0;
    cam->centerZ = -5;
    cam->upX = 0;
    cam->upY = 1;
    cam->upZ = 0;
//    cam-> directionX = 0.0;
//    cam-> directionZ = -5.0;
//    cam-> directionY = 0.0;

    startList = glGenLists(30);

    setupWallNodes();

    setupLampNodes();

    setupTableNodes();

    setupStage();

//    gluQuadricCallback(qobj, GLU_ERROR, (GLvoid ( *)()) errorCallback);
}

/*
void setPosition(float angle, float posX, float posZ, float posY)
{
    xPos = posX;
    zPos = posZ;
    yPos = posY;

    //compute instead of set based on angle
    angleY = angle;
    directionX = sin(angleY);
    directionZ = -cos(angleY);
}
*/

void setupTableNodes() {
    glGetFloatv(GL_MODELVIEW, table_layer1_node.m);
    table_layer1_node.drawingFunction = drawTableLayer1;
    table_layer1_node.sibling = NULL;
    table_layer1_node.child = &table_layer2_node;

    glGetFloatv(GL_MODELVIEW, table_layer2_node.m);
    table_layer2_node.drawingFunction = drawTableLayer2;
    table_layer2_node.sibling = NULL;
    table_layer2_node.child = &table_leg1_node;

    glGetFloatv(GL_MODELVIEW, table_leg1_node.m);
    table_leg1_node.drawingFunction = drawTableLeg1;
    table_leg1_node.sibling = &table_leg2_node;
    table_leg1_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, table_leg2_node.m);
    table_leg2_node.drawingFunction = drawTableLeg2;
    table_leg2_node.sibling = &table_leg3_node;
    table_leg2_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, table_leg3_node.m);
    table_leg3_node.drawingFunction = drawTableLeg3;
    table_leg3_node.sibling = &table_leg4_node;
    table_leg3_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, table_leg4_node.m);
    table_leg4_node.drawingFunction = drawTableLeg4;
    table_leg4_node.sibling = &table_inner1_node;
    table_leg4_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, table_inner1_node.m);
    table_inner1_node.drawingFunction = drawTableInner1;
    table_inner1_node.sibling = &table_inner2_node;
    table_inner1_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, table_inner2_node.m);
    table_inner2_node.drawingFunction = drawTableInner2;
    table_inner2_node.sibling = NULL;
    table_inner2_node.child = &lamp_cone_node;
}

void setupLampNodes() {
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW, lamp_cone_node.m);
    lamp_cone_node.drawingFunction = drawCone;
    lamp_cone_node.sibling = NULL;
    lamp_cone_node.child = &lamp_pole_node;

    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW, lamp_pole_node.m);
    lamp_pole_node.drawingFunction = drawPole;
    lamp_pole_node.sibling = NULL;
    lamp_pole_node.child = &lamp_base_node;

    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW, lamp_base_node.m);
    lamp_base_node.drawingFunction = drawBase;
    lamp_base_node.sibling = NULL;
    lamp_base_node.child = NULL;
}

void setupWallNodes() {

    glGetFloatv(GL_MODELVIEW, wall_floor_node.m);
    wall_floor_node.drawingFunction = drawFloor;
    wall_floor_node.sibling = &wall_back_node;
    wall_floor_node.child = &table_layer1_node;

    glGetFloatv(GL_MODELVIEW, wall_back_node.m);
    wall_back_node.drawingFunction = drawBackWall;
    wall_back_node.sibling = &wall_left_node;
    wall_back_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, wall_left_node.m);
    wall_left_node.drawingFunction = drawLeftWall;
    wall_left_node.sibling = &wall_right_node;
    wall_left_node.child = NULL;

    glGetFloatv(GL_MODELVIEW, wall_right_node.m);
    wall_right_node.drawingFunction = drawRightWall;
    wall_right_node.sibling = NULL;
    wall_right_node.child = &stage_level1_node;

}


void setupStage() {
    glGetFloatv(GL_MODELVIEW, stage_level1_node.m);
    stage_level1_node.drawingFunction = drawLvl1;
    stage_level1_node.sibling = NULL;
    stage_level1_node.child = &stage_level2_node;

    glGetFloatv(GL_MODELVIEW, stage_level2_node.m);
    stage_level2_node.drawingFunction = drawLvl2;
    stage_level2_node.sibling = NULL;
    stage_level2_node.child = NULL;

}


void light(void) {
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
}


void createLightingEnv() {

    glEnable(GL_DEPTH_TEST);
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
//    glShadeModel (GL_SMOOTH);

    glEnable(GL_LIGHT1);

    glEnable(GL_MODELVIEW);
    glLoadIdentity();



//    glLightfv(GL_LIGHT0, GL_POINT, lightpos);

    GLfloat bluish [] = {0.9f, 0.9f, 0.9f, 1};

    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 5);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, bluish);
    glLightfv(GL_LIGHT0, GL_SPECULAR, bluish);
    glLightfv(GL_LIGHT0, GL_AMBIENT, bluish);

    // glLightfv(GL_LIGHT1, GL_POSITION, lightpos2);

    glLightfv(GL_LIGHT1, GL_DIFFUSE, bluish);
    glLightfv(GL_LIGHT1, GL_SPECULAR, bluish);
    glLightfv(GL_LIGHT1, GL_AMBIENT, bluish);

}


void freeTexture(GLuint texture) {
    glDeleteTextures(1, &texture);
}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLightfv(GL_LIGHT0, GL_POSITION, lightpos1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightpos2);
    glLoadIdentity();

/*    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ,
            cam->centerX, cam->centerY, cam->centerZ,
            cam->upX, cam->upY, cam->upZ);*/

    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ,
            cam->eyeX + cam->centerX, cam->eyeY + cam->centerY, cam->eyeZ + cam->centerZ,
            0, 1, 0);

//    gluLookAt(	x, 1.0f, z,
//            x+lx, 1.0f, z+lz,
//            0.0f, 1.0f, 0.0f);

    drawGrid();

//    glLoadIdentity();
    traverse(&wall_floor_node);
    glutSwapBuffers();

    glFlush();

    return;
}

void drawGrid() {
    glLineWidth(5.0);

    materials(&red);

    glBegin(GL_LINES);
    glVertex3f(0, 0, -100.0f);
    glVertex3f(0, 0, 100.0f);
    glEnd();

    materials(&blue);

    glBegin(GL_LINES);
    glVertex3f(0, -100, 0.0f);
    glVertex3f(0, 100, 0.0f);
    glEnd();

    materials(&green);

    glBegin(GL_LINES);
    glVertex3f(-100.0f, 0, 0.0f);
    glVertex3f(100.0f, 0, 0.0f);
    glEnd();

    glTranslatef(0, 0, -5);
    glLineWidth(2.0);

    drawVerticalGrid();
    drawHorizontalGrid();
    glLineWidth(1.0);

}

void drawVerticalGrid() {
    for (int i = -100; i < 100; i++) {
        //  glColor4f(0.0f,1.0f,0.0f,1.0f);//Change the object color to red
        materials(&white);
        glBegin(GL_LINES);
        glVertex3f(-100.0f, 0, i);
        glVertex3f(100.0f, 0, i);
        glEnd();
    }
}

void drawHorizontalGrid() {
    for (int i = -100; i < 100; i++) {
        materials(&white);

        glBegin(GL_LINES);
        glVertex3f(i, 0.0f, -100);
        glVertex3f(i, 0.0f, 100);
        glEnd();
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    if (w <= h)
    glFrustum(-1, 1, -1, 1, 1.0, 150);
//    glFrustum(-2.5 * (GLfloat) w / (GLfloat) h,
//            2.5 * (GLfloat) w / (GLfloat) h, -2.5, 2.5, 1.5, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void idle() {
    glutPostRedisplay();
}

int main(int argc, const char *argv[]) {
    //glEnable(GL_TEXTURE_2D);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutSpecialFunc(specialKey);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}





