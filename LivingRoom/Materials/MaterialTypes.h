#import "GLUT/glut.h"

typedef struct material {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess[1];
} material;

material brass;

material red_plastic;
material white;
material green;
material red;
material blue;
material silver;

material jade;
material obsidian;
material pearl;
material ruby;
material turquoise;
material chrome;
material emerald;
material copper;
material gold;
material black_plastic;
material cyan_plastic;
material green_plastic;

void materials(material *m);

GLuint LoadTexture(const char *filename, int width, int
height);
