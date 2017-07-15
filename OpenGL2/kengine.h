#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<GL\glew.h>
#include<GL\freeglut.h>
#include<ctime>
#include "Maths.h"
#include"Models.h"
using namespace std;

void parseOBJ(string fileName);
int getVertexArraySize();
void loadData();
GLfloat* getVertexData();
GLfloat* getNormalData();
void cleanUp();

Model loadModel(string fileName);
void clearScreen();
void setClearColor(const Vector3f& color);
void swapFrameBuffers();

//***************WINDOW RELATED FUNCTIONS*************
void initializeGlut(int argc, char** argv);
void createWindow(int width, int height, string title);
void setCamera(float fov, float aspectRatio, float zNear, float zFar);
void displayWindow();

//**************LIGHT RELATED FUNCTIONS************
void loadLight(Vector3f position, Vector3f color);

void logFPS();