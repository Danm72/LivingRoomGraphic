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
GLfloat centers [] = {0, 0, 0};
float fraction = 0.3f;

void glCoordinatesFromGlut(int x, int y);

void initInputHandler(camera *cam1) {
    cam = cam1;
}

/*void specialKey(int key, int x, int y) {
    switch (key) {
        default:

        case GLUT_KEY_UP:
            //cam->eyeY += 5.0;
            cam->centerY += 10.0;

            break;
        case GLUT_KEY_DOWN:
            // cam->eyeY -= 5.0;
            cam->centerY -= 10.0;

            break;
        case GLUT_KEY_LEFT:
//            angle -= 0.1f;
//
//            //cam->eyeX += 10.0;
//            cam->eyeX = sin(angle);

            break;
        case GLUT_KEY_RIGHT:
//            angle += 0.1f;
//            cam->eyeX = cam->eyeX + sin(angle);
//            cam->eyeX = cos(angle);

            //  cam->eyeX += 10.0;
           // cam->centerX += 10.0;

            break;

    }
    glutPostRedisplay();

}*/

void specialKey(int key, int x, int y) {

    switch (key) {
        // Camera Controls
        case GLUT_KEY_LEFT:
            angleY -= 0.05f;
            printf("sinY y:%f\n", sin(angleY));

            cam-> directionX = sin(angleY);
            cam->directionZ = -cos(angleY);
/*            cam->directionZ=0;
            cam->directionX=5;

            cam->eyeX -= cam->directionX * fraction;
            cam->eyeZ -= cam->directionZ * fraction;
            cam->eyeY -= cam->directionY * fraction;*/
            break;
        case GLUT_KEY_RIGHT:
            angleY += 0.05f;
            printf("sinY y:%f\n", sin(angleY));

            cam-> directionX = sin(angleY);
            cam-> directionZ = -cos(angleY);
/*            cam->directionZ=0;
            cam->directionX=5;

            cam->eyeX += cam->directionX * fraction;
            cam->eyeZ += cam->directionZ * fraction;
            cam->eyeY += cam->directionY * fraction;*/
            break;
        case GLUT_KEY_UP:
            cam->directionZ=-5;
            cam->directionX=-0;
            cam->eyeX += cam->directionX * fraction;
            cam->eyeZ += cam->directionZ * fraction;
            cam->eyeY += cam->directionY * fraction;
            break;
        case GLUT_KEY_DOWN:
            cam->directionZ=-5;
            cam->directionX=-0;
            cam->eyeX -= cam->directionX * fraction;
            cam->eyeZ -= cam->directionZ * fraction;
            cam->eyeY -= cam->directionY * fraction;
            break;
        default:
            break;
    }
    glutPostRedisplay();

}


void mouse(int btn, int state, int x, int y) {
    glCoordinatesFromGlut(x, y);

    if (btn == GLUT_LEFT_BUTTON&& state == GLUT_DOWN) {

        if (state == GLUT_DOWN) {
            leftButton = 0;
            //cam->centerX += ox;
            //cam->eyeX = ox;
            printf("sinY y:%f\n", sin(angleY));

            /*         if (sin(angleY) >= 360)
                         angleY = 0;*/
            float x1 =  glutGet(GLUT_WINDOW_WIDTH);
            float y1 = glutGet(GLUT_WINDOW_HEIGHT);
            printf("width y:%f\n", x1);
            printf("height x:%f\n", y1);
            if (x < glutGet(GLUT_WINDOW_WIDTH) / 2)
                angleY -= 0.05f;
            if (x > glutGet(GLUT_WINDOW_WIDTH) / 2)
                angleY += 0.05f;

            cam->directionX = sin(angleY);
            cam->directionZ = -cos(angleY);
            printf("angleY y:%f\n", angleY);
            printf("angleX x:%f\n", angleX);

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
    glutPostRedisplay();

}


void motion(int x, int y) {
    glCoordinatesFromGlut(x, y);

    printf("output x:%f output y:%f output z:%f\n", ox, oy, oz);

    float x1 = (x) / glutGet(GLUT_WINDOW_WIDTH);
    float y1 = 1.0 - (y) / glutGet(GLUT_WINDOW_HEIGHT);

    if (modifierButton == GLUT_ACTIVE_ALT) {
        if (y >= 0) {
            cam->eyeY = y / 50;

        }
        printf("eyeZ:%f\n", cam->eyeZ);
    } else {
        if (leftButton == 0) {

            /*     cam->eyeX += ox /50;
                 cam->eyeY += oy / 50;*/

            /*       cam->eyeX += cam->directionX * fraction;
                   cam->eyeZ += cam->directionZ * fraction;
                   cam->eyeY += cam->directionY * fraction;*/

            printf("X:%f\n", cam->centerX);
            printf("Y:%f\n", cam->centerY);

        }
    }

//    centers[0] = ox;
//    centers[1] = oy;

    printf("Center :%f\n", centers[0]);
    printf("Center :%f\n", centers[1]);

    glutPostRedisplay();

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
    cam->centerX += ox;
    cam->centerY += oy;


    if (key == 'w') {
        cam->eyeY += 10;
    } else if (key == 'a') {
        cam->eyeX -= 10;
    } else if (key == 's') {
        cam->eyeY -= 10;
    } else if (key == 'd') {
        cam->eyeX += 10;
    }
    glutPostRedisplay();

}

