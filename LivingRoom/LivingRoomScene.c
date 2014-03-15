//
//  main.c
//  LivingRoom
//
//  Created by Dan Malone on 10/03/2014.
//
//

#import "LivingRoomScene.h"

static GLfloat theta [] = {0.0, 0.0, 0.0};
static GLint axis = 2;
GLUquadricObj *quadObj;
float angle = 0.0;
GLdouble eyeX = 0;
//* cos(angle);
GLdouble eyeY = 0;
//* sin(angle);
GLdouble eyeZ = 0.0;
GLdouble centerX = 0;
GLdouble centerY = 0;
GLdouble centerZ = -1;
GLdouble upX = 0;
GLdouble upY = 1;
GLdouble upZ = -1.5;

treenode lamp_cone_node;
treenode lamp_pole_node;
treenode lamp_base_node;

treenode table_layer1_node;
treenode table_layer2_node;
treenode table_leg1_node;
treenode table_leg2_node;
treenode table_leg3_node;
treenode table_leg4_node;

treenode wall_node;

void setupLampNodes();

void setupTableNodes();

void errorCallback(GLenum errorCode) {
    const GLubyte *estring;

    estring = gluErrorString(errorCode);
    fprintf(stderr, "Quadric Error: %s\n", estring);
    exit(0);
}

void mouse(int btn, int state, int x, int y) {
    if (btn == GLUT_LEFT_BUTTON&& state == GLUT_DOWN)
        axis = 0;
    if (btn == GLUT_MIDDLE_BUTTON&& state == GLUT_DOWN)
        axis = 1;
    if (btn == GLUT_RIGHT_BUTTON&& state == GLUT_DOWN)
        axis = 2;
}

//void (^translateBlock)(GLfloat []) = ^(GLfloat translateCoOrds []) {
//
//    glTranslatef(translateCoOrds[0], translateCoOrds[1],translateCoOrds[2]);
//};

void init(void) {
    createLightingEnv();
    glLoadIdentity();
    glGetFloatv(GL_MODELVIEW, lamp_cone_node.m);

    setupLampNodes();

    setupTableNodes();

    startList = glGenLists(14);

    quadObj = gluNewQuadric();
    gluQuadricCallback(quadObj, GLU_ERROR, (GLvoid ( *)()) errorCallback);

    createFlatSurface(quadObj, startList + 9);
    createFlatSurface(quadObj, startList + 10);
    createFlatSurface(quadObj, startList + 11);
    createFlatSurface(quadObj, startList + 12);
}

void setupTableNodes() {
    table_layer1_node.drawingFunction = drawTableLayer1;
    table_layer1_node.sibling = NULL;
    table_layer1_node.child = &table_layer2_node;

    table_layer2_node.drawingFunction = drawTableLayer2;
    table_layer2_node.sibling = NULL;
    table_layer2_node.child = &table_leg1_node;

    table_leg1_node.drawingFunction = drawTableLeg1;
    table_leg1_node.sibling = &table_leg2_node;
    table_leg1_node.child = NULL;

    table_leg2_node.drawingFunction = drawTableLeg2;
    table_leg2_node.sibling = &table_leg3_node;
    table_leg2_node.child = NULL;

    table_leg3_node.drawingFunction = drawTableLeg3;
    table_leg3_node.sibling = &table_leg4_node;
    table_leg3_node.child = NULL;

    table_leg4_node.drawingFunction = drawTableLeg4;
    table_leg4_node.sibling = NULL;
    table_leg4_node.child = NULL;
}

void setupLampNodes() {
    lamp_cone_node.drawingFunction = drawCone;
    lamp_cone_node.sibling = NULL;
    lamp_cone_node.child = &lamp_pole_node;

    lamp_pole_node.drawingFunction = drawPole;
    lamp_pole_node.sibling = NULL;
    lamp_pole_node.child = &lamp_base_node;

    lamp_base_node.drawingFunction = drawBase;
    lamp_base_node.sibling = NULL;
    lamp_base_node.child = NULL;
}

void createLightingEnv() {
    GLfloat mat_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
    GLfloat model_ambient[] = {0.5, 0.5, 0.5, 1.0};

   // GLfloat lightpos [] = {0.0, 0.0, 0.0, 0.0};
    GLfloat dx = 1.0;
    GLfloat dy = 1.0;
    GLfloat dz = 1.0;
    GLfloat theta = 0.0;

     //glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);
}


void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //angle += 360. / 10.;
    // set camera parameters
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ,
            centerX, centerY, centerZ,
            upX, upY, upZ);

    glRotatef(theta[0], 1.0, 0.0, 0.0);
    glRotatef(theta[1], 0.0, 1.0, 0.0);
    glRotatef(theta[2], 0.0, 0.0, 1.0);


    traverse(&lamp_cone_node);
    //glRotatef(90, 0, 0, 0);

    traverse(&table_layer1_node);

    // placeLamp();

       //Teapot?
       placeTeapot();

       //Table
     //  placeTable();

       GLfloat location[] = {0.0, 0.0, -5.0};
       GLfloat rotate[] = {0.0, 0.0, 0.0, 0.0};
       placeWall(startList + 9, location, rotate);

       GLfloat location1[] = {0.0, 5.0, 0.0};
       GLfloat rotate1[] = {90.0, 0.0, 0.0, 0.0};
       placeWall(startList + 10, location1, rotate1);
    glutSwapBuffers();

    glFlush();

    return;
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-5, 5, -5 * (GLfloat) h / (GLfloat) w,
                5 * (GLfloat) h / (GLfloat) w, -100.0, 100.0);
    else
        glOrtho(-2.5 * (GLfloat) w / (GLfloat) h,
                2.5 * (GLfloat) w / (GLfloat) h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

void specialKey(int key, int x, int y) {
    switch (key) {
        default:

        case GLUT_KEY_UP:
            printf("%fX", eyeZ);
            printf("\n");

            upY += 1.0;
            break;
        case GLUT_KEY_DOWN:
            printf("%fX", eyeZ);
            printf("\n");

            upY -= 1.0;
            break;
        case GLUT_KEY_LEFT:
            printf("%fY", eyeY);
            printf("\n");

            //  eyeY -= 1.0;
            theta[axis] -= 5.0;

            break;
        case GLUT_KEY_RIGHT:
            printf("%fY", eyeY);
            printf("\n");

            //eyeY += 1.0;
            theta[axis] += 5.0;

            break;

    }
    glutPostRedisplay();
}


void spin() {
    angle += 3.0;
    glutPostRedisplay();
}

int main(int argc, const char *argv[]) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    // glutIdleFunc(spin);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}



