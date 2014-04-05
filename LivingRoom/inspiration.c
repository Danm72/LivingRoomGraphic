/*
//
//  main.c
//  LivingRoom
//
//  Created by Dan Malone on 10/03/2014.
//
//

#include <stdio.h>
#include <GLUT/GLUT.h>
#import <stdlib.h>

*/
/*void display(void) {

    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    gluQuadricDrawStyle(qobj, GLU_FILL); *//*
*/
/* smooth shaded *//*
*/
/*
    gluQuadricNormals(qobj, GLU_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, -0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
    gluCylinder(qobj, 0.5, 0.3, 1.0, 15, 5);

    glEnd();

    glFlush();

    return;;
}*//*



GLuint startList;

void errorCallback(GLenum errorCode)
{
    const GLubyte *estring;

    estring = gluErrorString(errorCode);
    fprintf(stderr, "Quadric Error: %s\n", estring);
    exit(0);
}

void init(void)
{
    GLUquadricObj *qobj;
    GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

*/
/* Create 4 display lists, each with a different quadric object.
 * Different drawing styles and surface normal specifications
 * are demonstrated.
 *//*

    startList = glGenLists(4);
    qobj = gluNewQuadric();
    gluQuadricCallback(qobj, GLU_ERROR, errorCallback);

    gluQuadricDrawStyle(qobj, GLU_FILL); */
/* smooth shaded *//*

    gluQuadricNormals(qobj, GLU_SMOOTH);
    glNewList(startList, GL_COMPILE);
    gluSphere(qobj, 0.75, 15, 10);
    //glEndList();;

    gluQuadricDrawStyle(qobj, GLU_FILL); */
/* flat shaded *//*

    gluQuadricNormals(qobj, GLU_FLAT);
    glNewList(startList+1, GL_COMPILE);
    gluCylinder(qobj, 0.5, 0.3, 1.0, 15, 5);
    //glEndList();;

    gluQuadricDrawStyle(qobj, GLU_LINE); */
/* wireframe *//*

    gluQuadricNormals(qobj, GLU_NONE);
    glNewList(startList+2, GL_COMPILE);
    gluDisk(qobj, 0.25, 1.0, 20, 4);
    //glEndList();;

    gluQuadricDrawStyle(qobj, GLU_SILHOUETTE);
    gluQuadricNormals(qobj, GLU_NONE);
    glNewList(startList+3, GL_COMPILE);
    gluPartialDisk(qobj, 0.0, 1.0, 20, 4, 0.0, 225.0);
    //glEndList();;
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glEnable(GL_LIGHTING);
    glShadeModel (GL_SMOOTH);
    glTranslatef(-1.0, -1.0, 0.0);
    glCallList(startList);

    glShadeModel (GL_FLAT);
    glTranslatef(0.0, 2.0, 0.0);
    glPushMatrix();
    glRotatef(300.0, 1.0, 0.0, 0.0);
    glCallList(startList+1);
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glColor3f(0.0, 1.0, 1.0);
    glTranslatef(2.0, -2.0, 0.0);
    glCallList(startList+2);

    glColor3f(1.0, 1.0, 0.0);
    glTranslatef(0.0, 2.0, 0.0);
    glCallList(startList+3);

    glPopMatrix();
    glFlush();
}

void reshape (int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-2.5, 2.5, -2.5*(GLfloat)h/(GLfloat)w,
                2.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-2.5*(GLfloat)w/(GLfloat)h,
                2.5*(GLfloat)w/(GLfloat)h, -2.5, 2.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}



int main(int argc, const char *argv[]) {

    */
/* // insert code here...
     glutInit(&argc, argv);
     glutCreateWindow("simple");
     glutDisplayFunc(display);

     glutMainLoop();
     printf("Hello, World!\n");
     return 0;*//*


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}



*/


