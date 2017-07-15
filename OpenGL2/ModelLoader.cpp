#include"kengine.h"


GLfloat* vertexData;
GLfloat* normalData;

GLuint vaoID;
GLuint vboID[2];
int vertexArraySize;
Model loadModel(string fileName) {

	parseOBJ(fileName);
	loadData();

	vertexArraySize = getVertexArraySize();

	vertexData = getVertexData();
	normalData = getNormalData();

	glGenVertexArrays(1, &vaoID);
	glBindVertexArray(vaoID);
	glGenBuffers(2, vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertexArraySize, vertexData, GL_STATIC_DRAW);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	glEnableClientState(GL_VERTEX_ARRAY);
	
	glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat)*vertexArraySize, normalData, GL_STATIC_DRAW);
	glNormalPointer(GL_FLOAT, 0, 0);
	glEnableClientState(GL_NORMAL_ARRAY);

	glBindVertexArray(0);
	cleanUp();
	return Model(vertexArraySize, vaoID);
}