#include <stdlib.h>
#import <math.h>
#include <stdio.h>
#import "Input.h"

camera *cam;
item_mover *item_move;
int leftButton = 1;
int rightButton = 1;
int modifierButton;
GLdouble ox = 0.0, oy = 0.0, oz = 0.0;

GLfloat angleX = 0.0;
GLfloat angleY = 0.0;
GLfloat click [] = {0.0, 0.0};
float fraction = 0.5f;
int bookcase = BOOKCASE_NUM;
int table = TABLE_NUM;

int chair = CHAIR_NUM;

void glCoordinatesFromGlut(int x, int y);

void initInputHandler(camera *cam1) {
    cam = cam1;
}

void initItemMover(item_mover *item_move1) {
    item_move = item_move1;
}

void specialKey(int key, int x, int y) {
    modifierButton = glutGetModifiers();

    switch (key) {
        // Camera Controls
        case GLUT_KEY_LEFT:

            angleX -= 0.1f;
            cam->centerX = (GLfloat) sin(angleX);
            cam->centerZ = (GLfloat) -cos(angleX);

            break;
        case GLUT_KEY_RIGHT:

            angleX += 0.1f;

            cam->centerX = (GLfloat) sin(angleX);
            cam->centerZ = (GLfloat) -cos(angleX);

            break;
        case GLUT_KEY_UP:
            if (modifierButton == GLUT_ACTIVE_ALT) {
                cam->eyeY += 1.0;

            } else if (modifierButton == GLUT_ACTIVE_SHIFT) {
                if (item_move->itemToMove == chair) {
                    item_move->chairY = item_move->chairY + 1;

                } else if (item_move->itemToMove == table) {
                    item_move->tableY = item_move->tableY + 1;
                }
            } else {
                cam->eyeX += cam->centerX * fraction;
                cam-> eyeZ += cam->centerZ * fraction;
            }
            break;
        case GLUT_KEY_DOWN:

            if (modifierButton == GLUT_ACTIVE_ALT) {
                cam->eyeY -= 1.0;

            }
            else if (modifierButton == GLUT_ACTIVE_SHIFT) {
                if (item_move->itemToMove == chair) {
                    item_move->chairY = item_move->chairY - 1;

                } else if (item_move->itemToMove == table) {
                    item_move->tableY = item_move->tableY - 1;
                }
            } else {
                cam->eyeX -= cam->centerX * fraction;
                cam-> eyeZ -= cam->centerZ * fraction;
            }
            break;
        default:
            break;
    }

}

void mouse(int btn, int state, int x, int y) {
    glCoordinatesFromGlut(x, y);
    click[0] = x;
    click[1] = y;

    if (btn == GLUT_LEFT_BUTTON&& state == GLUT_DOWN) {

        if (state == GLUT_DOWN) {
            leftButton = 0;

        }
        else
            leftButton = 1;
    }
    if (btn == GLUT_MIDDLE_BUTTON&& state == GLUT_DOWN) {
    }
    if (btn == GLUT_RIGHT_BUTTON&& state == GLUT_DOWN) {
        if (state == GLUT_DOWN) {
            rightButton = 0;
            leftButton = 1;
        }
        else
            rightButton = 1;
    }
//    modifierButton = glutGetModifiers();

}


void motion(int x, int y) {
    glCoordinatesFromGlut(x, y);
    GLfloat distX = click[0] - x;
    GLfloat distY = click[1] - y;

//    if (leftButton == 0) {
//        if (x < glutGet(GLUT_WINDOW_WIDTH) / 2)
//            angleY += distY;
//        if (x > glutGet(GLUT_WINDOW_WIDTH) / 2)
//            angleY -= distY;
//
//        cam->centerX = (GLfloat) sin(angleY);
//        cam->centerZ = (GLfloat) -cos(angleY);
//
//    }

}

void glCoordinatesFromGlut(int x, int y) {
    GLint viewport[4];
    GLdouble modelview[16], projection[16];
    GLfloat wx = x, wy, wz;

    glGetIntegerv(GL_VIEWPORT, viewport);
    y = viewport[3] - y;
    wy = y;
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glReadPixels(x, y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &wz);

    gluUnProject(wx, wy, wz, modelview, projection, viewport, &ox, &oy, &oz);
}

void keyboard(unsigned char key, int x, int y) {
    glCoordinatesFromGlut(x, y);
    int modifierButton = glutGetModifiers();

    if (key == 27) {
        freeTexture(tex->wood);
        freeTexture(tex->oak);
        freeTexture(tex->bookshelf);
        freeTexture(tex->wood_desk);
        freeTexture(tex->frame);
        freeTexture(tex->leather);

        free(cam);
        free(tex);

        exit(0);
    }

    if (key == 'w' || key == 'W') {

        if (modifierButton == GLUT_ACTIVE_SHIFT) {
            if (item_move->itemToMove == chair) {
                item_move->chairZ = item_move->chairZ - 1;

            } else if (item_move->itemToMove == table) {
                item_move->tableZ = item_move->tableZ - 1;
            }
        } else {
            cam->eyeX += cam->centerX * fraction;
            cam-> eyeZ += cam->centerZ * fraction;
        }
    } else if (key == 'a' || key == 'A') {

        if (modifierButton == GLUT_ACTIVE_SHIFT) {
            if (item_move->itemToMove == chair) {
                item_move->chairX = item_move->chairX - 1;

            } else if (item_move->itemToMove == table) {
                item_move->tableX = item_move->tableX - 1;
            }
        } else {
            cam->eyeX -= 10;
        }

    } else if (key == 's' || key == 'S') {

        if (modifierButton == GLUT_ACTIVE_SHIFT) {
            if (item_move->itemToMove == chair) {
                item_move->chairZ = item_move->chairZ + 1;

            } else if (item_move->itemToMove == table) {
                item_move->tableZ = item_move->tableZ + 1;
            }
        } else {
            cam->eyeX -= cam->centerX * fraction;
            cam-> eyeZ -= cam->centerZ * fraction;
        }

    } else if (key == 'd' || key == 'D') {
        if (modifierButton == GLUT_ACTIVE_SHIFT) {
            if (item_move->itemToMove == chair) {
                item_move->chairX = item_move->chairX + 1;

            } else if (item_move->itemToMove == table) {
                item_move->tableX = item_move->tableX + 1;
            }
        } else {
            cam->eyeX += 10;
        }

    } else if (key == '1') {
        glDisable(GL_LIGHT0);
    } else if (key == '2') {
        glEnable(GL_LIGHT0);
    } else if (key == '3') {
        glDisable(GL_LIGHT1);
    } else if (key == '4') {
        glEnable(GL_LIGHT1);
    } else if (key == '5') {
        glDisable(GL_LIGHT2);
    } else if (key == '6') {
        glEnable(GL_LIGHT2);
    } else if (key == '|') {
        if (cam->debugMode == 1)
            cam->debugMode = 0;
        else
            cam->debugMode = 1;
    } else if ((int) key == 9) {
        if (modifierButton == GLUT_ACTIVE_SHIFT) {
        } else {

            if (item_move->itemToMove == table) {
                item_move->itemToMove = chair;
            } else {
                item_move->itemToMove = item_move->itemToMove + 1;
            }

        }
    }
}

