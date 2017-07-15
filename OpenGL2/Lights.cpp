#include"OBJLoader.h"

void loadLight(Vector3f position, Vector3f color) {
	GLfloat pos[] = { position.x,position.y,position.z,0 };
	GLfloat col[] = { color.x,color.y,color.z,0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, col);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	GLfloat m[] = { 1,0,0,0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, m);
}