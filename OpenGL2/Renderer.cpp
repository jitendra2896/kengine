#include "kengine.h"


void setClearColor(const Vector3f& color) {
	glClearColor(color.x, color.y,color.z, 0);
	glMatrixMode(GL_MODELVIEW);
}

void clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void swapFrameBuffers() {
	glutSwapBuffers();
}