/*
 * GluCylinders.c   - Version 1.0.
 *
 * Author: Samuel R. Buss
 *
 * Bug reports: Sam Buss, sbuss@ucsd.edu.
 *
 * PURPOSE: Provide routines for drawing cylinders with gluQuadricObjects
 *     Since GLUT does not support cylinders, this adds useful support
 *		for these common shapes.
 *
 * USAGE:
 *    Press arrow keys to control view position.
 *			left and right keys rotate the viewpoint left and right
 *	  Up and down keys rotate viewpoint up and down (up to 80 degrees).
 *
 *    Press "R" key to make step size bigger (if moving too slowly)
 *    Press "r" key to make step size smaller (if moving too fast).
 *
 *    Press the "w" key to toggle wireframe mode (looks terrible in "fill" mode)
 *
 *	  Press ESCAPE to exit.
 *
 */
/*

#include <stdio.h>
#import <stdlib.h>
#include <GLUT/glut.h>	// OpenGL Graphics Utility Library

// The next global variable controls the animation's state and speed.
float RotateAngle = 0.0f;        // Angle in degrees of rotation around y-axis
float Azimuth = 20.0;            // Rotated up or down by this amount

float AngleStepSize = 3.0f;        // Step three degrees at a time
const float AngleStepMax = 10.0f;
const float AngleStepMin = 0.1f;

int WireFrameOn = 1;            // == 1 for wire frame mode

void drawGluCylinder(double, double, int, int);
void drawGluSlantCylinderWithCaps(double, double, double, int, int);
void drawGluSlantCylinder(double, double, double, int, int);


// glutKeyboardFunc is called below to set this function to handle
//		all "normal" key presses.
void myKeyboardFunc(unsigned char key, int x, int y) {
    switch (key) {
        case 'w':
            WireFrameOn = 1 - WireFrameOn;
            if (WireFrameOn) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);        // Just show wireframes
            }
            else {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);        // Show solid polygons
            }
            glutPostRedisplay();
            break;
        case 'R':
            AngleStepSize *= 1.5;
            if (AngleStepSize > AngleStepMax) {
                AngleStepSize = AngleStepMax;
            }
            break;
        case 'r':
            AngleStepSize /= 1.5;
            if (AngleStepSize < AngleStepMin) {
                AngleStepSize = AngleStepMin;
            }
            break;
        case 27:    // Escape key
            exit(1);
    }
}

// glutSpecialFunc is called below to set this function to handle
//		all "special" key presses.  See glut.h for the names of
//		special keys.
void mySpecialKeyFunc(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            Azimuth += AngleStepSize;
            if (Azimuth > 80.0f) {
                Azimuth = 80.0f;
            }
            break;
        case GLUT_KEY_DOWN:
            Azimuth -= AngleStepSize;
            if (Azimuth < -80.0f) {
                Azimuth = -80.0f;
            }
            break;
        case GLUT_KEY_LEFT:
            RotateAngle += AngleStepSize;
            if (RotateAngle > 180.0f) {
                RotateAngle -= 360.0f;
            }
            break;
        case GLUT_KEY_RIGHT:
            RotateAngle -= AngleStepSize;
            if (RotateAngle < -180.0f) {
                RotateAngle += 360.0f;
            }
            break;
    }
    glutPostRedisplay();

}

*/
/*
 * drawScene() handles the animation and the redrawing of the
 *		graphics window contents.
 *//*

void drawScene(void) {
    // Clear the rendering window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // Rotate the image
    glMatrixMode(GL_MODELVIEW);                // Current matrix affects objects positions
    glLoadIdentity();                            // Initialize to the identity
    glTranslatef(-0.5, 0.0, -35.0);                // Translate  from origin (in front of viewer)
    glRotatef(RotateAngle, 0.0, 1.0, 0.0);        // Rotate around y-axis
    glRotatef(Azimuth, 1.0, 0.0, 0.0);            // Set Azimuth angle

    glDisable(GL_CULL_FACE);
    glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(1.0, 0.2, 0.2);                    // Reddish color
    // Parameters: height, radius, slices, stacks
    drawGluCylinder(2.0, 0.75, 8, 10);
    glPopMatrix();

    glEnable(GL_CULL_FACE);
    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glColor3f(0.2, 1.0, 0.2);                    // Greenish color
    // Parameters: height, base radius, top radius, slices, stacks
    drawGluSlantCylinderWithCaps(2.0, 1.0, 0.4, 8, 8);
    glPopMatrix();

    // Flush the pipeline, swap the buffers
    glFlush();
    glutSwapBuffers();
}


// Initialize OpenGL's rendering modes
void initRendering() {
    glEnable(GL_DEPTH_TEST);    // Depth testing must be turned on

    glCullFace(GL_BACK);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);        // Just show wireframes at first
}

// Called when the window is resized
//		w, h - width and height of the window in pixels.
void resizeWindow(int w, int h) {
    double aspectRatio;

    // Define the portion of the window used for OpenGL rendering.
    glViewport(0, 0, w, h);    // View port uses whole window

    // Set up the projection view matrix: perspective projection
    // Determine the min and max values for x and y that should appear in the window.
    // The complication is that the aspect ratio of the window may not match the
    //		aspect ratio of the scene we want to view.
    w = (w == 0) ? 1 : w;
    h = (h == 0) ? 1 : h;
    aspectRatio = (double) w / (double) h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(15.0, aspectRatio, 25.0, 45.0);

}


// Main routine
// Set up OpenGL, define the callbacks and start the main loop
int main(int argc, char **argv) {
    glutInit(&argc, argv);

    // We're going to animate it, so double buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    // Window position (from top corner), and size (width% and hieght)
    glutInitWindowPosition(10, 60);
    glutInitWindowSize(360, 360);
    glutCreateWindow("GluCylinders");

    // Initialize OpenGL as we like it..
    initRendering();

    // Set up callback functions for key presses
    glutKeyboardFunc(myKeyboardFunc);            // Handles "normal" ascii symbols
    glutSpecialFunc(mySpecialKeyFunc);        // Handles "special" keyboard keys

    // Set up the callback function for resizing windows
    glutReshapeFunc(resizeWindow);

    // Call this for background processing
    // glutIdleFunc( myIdleFunction );

    // call this whenever window needs redrawing
    glutDisplayFunc(drawScene);

    fprintf(stdout, "Arrow keys control viewpoint.\n");
    fprintf(stdout, "Press \"w\" to toggle wireframe mode.\n");
    fprintf(stdout, "Press \"R\" or \"r\" to increase or decrease rate of movement (respectively).\n");

    // Start the main loop.  glutMainLoop never returns.
    glutMainLoop();

    return (0);    // This line is never reached.
}

// ************************************************************************
// These are four general purpose routines for generating
//	cylinders, with or without caps.
// See the OpenGL redbook or other glu documentation for more information.
// These generate normals, but not texture coordinates.
// To generate texture coordinates, you need to modify the code to
//   call gluQuadricTexture();
// For higher performance, you should consider putting your cylinders into
//	 a display list.
// Please note these routines do not do all possible error checking, and
//	 thus should not be used in a production or other critical environment.
// ************************************************************************

//  A Reusable gluQuadric object:
GLUquadricObj *myReusableQuadric = 0;

void drawGluCylinder(double height, double radius, int slices, int stacks) {
    drawGluSlantCylinder(height, radius, radius, slices, stacks);
}

void drawGluSlantCylinder(double height, double radiusBase, double radiusTop, int slices, int stacks) {
    if (!myReusableQuadric) {
        myReusableQuadric = gluNewQuadric();
        // Should (but don't) check if pointer is still null --- to catch memory allocation errors.
        gluQuadricNormals(myReusableQuadric, GL_TRUE);
    }
    // Draw the cylinder.
    gluCylinder(myReusableQuadric, radiusBase, radiusTop, height, slices, stacks);
}


void drawGluCylinderWithCaps(double height, double radius, int slices, int stacks) {
    drawGluSlantCylinderWithCaps(height, radius, radius, slices, stacks);
}

void drawGluSlantCylinderWithCaps(double height, double radiusBase, double radiusTop, int slices, int stacks) {
    // First draw the cylinder
    drawGluSlantCylinder(height, radiusBase, radiusTop, slices, stacks);

    // Draw the top disk cap
    glPushMatrix();
    glTranslated(0.0, 0.0, height);
    gluDisk(myReusableQuadric, 0.0, radiusTop, slices, stacks);
    glPopMatrix();

    // Draw the bottom disk cap
    glPushMatrix();
    glRotated(180.0, 1.0, 0.0, 0.0);
    gluDisk(myReusableQuadric, 0.0, radiusBase, slices, stacks);
    glPopMatrix();

}
*/
