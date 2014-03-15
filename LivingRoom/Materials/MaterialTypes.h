#import "GLUT/glut.h"

typedef struct material {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess[4];
} material;

material brass;

material red_plastic;

void materials(material *m);