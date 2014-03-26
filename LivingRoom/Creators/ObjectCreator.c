#import "ObjectCreator.h"

void defineDrawStyle(GLUquadricObj *qobj, GLuint startList) {
    /* flat shaded */
    gluQuadricDrawStyle(qobj, GLU_FILL);
    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList, GL_COMPILE);
}

void createTableLayer(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    materials(&blue);

    glutSolidCube(0.1);
    glEndList();
}

void createWall(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    materials(&white);

    glutSolidCube(0.1);
    glEndList();
}

void createTableInnerBeam(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    materials(&brass);
    gluCylinder(obj, 0.05, 0.05, .5, 30, 10);
    glEndList();
}


void createTableLeg(GLUquadricObj *obj, GLuint list) {
    defineDrawStyle(obj, list);
    materials(&silver);
    glutSolidCube(0.1);
    glEndList();
}

void createLampBase(GLUquadricObj *qobj) {
    defineDrawStyle(qobj, startList + 2);
    materials(&brass);

    gluCylinder(qobj, 0.5, 0.5, 0.5, 30, 10);
    gluDisk(qobj, 0, .5, 30, 30);
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEndList();
}

void createLampPole(GLUquadricObj *qobj) {
    defineDrawStyle(qobj, startList + 1);
    materials(&brass);

    gluCylinder(qobj, 0.05, 0.05, 2, 15, 15);
    glEndList();
}

void createLampCone(GLUquadricObj *qobj) {
    materials(&red_plastic);

    materials(&red_plastic);

    defineDrawStyle(qobj, startList);
//    glColor3ub(1, 2, 3);
//    glBindTexture(GL_TEXTURE_2D, texture[1]);
    gluCylinder(qobj, 0.5, 0.25, 1, 30, 10);
    glEndList();

}

/*
GLuint loadBMP_custom(char path[]) {

    // Data read from the header of the BMP file
     char header[54]; // Each BMP file begins by a 54-bytes header
    int dataPos;     // Position in the file where the actual data begins
     int width, height;
     int imageSize;   // = width*height*3
// Actual RGB data
    unsigned char *data;

    // Open the file
    FILE *file = fopen(path, "rb");
    if (!file) {
        printf("Image could not be opened\n");
        return 0;
    }

    if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
        printf("Not a correct BMP file\n");
        return NULL;
    }

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Not a correct BMP file\n");
        return 0;
    }

    // Read ints from the byte array
    dataPos = *(int *) &(header[0x0A]);
    imageSize = *(int *) &(header[0x22]);
    width = *(int *) &(header[0x12]);
    height = *(int *) &(header[0x16]);

    // Some BMP files are misformatted, guess missing information
    if (imageSize == 0) imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
    if (dataPos == 0) dataPos = 54; // The BMP header is done that way

    // Create a buffer
    unsigned char lol [imageSize];
    data = lol;

// Read the actual data from the file into the buffer
    fread(data, 1, imageSize, file);

//Everything is in memory now, the file can be closed
    fclose(file);

    return data;
}*/
