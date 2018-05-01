#include <iostream>
#include "cube.h"

int main() {
	Cube c;
	c.printFace("blue");
	c.printFace("red");
	c.printFace("green");
	c.printFace("orange");
	c.printFace("white");

	c.rotateFaceCounterClockWise("white");
	c.printFace("white");
	c.printFace("orange");
	c.rotateFaceClockWise("orange");
	c.printFace("orange");

	return 0;
}
