#include <iostream>
#include "extract.h"
#include "cube.h"


int main() {
	Cube c;

	c.rotateFaceCounterClockWise("R");
	c.rotateFaceCounterClockWise("D");
	c.printFace("R");
	c.printFace("F");

	c.rotateFaceCounterClockWise("L");
	c.printFace("F");

	return 0;
}
