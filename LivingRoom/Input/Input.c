#include <stdio.h>
#include <stdlib.h>
#import <math.h>
#import "Input.h"

camera *cam;
int leftButton = 1;
int rightButton = 1;
int modifierButton;
GLdouble ox = 0.0, oy = 0.0, oz = 0.0;

GLfloat angleX = 0.0;
GLfloat angleY = 0.0;
GLfloat click [] = {0.0, 0.0};
float fraction = 0.3f;


void glCoordinatesFromGlut(int x, int y);

void initInputHandler(camera *cam1) {
    cam = cam1;
}

void specialKey(int key, int x, int y) {
    modifierButton = glutGetModifiers();

    switch (key) {
        // Camera Controls
        case GLUT_KEY_LEFT:
            angleX -= 0.05f;
            cam->centerX = (GLfloat) sin(angleX);
            cam->centerZ = (GLfloat) -cos(angleY);

            break;
        case GLUT_KEY_RIGHT:
            angleX += 0.05f;

            cam->centerX = (GLfloat) sin(angleX);
            cam->centerZ = (GLfloat) -cos(angleX);
            break;
        case GLUT_KEY_UP:
            if (modifierButton == GLUT_ACTIVE_ALT) {
                cam->eyeY += 0.1;

            } else {
                cam->eyeX += cam->centerX * fraction;
                cam-> eyeZ += cam->centerZ * fraction;
            }
            break;
        case GLUT_KEY_DOWN:
            if (modifierButton == GLUT_ACTIVE_ALT) {

                cam->eyeY -= 0.1;

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
    modifierButton = glutGetModifiers();

}


void motion(int x, int y) {
    glCoordinatesFromGlut(x, y);
    GLfloat distX = click[0] - x;
    GLfloat distY = click[1] - y;

    printf("output x:%f output y:%f output z:%f\n", ox, oy, oz);

    if (leftButton == 0) {
        if (x < glutGet(GLUT_WINDOW_WIDTH) / 2)
            angleY -= distY;
        if (x > glutGet(GLUT_WINDOW_WIDTH) / 2)
            angleY += distY;

        cam->centerX = (GLfloat) sin(angleY);
        cam->centerZ = (GLfloat) -cos(angleY);

    }

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
    printf("mouse x:%d mouse y:%d\n", x, y);
    printf("output ox:%f output oy:%f output oz:%f\n", ox, oy, oz);

    if (key == 27) {
        exit(0);
    }

    if (key == 'w') {
        cam->eyeY += 10;
    } else if (key == 'a') {
        cam->eyeX -= 10;
    } else if (key == 's') {
        cam->eyeY -= 10;
    } else if (key == 'd') {
        cam->eyeX += 10;
    }
}

