#include "kengine.h"
class vertex3 {
public:
	float x, y, z;
	vertex3(float xx, float yy, float zz) {
		x = xx;
		y = yy;
		z = zz;
	}
};

vector<vertex3> vertices;
vector<vertex3> normals;
vector<int> indicesVertex;
vector<int> indicesNormal;

void parseOBJ(string fileName) {
	ifstream is;
	is.open(fileName, ios::in);

	string header;
	float x, y, z;
	int xf, yf;
	while (!is.eof()) {
		is >> header;
		if (header == "v") {	//VERTEX DATA
			is >> x >> y >> z;
			vertex3 ob(x, y, z);
			vertices.push_back(ob);
		}
		else if (header == "vn") {	//VERTEX DATA
			is >> x >> y >> z;
			vertex3 ob(x, y, z);
			normals.push_back(ob);
		}
		else if (header == "f") {	//VERTEX DATA
			is >> xf;
			indicesVertex.push_back(xf);
			char c1;
			is >> c1;
			is >> c1;
			is >> yf;

			indicesNormal.push_back(yf);
			is >> xf;
			indicesVertex.push_back(xf);
			is >> c1;
			is >> c1;
			is >> yf;
			indicesNormal.push_back(yf);

			is >> xf;
			indicesVertex.push_back(xf);
			is >> c1;
			is >> c1;
			is >> yf;
			indicesNormal.push_back(yf);
		}
	}
	is.close();
}

int getVertexArraySize() {
	return indicesVertex.size()*3;
}

GLfloat verticesData[1000000];
GLfloat normalsData[1000000];
void loadData() {
	int j = 0;
	for (int i = 0; i < getVertexArraySize(); i+=3) {
		verticesData[i] = vertices[indicesVertex[j] - 1].x;
		verticesData[i+1] = vertices[indicesVertex[j] - 1].y;
		verticesData[i+2] = vertices[indicesVertex[j] - 1].z;

		normalsData[i] = normals[indicesNormal[j] - 1].x;
		normalsData[i+1] = normals[indicesNormal[j] - 1].y;
		normalsData[i+2] = normals[indicesNormal[j] - 1].z;
		j++;
	}

}

GLfloat* getVertexData() {
	return verticesData;
}

GLfloat* getNormalData() {
	return normalsData;
}

void cleanUp() {
	vertices.clear();
	normals.clear();
	indicesVertex.clear();
	indicesNormal.clear();
}