#include <stdio.h>
#include <stdlib.h>
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

material white =
        {
                {1.0, 1.0, 1.0, 1.0},
                {1.0, 1.0, 1.0, 1.0},
                {1.0, 1.0, 1.0, 1.0},
                32.0
        };

material red =
        {
                {1.0, 0.0, 0.0, 1.0},
                {1.0, 0.0, 0.0, 1.0},
                {0.0, 0.0, 0.0, 1.0},
                32.0
        };
material green =
        {
                {0.0, 1.0, 0.0, 1.0},
                {0.0, 1.0, 0.0, 1.0},
                {0.0, 1.0, 0.0, 1.0},
                27.0
        };
material blue =
        {
                {0.0, 0.0, 1.0, 1.0},
                {0.0, 0.0, 1.0, 1.0},
                {0.0, 0.0, 1.0, 1.0},
                32.0
        };

material silver =
        {
                {0.19225, 0.19225, 0.19225}, {0.50754, 0.50754, 0.50754}, {0.508273, 0.508273, 0.508273}, 0.4 * 128
        };


material emerald =
        {
                {0.0215, 0.1745, 0.0215},
                {0.07568, 0.61424, 0.07568},
                {0.633, 0.727811, 0.633}, 0.6 * 128
        };


material jade = {
        {
                0.135, 0.2225, 0.1575, 0.54}, {0.89, 0.63, 0.316228, 0.316228}, 0.1 * 128
};
material obsidian = {{0.05375, 0.05, 0.06625}, {0.18275, 0.17, 0.22525}, {0.332741, 0.328634, 0.346435}, 0.3 * 128};
material pearl = {{0.25, 0.20725, 0.20725, 1}, {0.829, 0.829, 0.296648}, {0.296648, 0.296648, 0.088 * 128}};
material ruby = {{0.1745, 0.01175, 0.01175}, {0.61424, 0.04136, 0.04136}, {0.727811, 0.626959, 0.626959}, 0.6 * 128};
material turquoise = {{0.1, 0.18725, 0.1745}, {0.396, 0.74151, 0.69102}, {0.297254, 0.30829, 0.306678}, 0.1 * 128};

material chrome = {{0.25, 0.25, 0.25}, {0.4, 0.4, 0.4}, {0.774597, 0.774597, 0.774597}, 0.6 * 128};

material copper = {{0.19125, 0.0735, 0.0225}, {0.7038, 0.27048, 0.0828}, {0.256777, 0.137622, 0.086014}, 0.1 * 128};
material gold = {{0.24725, 0.1995, 0.0745}, {0.75164, 0.60648, 0.22648}, {0.628281, 0.555802, 0.366065}, 0.4 * 128};
material black_plastic = {{0.0, 0.0, 0.0}, {0.01, 0.01, 0.01}, {0.50, 0.50, 0.50}, .25 * 128};
material cyan_plastic = {{0.0, 0.1, 0.06}, {0.0, 0.50980392, 0.50980392}, {0.50196078, 0.50196078, 0.50196078}, .25 * 128};
material green_plastic = {{0.0, 0.0, 0.0}, {0.1, 0.35, 0.1}, {0.45, 0.55, 0.45}, .25 * 128};


void materials(material *m) {
//    glEnable(GL_COLOR_MATERIAL);
//
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, m->ambient);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, m->diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, m->specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, m->shininess);

//    glDisable(GL_COLOR_MATERIAL);

}

GLuint LoadTexture(const char *filename, int width, int
height) {

    GLuint texture;
    unsigned char *data;
    FILE *file;

    //The following code will read in our RAW file
    file = fopen(filename, "rb");
    if (file == NULL ) return 0;
    data = (unsigned char *) malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);
    fclose(file);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);


    free(data); //free the texture
    return texture; //return whether it was successfull
}


void freeTexture(GLuint texture) {
    glDeleteTextures(1, &texture);
}