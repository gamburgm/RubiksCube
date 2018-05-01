#include <iostream>
#include "cube.h"
#include "color.h"

//initialize the CubeFaces and assign each of them their respective neighbors
Cube::Cube() {
	whiteFace  = new CubeFace(white);
	redFace    = new CubeFace(red);
	greenFace  = new CubeFace(green);
	orangeFace = new CubeFace(orange);
	blueFace   = new CubeFace(blue);
	yellowFace = new CubeFace(yellow);

	whiteFace->addNeighbors(orangeFace, redFace, greenFace, blueFace);
	redFace->addNeighbors(whiteFace, yellowFace, greenFace, blueFace);
	greenFace->addNeighbors(whiteFace, yellowFace, orangeFace, redFace);
	orangeFace->addNeighbors(whiteFace, yellowFace, blueFace, greenFace);
	blueFace->addNeighbors(whiteFace, yellowFace, redFace, orangeFace);
	yellowFace->addNeighbors(redFace, orangeFace, greenFace, blueFace);	
}

//delete the memory of the cubefaces
Cube::~Cube() {
	delete whiteFace;
	delete redFace;
	delete greenFace;
	delete orangeFace;
	delete blueFace;
	delete yellowFace;
}	


//given a string, return the respective number of the Color enumeration
int Cube::chooseColor(string faceName) {
	if (faceName.compare("white") == 0)
		return 0;	
	else if (faceName.compare("red") == 0)
		return 1;
	else if (faceName.compare("green") == 0)
		return 2;
	else if (faceName.compare("orange") == 0)
		return 3;
	else if (faceName.compare("blue") == 0)
		return 4;
	else if (faceName.compare("yellow") == 0)
		return 5;
	else
		return -1;
}

//print the CubeFace given the name of the face
void Cube::printFace(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			whiteFace->printCubeFace();
			break;
		case 1:
			redFace->printCubeFace();
			break;
		case 2: 
			greenFace->printCubeFace();
			break;
		case 3:
			orangeFace->printCubeFace();
			break;
		case 4:
			blueFace->printCubeFace();
			break;
		case 5:
			yellowFace->printCubeFace();
			break;
		default:
			cout << "Error: invalid CubeFace" << endl;
			break;
	}
}

//rotate a CubeFace clockwise, given the name of the CubeFace 
void Cube::rotateFaceClockWise(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			whiteFace->rotateClockWise();	
			break;
		case 1:
			redFace->rotateClockWise();
			break;
		case 2:
			greenFace->rotateClockWise();
			break;
		case 3:
			orangeFace->rotateClockWise();
			break;
		case 4:
			blueFace->rotateClockWise();
			break;
		case 5:
			yellowFace->rotateClockWise();
			break;
		default:
			cout << "Error: invalid CubeFace" << endl;
			break;
		
	}
}	


//rotate a CubeFace counterclockwise, given the name of the CubeFace
void Cube::rotateFaceCounterClockWise(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			whiteFace->rotateCounterClockWise();	
			break;
		case 1:
			yellowFace->rotateCounterClockWise();
			break;
		case 2:
			blueFace->rotateCounterClockWise();
			break;
		case 3:
			orangeFace->rotateCounterClockWise();
			break;
		case 4:
			greenFace->rotateCounterClockWise();
			break;
		case 5:
			whiteFace->rotateCounterClockWise();
			break;
		default:
			cout << "Error: invalid CubeFace" << endl;
			break;
		
	}
}	
