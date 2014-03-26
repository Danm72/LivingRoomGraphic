#import "GLUT/glut.h"

typedef struct material {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    float shininess[4];
} material;

material brass;

material red_plastic;
material white;
material green;
material red;
material blue;
material silver;




void materials(material *m);