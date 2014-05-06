
#ifndef INPUT_H
#import "ItemMover.h"
#import "Camera.h"
#import "Drawer.h"

void specialKey(int key, int x, int y);

void initInputHandler(camera *cam1);

void mouse(int btn, int state, int x, int y);

void motion(int x, int y);

void keyboard(unsigned char key, int x, int y);

void initItemMover(item_mover *item_move1);

#endif
