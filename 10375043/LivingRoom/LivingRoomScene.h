#ifndef LIVINGROOMSCENE_H_
#define LIVINGROOMSCENE_H_

#import "Placement.h"
#import "GLUT/glut.h"

void errorCallback(GLenum errorCode);

void createLightingEnv();

void drawHorizontalGrid();

void drawVerticalGrid();

void drawGrid();

#endif