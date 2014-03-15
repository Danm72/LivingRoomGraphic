#import "MaterialTypes.h"

material brass = {
        {0.33, 0.22, 0.03, 1.0},
        {0.78, 0.57, 0.11, 1.0},
        {0.99, 0.91, 0.81, 1.0},
        27.8
};

material red_plastic =
        {
                {0.3, 0.0, 0.0, 1.0},
                {0.6, 0.0, 0.0, 1.0},
                {0.8, 0.6, 0.6, 1.0},
                32.0
        };

void materials(material *m) {
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m->ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m->diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m->specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m->shininess);
}