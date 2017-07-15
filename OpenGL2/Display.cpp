#include "kengine.h"

void initializeWindow(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
}

void createWindow(int width, int height,string title) {
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 50);
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