#import "GLUT/glut.h"

typedef struct camera {
    GLdouble eyeX;
    GLdouble eyeY;
    GLdouble eyeZ;
    GLdouble centerX;
    GLdouble centerY;
    GLdouble centerZ;
    GLdouble upX;
    GLdouble upY;
    GLdouble upZ;
    GLfloat directionX;
    GLfloat directionY;
    GLfloat directionZ;
} camera;