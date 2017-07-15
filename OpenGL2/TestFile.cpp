#include"kengine.h"

Model monkey;
Model cone;
Model glass;
Model torus;
float angle = 0.0;

void increment() {
	angle += 0.05;
	glutPostRedisplay();
}

void display() {
	clearScreen();

	monkey.draw(Vector3f(0, 0, -9), Vector3f(0, 1, 0), angle);
	cone.draw(Vector3f(-2, 0, -9), Vector3f(1, 0, 0), angle);
	glass.draw(Vector3f(2, 0, -9), Vector3f(0, 0, 1), angle);
	torus.draw(Vector3f(0, 0, -7), Vector3f(1, 0, 0), angle);



	increment();
	swapFrameBuffers();
	logFPS();
}

void init() {
	setClearColor(Vector3f(0, 0, 0));
	loadLight(Vector3f(0, 0, 1), Vector3f(1, 1, 1));
}

int main(int argc, char** argv) {
	initializeWindow(argc, argv);
	createWindow(500, 500, "My Window");
	setCamera(50, 1, 5, 10);
	init();
	monkey = loadModel("monkey.obj");
	cone = loadModel("cone.obj");
	glass = loadModel("glass.obj");
	torus = loadModel("torus.obj");
	glutDisplayFunc(display);
	displayWindow();
	return 0;
}
