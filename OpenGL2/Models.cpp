#include "kengine.h"

Model::Model() {
	size = 0;
	vaoID = -1;
}
Model::Model(int s, GLuint v) {
	size = s;
	vaoID = v;
}
void Model::draw(Vector3f position, Vector3f rotation, float angle) {
	glLoadIdentity();
	glTranslatef(position.x, position.y, position.z);
	if (angle != 0)
		glRotatef(angle, rotation.x, rotation.y, rotation.z);

	glBindVertexArray(vaoID);
	glDrawArrays(GL_TRIANGLES, 0, size);
	glBindVertexArray(0);
}