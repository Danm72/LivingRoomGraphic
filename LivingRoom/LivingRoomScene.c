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

void init(void) {
    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_CULL_FACE);
//    glCullFace(GL_BACK);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    initInputHandler(cam);

    cam = malloc(sizeof *cam);
    tex = malloc(sizeof *tex);

    cam->eyeX = 0;
    cam->eyeY = 5;
    cam->eyeZ = 0;
    cam->centerX = 0;
    cam->centerY = 0;
    cam->centerZ = -5;
    cam->upX = 0;
    cam->upY = 1;
    cam->upZ = 0;
    cam->debugMode = 0;

    createLightingEnv();
    tex->wood = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/wood_wall.bmp", 256, 256);
    tex->oak = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/LaminatedOak.bmp", 720, 620);
    tex->bookshelf = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/book_400.bmp", 400, 400);
    tex->wood_desk = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/wood_desk.bmp", 1024, 1024);
    tex->frame = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/frame.bmp", 256, 256);
    tex->leather = LoadTexture("/Users/danmalone/Documents/Programming/2014/C:C++/LivingRoomGraphic/LivingRoom/Resources/brown.bmp",1024, 1024);

    initTextures(tex);

    setupWallNodes();

    setupLampNodes();

    setupTableNodes();

    setupStage();

    setupBookCase();

    setupChair();

    setupWindows();

}

GLfloat light0[] = {0.0f, 10.0f, -10.0f, 1.0f};
GLfloat light1[] = {-8.0f, 4.0f, -5.0f, 1.0f};
GLfloat light2[] = {8.0f, 4.0f, -5.0f, 1.0f};

void createLightingEnv() {

    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHT1);
//
//    glEnable(GL_LIGHT2);
//    glEnable(GL_LIGHT3);

    glShadeModel(GL_SMOOTH);

    GLfloat light_dir [] = {10.0, 1.0, 10.0};
    GLfloat exponent = 2;
    GLfloat cut = 95.0f;

    glEnable(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat ambientLight[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat diffuseLight[] = {0.9f, 0.9f, 0.9, 1.0f};
    GLfloat specularLight[] = {0.9f, 0.9f, 0.9f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight);

    glLightfv(GL_LIGHT1, GL_POSITION, light1);

    glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight);

    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_dir);
    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, &cut);
    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, exponent);

    glLightfv(GL_LIGHT2, GL_POSITION, light2);

}


void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glLightfv(GL_LIGHT0, GL_POSITION, light0);
    glLightfv(GL_LIGHT1, GL_POSITION, light1);
    glLightfv(GL_LIGHT2, GL_POSITION, light2);


    glLoadIdentity();

    gluLookAt(cam->eyeX, cam->eyeY, cam->eyeZ,
            cam->eyeX + cam->centerX, cam->eyeY + cam->centerY, cam->eyeZ + cam->centerZ,
            0, 1, 0);

    if(cam->debugMode ==0)
        drawGrid();

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

    glLineWidth(2.0);

    drawVerticalGrid();
    drawHorizontalGrid();
    glLineWidth(1.0);

}

void drawVerticalGrid() {
    for (int i = -100; i < 100; i++) {

        materials(&silver);
        glBegin(GL_LINES);
        glVertex3f(-100.0f, 0, i);
        glVertex3f(100.0f, 0, i);
        glEnd();
    }
}

void drawHorizontalGrid() {
    for (int i = -100; i < 100; i++) {
        materials(&silver);

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
    glutCreateWindow("Lovely Office");
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





