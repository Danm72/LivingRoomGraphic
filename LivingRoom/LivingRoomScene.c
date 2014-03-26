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

static GLfloat theta [] = {0.0, 0.0, 0.0};
static GLint axis = 2;
GLUquadricObj *quadObj;
camera cam1;
camera *cam = &cam1;

float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 0.0f;

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


GLfloat xPos = 0.0;
GLfloat zPos = 1.0;
GLfloat yPos = 2.0;


void setupLampNodes();

void setupTableNodes();

void drawHorizontalGrid();

void drawVerticalGrid();

void drawGrid();

void setupWallNodes();

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
    glLoadIdentity();

    cam->eyeX = 0;
    cam->eyeY = 1;
    cam->eyeZ = -5;
    cam->centerX = 0;
    cam->centerY = 0;
    cam->centerZ = 0;
    cam->upX = 0;
    cam->upY = 1;
    cam->upZ = 0;
    cam-> directionX = 0.0;
    cam-> directionZ = -5.0;
    cam-> directionY = 0.0;

    startList = glGenLists(14);
    quadObj = gluNewQuadric();

    setupWallNodes();

    setupLampNodes();

    setupTableNodes();

    gluQuadricCallback(quadObj, GLU_ERROR, (GLvoid ( *)()) errorCallback);
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
    table_inner2_node.child = NULL;
}

void setupLampNodes() {
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW, lamp_cone_node.m);
    lamp_cone_node.drawingFunction = drawCone;
    lamp_cone_node.sibling = &table_layer1_node;
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
    wall_floor_node.child = &lamp_cone_node;

    glGetFloatv(GL_MODELVIEW, wall_back_node.m);
    wall_back_node.drawingFunction = drawBackWall;
    wall_back_node.sibling = NULL;
    wall_back_node.child = NULL;

}

void light(void) {
    glLightfv(GL_LIGHT0, GL_SPECULAR, whiteSpecularLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);
}

void createLightingEnv() {

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLfloat lightpos[] = {0.0, 0.0, 0.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

/*    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ,
            cam->centerX, cam->centerY, cam->centerZ,
            cam->upX, cam->upY, cam->upZ);*/

//    gluLookAt(x, 10.0f, z,
//            x + lx, 0.0f, z + lz,
//            0.0f, 1.0f, 0.0f);


    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ,
            cam->eyeX + cam->directionX, cam->eyeY + cam->directionY, cam->eyeZ + cam->directionZ,
            0, 1, 0);

    drawGrid();

    // glTranslatef(0, 0, 5);

    // glScalef(10, 10, 10);
    traverse(&wall_floor_node);

    //Teapot?
    //placeTeapot();

/*    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.0);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.0, 0.8);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, 0.0);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.0, 0.0);
    glEnd();*/

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
    glFrustum(-1, 1, -1, 1, 1.5, 150);
//    glFrustum(-2.5 * (GLfloat) w / (GLfloat) h,
//            2.5 * (GLfloat) w / (GLfloat) h, -2.5, 2.5, 1.5, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*void specialKey1(int key, int x, int y) {
    float fraction = 0.1f;

    switch (key) {
        case GLUT_KEY_LEFT :
            angle -= 0.1f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_RIGHT :
            angle += 0.1f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
            break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
            break;
    }


    glutPostRedisplay();
}*/


int main(int argc, const char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    // glutIdleFunc(spin);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}





