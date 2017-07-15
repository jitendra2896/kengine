#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<GL\glew.h>
#include<GL\freeglut.h>
#include<ctime>
#include "Maths.h"

using namespace std;

class Model {
	int size;
	GLuint vaoID;
public:
	Model() {
		size = 0;
		vaoID = -1;
	}
	Model(int s, GLuint v) {
		size = s;
		vaoID = v;
	}
	void draw(Vector3f position, Vector3f rotation, float angle) {
		glLoadIdentity();
		glTranslatef(position.x, position.y, position.z);
		if (angle != 0)
			glRotatef(angle, rotation.x, rotation.y, rotation.z);

		glBindVertexArray(vaoID);
		glDrawArrays(GL_TRIANGLES, 0, size);
		glBindVertexArray(0);
	}
};


void parseOBJ(string fileName);
int getVertexArraySize();
void loadData();
GLfloat* getVertexData();
GLfloat* getNormalData();
void cleanUp();

Model loadModel(string fileName);
void render(Vector3f position, Vector3f rotation, float angle, const Model& model);
void clearScreen();
void setClearColor(const Vector3f& color);
void swapFrameBuffers();

//***************WINDOW RELATED FUNCTIONS*************
void initializeWindow(int argc, char** argv);
void createWindow(int width, int height, string title);
void setCamera(float fov, float aspectRatio, float zNear, float zFar);
void displayWindow();

//**************LIGHT RELATED FUNCTIONS************
void loadLight(Vector3f position, Vector3f color);

void logFPS();