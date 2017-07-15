#pragma once
#include "kengine.h"

class Model {
	int size;
	GLuint vaoID;
public:
	Model();
	Model(int s, GLuint v);
	void draw(Vector3f position, Vector3f rotation, float angle);
};