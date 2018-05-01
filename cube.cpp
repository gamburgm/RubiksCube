#include <iostream>
#include "cube.h"
#include "color.h"

Cube::Cube() {
	redFace = new CubeFace(red);
	blueFace = new CubeFace(blue); 
	yellowFace = new CubeFace(yellow); 
	whiteFace = new CubeFace(white);
	greenFace = new CubeFace(green); 
	orangeFace = new CubeFace(orange); 


	redFace->addNeighbors(yellowFace, whiteFace, greenFace, blueFace);
	blueFace->addNeighbors(yellowFace, whiteFace, orangeFace, redFace);
	greenFace->addNeighbors(yellowFace, whiteFace, redFace, orangeFace);
	orangeFace->addNeighbors(yellowFace, whiteFace, greenFace, blueFace);
	yellowFace->addNeighbors(orangeFace, redFace, blueFace, greenFace);
	whiteFace->addNeighbors(redFace, orangeFace, blueFace, greenFace);
}

Cube::~Cube() {
	delete redFace;
	delete blueFace;
	delete yellowFace;
	delete whiteFace;
	delete greenFace;
	delete orangeFace;
}	


int Cube::chooseColor(string faceName) {
	if (faceName.compare("red") == 0)
		return 0;	
	else if (faceName.compare("yellow") == 0)
		return 1;
	else if (faceName.compare("blue") == 0)
		return 2;
	else if (faceName.compare("orange") == 0)
		return 3;
	else if (faceName.compare("green") == 0)
		return 4;
	else if (faceName.compare("white") == 0)
		return 5;
	else
		return -1;
}

void Cube::printFace(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			redFace->printCubeFace();
			break;
		case 1:
			yellowFace->printCubeFace();
			break;
		case 2: 
			blueFace->printCubeFace();
			break;
		case 3:
			orangeFace->printCubeFace();
			break;
		case 4:
			greenFace->printCubeFace();
			break;
		case 5:
			whiteFace->printCubeFace();
			break;
		default:
			cout << "Error: invalid CubeFace" << endl;
			break;
	}
}

void Cube::rotateFaceClockWise(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			redFace->rotateClockWise();	
			break;
		case 1:
			yellowFace->rotateClockWise();
			break;
		case 2:
			blueFace->rotateClockWise();
			break;
		case 3:
			orangeFace->rotateClockWise();
			break;
		case 4:
			greenFace->rotateClockWise();
			break;
		case 5:
			whiteFace->rotateClockWise();
			break;
		default:
			cout << "Error: invalid CubeFace" << endl;
			break;
		
	}
}	



void Cube::rotateFaceCounterClockWise(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			redFace->rotateCounterClockWise();	
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
