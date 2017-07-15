#include "OBJLoader.h"
double FPS = 0.0;
time_t startTime;
time_t endTime;
bool FIRST = true;

void logEndTime() {
	endTime = time(NULL);
}

void setUp() {
	if (FIRST) {
		startTime = time(NULL);
		FIRST = false;
	}
}

void logFPS() {
	setUp();
	logEndTime();
	double seconds = difftime(endTime, startTime);
	if (seconds < 1) {
		FPS++;
	}
	else {
		cout << "FPS: " << FPS << endl;
		FPS = 0;
		FIRST = true;
	}
}