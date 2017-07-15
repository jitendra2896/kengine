#include "kengine.h"

void initializeGlut(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
}

void createWindow(int width, int height,string title) {
	glutInitWindowSize(width, height);
	glutInitWindowPosition(150, 150);
	glutCreateWindow(title.c_str());
	glewInit();
	glEnable(GL_DEPTH_TEST);
}

void setCamera(float fov, float aspectRatio, float zNear, float zFar) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspectRatio, zNear, zFar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void displayWindow() {
	glutMainLoop();
}