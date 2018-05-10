#include <iostream>
#include "cube.h"
#include "color.h"
#include "extract.h"

//initialize the CubeFaces and assign each of them their respective neighbors
Cube::Cube() {
	bottomFace = new CubeFace(white);
	frontFace  = new CubeFace(red);
	rightFace  = new CubeFace(green);
	backFace   = new CubeFace(orange);
	leftFace   = new CubeFace(blue);
	topFace    = new CubeFace(yellow);

	bottomFace->addNeighbors(backFace, frontFace, rightFace, leftFace);
	frontFace->addNeighbors(bottomFace, topFace, rightFace, leftFace);
	rightFace->addNeighbors(bottomFace, topFace, backFace, frontFace);
	backFace->addNeighbors(bottomFace, topFace, leftFace, rightFace); //might have problem here, with orientation: changing faces
	leftFace->addNeighbors(bottomFace, topFace, frontFace, backFace);
	topFace->addNeighbors(frontFace, backFace, rightFace, leftFace);
}

//delete the memory of the cubefaces
Cube::~Cube() {
	delete bottomFace;
	delete frontFace;
	delete rightFace;
	delete backFace;
	delete leftFace; 
	delete topFace;
}	

//given a string, return the respective number of the Color enumeration
int Cube::chooseColor(string faceName) {
	if (faceName.compare("bottom") == 0 || faceName.compare("D") == 0)
		return 0;	
	else if (faceName.compare("front") == 0 || faceName.compare("F") == 0)
		return 1;
	else if (faceName.compare("right") == 0 || faceName.compare("R") == 0)
		return 2;
	else if (faceName.compare("back") == 0 || faceName.compare("B") == 0)
		return 3;
	else if (faceName.compare("left") == 0 || faceName.compare("L") == 0)
		return 4;
	else if (faceName.compare("top") == 0 || faceName.compare("U") == 0)
		return 5;
	else
		return -1;
}

//print the CubeFace given the name of the face
void Cube::printFace(string faceName) {
	int num = chooseColor(faceName);

	switch (num) {
		case 0:
			bottomFace->printCubeFace();
			break;
		case 1:
			frontFace->printCubeFace();
			break;
		case 2: 
			rightFace->printCubeFace();
			break;
		case 3:
			backFace->printCubeFace();
			break;
		case 4:
			leftFace->printCubeFace();
			break;
		case 5:
			topFace->printCubeFace();
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
			bottomFace->rotateClockWise(ExtractBottom());	
			break;
		case 1:
			frontFace->rotateClockWise(ExtractFront());
			break;
		case 2:
			rightFace->rotateClockWise(ExtractRight());
			break;
		case 3:
			backFace->rotateClockWise(ExtractBack());
			break;
		case 4:
			leftFace->rotateClockWise(ExtractLeft());
			break;
		case 5:
			topFace->rotateClockWise(ExtractTop());
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
			bottomFace->rotateCounterClockWise(ExtractBottom());	
			break;
		case 1:
			frontFace->rotateCounterClockWise(ExtractFront());
			break;
		case 2:
			rightFace->rotateCounterClockWise(ExtractRight());
			break;
		case 3:
			backFace->rotateCounterClockWise(ExtractBack());
			break;
		case 4:
			leftFace->rotateCounterClockWise(ExtractLeft());
			break;
		case 5:
			topFace->rotateCounterClockWise(ExtractTop());
			break;
		default:
			cout << "Error: invalid CubeFace" << endl;
			break;
		
	}
}	
