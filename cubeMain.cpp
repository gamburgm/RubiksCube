#include <iostream>
#include "cube.h"

int main() {
	Cube c;

	c.rotateFaceCounterClockWise("white");
	c.rotateFaceClockWise("green");
	c.rotateFaceClockWise("red");
	c.rotateFaceClockWise("orange");
	c.rotateFaceCounterClockWise("yellow");
	c.rotateFaceCounterClockWise("yellow");
	c.rotateFaceClockWise("blue");
	c.rotateFaceClockWise("yellow");
	c.rotateFaceCounterClockWise("red");
	c.rotateFaceCounterClockWise("white");

	c.printFace("white");
	c.printFace("red");
	c.printFace("green");
	c.printFace("orange");
	c.printFace("blue");
	c.printFace("yellow");	

	return 0;
}
