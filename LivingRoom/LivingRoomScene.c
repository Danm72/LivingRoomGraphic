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
#include "MaterialTypes.h"

camera *cam;
textures *tex;

GLfloat lightpos1[] = {0.0, 10.0, -17.0, 1.0};
GLfloat lightpos2[] = {0.0, 2.0, -17.0, 1.0};

void errorCallback(GLenum errorCode) {
    const GLubyte *estring;
    estring = gluErrorString(errorCode);
    fprintf(stderr, "Quadric Error: %s\n", estring);
    exit(0);
}

#define PI 3.14159265

void init(void) {
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    initInputHandler(cam);

    cam = malloc(sizeof *cam);
    tex = malloc(sizeof *tex);

    cam->eyeX = 0;
    cam->eyeY = 1;
    cam->eyeZ = -5;
    cam->centerX = 0;
    cam->centerY = 0;
    cam->centerZ = -5;
    cam->upX = 0;
    cam->upY = 1;
    cam->upZ = 0;

    createLightingEnv();
    tex->bookcase = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/bookshelf_1024.bmp", 1024, 1024);
    tex->cream = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/cream_256.bmp", 256, 256);
    tex->wood = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/wood_wall.bmp", 256, 256);
    tex->oak = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 720, 620);
    tex->bookshelf = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/book_400.bmp", 400, 400);
    tex->wood_desk = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/wood_desk.bmp", 1024, 1024);
    tex->fabric = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/fabric.bmp", 1024, 1024);
    tex->frame = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/frame.bmp", 256, 256);

    initTextures(tex);

    setupWallNodes();

    setupLampNodes();

    setupTableNodes();

    setupStage();

    setupBookCase();

    setupChair();

    setupWindows();

}


//GLfloat light_pos [] = {4.0, 4.0, -15.0, 1.0};
GLfloat position[] = {0.0f, 5.0f, 0.0f, 0.0f};


void createLightingEnv() {

//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);

    glShadeModel(GL_SMOOTH);


    glEnable(GL_MODELVIEW);
    glLoadIdentity();

//    glLightfv(GL_LIGHT0, GL_POINT, lightpos);

    GLfloat lightParams [] = {0.9f, 0.9f, 0.9f, 1};
//
//    //glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 5);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightParams);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, lightParams);
//    glLightfv(GL_LIGHT0, GL_AMBIENT, lightParams);
//
//    // glLightfv(GL_LIGHT1, GL_POSITION, lightpos2);
//
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightParams);
//    glLightfv(GL_LIGHT1, GL_SPECULAR, lightParams);
//    glLightfv(GL_LIGHT1, GL_AMBIENT, lightParams);

//    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8, 1.0f };
//    GLfloat specularLight[] = { 0.5f, 0.5f, 0.5f, 1.0f };

    GLfloat ambientLight[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat diffuseLight[] = {0.9f, 0.9f, 0.9, 1.0f};
    GLfloat specularLight[] = {0.9f, 0.9f, 0.9f, 1.0f};

    float ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
    float diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float specular[] = {1.0f, 1.0f, 1.0f, 1.0f};

// Assign created components to GL_LIGHT0
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
//    glLightfv(GL_LIGHT0, GL_POSITION, position);

    GLfloat light_dir [] = {0.0, -1.0, 0.0};
    GLfloat cutoff = 90.0f;
    GLfloat expo = 100;
//
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);
    glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, &cutoff);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, expo);
    glLightfv(GL_LIGHT0, GL_POSITION, position);


    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

//
//    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir);
//    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, &cutoff);
//    glLightf(GL_LIGHT1,GL_SPOT_EXPONENT, expo);
//    GLfloat position2[] = { cam->eyeX, cam->eyeY, cam->eyeZ, 1.0f };
//
//    glLightfv(GL_LIGHT1, GL_POSITION, position2);

}


void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLightfv(GL_LIGHT0, GL_POSITION, position);

//    GLfloat position2[] = {cam->eyeX, cam->eyeY, cam->eyeZ, 1.0f};
//    glLightfv(GL_LIGHT1, GL_POSITION, position2);
    glLoadIdentity();

    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ,
            cam->eyeX + cam->centerX, cam->eyeY + cam->centerY, cam->eyeZ + cam->centerZ,
            0, 1, 0);

    drawGrid();

    traverse(&wall_floor_node);

//    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    float R = 5.0; // Radius of hemisphere.
    int p = 6; // Number of longitudinal slices.
    int q = 4; // Number of latitudinal slices.
    float Xangle, Yangle, Zangle = 0.0; // Angles to rotate hemisphere.

    glTranslatef(0, 5, 0);
//    glRotatef(180, 1, 0, 0);
    glScalef(.2, .3, .1);

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

//    glTranslatef(0, 0, -5);
    glLineWidth(2.0);

    drawVerticalGrid();
    drawHorizontalGrid();
    glLineWidth(1.0);

}

void drawVerticalGrid() {
    for (int i = -100; i < 100; i++) {

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
//    if (w <= h){

    GLfloat ratio = (GLfloat) w / (GLfloat) h;
    glLoadIdentity();
    if (w <= h) {
        glFrustum(-1 / ratio, 1 / ratio, -1, 1, 1.0, 50.0);
    } else {
        glFrustum(-1 * ratio, 1 * ratio, -1, 1, 1.0, 50.0);
    }

}

void idle() {
    glutPostRedisplay();
}

int main(int argc, const char *argv[]) {

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

    freeTexture(tex->wood);
    freeTexture(tex->oak);
    freeTexture(tex->cream);
    freeTexture(tex->bookcase);
    freeTexture(tex->bookshelf);
    freeTexture(tex->wood_desk);

    return 0;
}





