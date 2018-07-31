#include <iostream>
#include "cube.h"
#include "color.h"
#include "extract.h"

class FileHandler;

//initialize the CubeFaces and assign each of them their respective neighbors
Cube::Cube() {
	generateCube();
	commands = new FileHandler();
	preLoaded = false;
}

Cube::Cube(string fileName) {
	generateCube();
	commands = new FileHandler(fileName);
	commands->readCommands(this);
	preLoaded = true;
}

//delete the memory of the cubefaces
Cube::~Cube() {
	delete bottomFace;
	delete frontFace;
	delete rightFace;
	delete backFace;
	delete leftFace; 
	delete topFace;
	delete commands;
}	


void Cube::generateCube() {
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

//return the corresponding number asociated with a face
int Cube::chooseFace(string faceName) {
	if (faceName.compare("D") == 0 || faceName.compare("d") == 0)
		return 0;	
	else if (faceName.compare("F") == 0 || faceName.compare("f") == 0)
		return 1;
	else if (faceName.compare("R") == 0 || faceName.compare("r") == 0)
		return 2;
	else if (faceName.compare("B") == 0 || faceName.compare("b") == 0)
		return 3;
	else if (faceName.compare("L") == 0 || faceName.compare("l") == 0)
		return 4;
	else if (faceName.compare("U") == 0 || faceName.compare("u") == 0)
		return 5;
	else
		return -1;
}

//print the CubeFace given the name of the face
void Cube::printFace(string faceName) {
	int num = chooseFace(faceName);

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

//execute a command given instructions: either a rotate, re-orient or print command
void Cube::readCommand(string input) {

	for (string::iterator iter = input.begin(); iter != input.end(); iter++) {
		string command = "";

		char letter = tolower(*iter);	

		if (letter == 'p') {
			printAllFaces();
		}

		if (letter == 'f' ||
			letter == 'u' ||
			letter == 'r' ||
			letter == 'l' ||
			letter == 'd' ||
			letter == 'b' ||
			letter == 'x' ||
			letter == 'y' ||
			letter == 'z') {
			
			command.push_back(letter);
		}

		if (*(iter + 1) == '\'') {
			command.push_back('\'');
		}

		if (!command.empty()) {
			handleCommand(command);
			commands->writeCommand(command);	
		}
	}
}

void Cube::handleCommand(string command) {
	bool clockwise = true;

	if (command.length() > 1 && command[1] == '\'') {
		clockwise = false;
	}

	if (chooseFace(command) == -1) {
		rotateCube(command, clockwise);
	}
	else {
		rotateFace(command, clockwise);
	}
}

void Cube::rotateCube(string command, bool clockwise) {
	if (command.compare("X") == 0 || command.compare("x") == 0) {
		if (clockwise) {
			rotateXClockWise();
		} else {
			rotateXCounterClockWise();
		}
	}
	else if (command.compare("Y") == 0 || command.compare("y") == 0) {
		if (clockwise) {
			rotateYClockWise();
		} else {
			rotateYCounterClockWise();
		}
	}
	else if (command.compare("Z") == 0 || command.compare("z") == 0) {
		if (clockwise) {
			rotateZClockWise();
		} else {
			rotateZCounterClockWise();
		}
	}
}

//rotate a face given the face's name and a direction
void Cube::rotateFace(string faceName, bool clockwise) {
	int num = chooseFace(faceName);

	switch (num) {
		case 0:
			bottomFace->rotate(ExtractBottom(), clockwise);
			break;
		case 1:
			frontFace->rotate(ExtractFront(), clockwise);
			break;
		case 2:
			rightFace->rotate(ExtractRight(), clockwise);
			break;
		case 3:
			backFace->rotate(ExtractBack(), clockwise);
			break;
		case 4:
			leftFace->rotate(ExtractLeft(), clockwise);
			break;
		case 5:
			topFace->rotate(ExtractTop(), clockwise);
			break;
		default:
			cout << "Invalid Face" << endl;
			break;
		
	}
}	

//check if the game has been won by checking if each face has been completed
bool Cube::wonGame() {
	if (bottomFace->completedFace() && 
		frontFace->completedFace()  &&
		rightFace->completedFace()  &&
		backFace->completedFace()   &&
		leftFace->completedFace()   &&
		topFace->completedFace()     ) {

		return true;
	}

	return false;
}

//interact with this cube and take user input as instructions to execute
void Cube::playGame() {
	string instructions;

	cout << "Welcome to Rubik's Cube!" << endl;
	if (!preLoaded) {
		randomizeCube();
	}
	printAllFaces();
	cout << endl;

	while (true) {
		printLegend();

		cin >> instructions;	
		
		readCommand(instructions);	
	
		if (wonGame()) {
			break;
		}
	}
	cout << "You won!" << endl;
}

//print possible user instructions for user to see
void Cube::printLegend() {
	cout << "* * * * * * * * * * * * * * * *" << endl;
	cout << "Commands:" << endl;
	cout << "F to rotate Front Face" << endl;
	cout << "U to rotate Upper Face" << endl;
	cout << "R to rotate Right Face" << endl;
	cout << "L to rotate Left Face" << endl;
	cout << "D to rotate Down Face" << endl;
	cout << "B to rotate Back Face" << endl;
	cout << "P to print all Faces" << endl;
	cout << "\nYour Command: ";	
	
}

//print all faces of this cube
void Cube::printAllFaces() {
	printFace("F");
	printFace("U");
	printFace("R");
	printFace("L");
	printFace("D");
	printFace("B");
}

//randomize the cube by using random rotations
void Cube::randomizeCube() {

	srand(time(NULL));

	for (int i = 0; i < 12; i++) {
		int rotations = rand() % 3 + 1;
		string cf;

		int whichFace = i % 6;

		switch (whichFace) {
			case 0:
				cf = "D";
				break;
			case 1:
				cf = "F";
				break;
			case 2:
				cf = "R";
				break;
			case 3:
				cf = "B";
				break;
			case 4:
				cf = "L";
				break;
			case 5:
				cf = "U";
				break;
			default:
				cf = "D";
				break;
		}

		for (int j = 0; j < rotations; j++) {
			readCommand(cf);
		}
	}

	commands->writeCommand("* * * * * * * * * *");
}

//change the orientation of the cube on the Y Axis clockwise
void Cube::rotateYClockWise() {
	CubeFace* temp = leftFace;

	leftFace = frontFace;
	frontFace = rightFace;
	rightFace = backFace;
	backFace = temp;

	topFace->orientClockWise();
	bottomFace->orientCounterClockWise();	
}

//change the orientation of the cube on the Y Axis counter-clockwise
void Cube::rotateYCounterClockWise() {
	CubeFace* temp = leftFace;
	
	leftFace = backFace;
	backFace = rightFace;
	rightFace = frontFace;
	frontFace = temp;

	topFace->orientCounterClockWise();
	bottomFace->orientClockWise();
}

void Cube::rotateXClockWise() {
	CubeFace* temp = frontFace;
	
	frontFace = bottomFace;
	bottomFace = backFace;
	backFace = topFace;
	topFace = temp;

	rightFace->orientClockWise();
	leftFace->orientCounterClockWise();
	backFace->totalReOrientation();
	bottomFace->totalReOrientation();
}

void Cube::rotateXCounterClockWise() {
	CubeFace* temp = frontFace;
	
	frontFace = topFace;
	topFace = backFace;
	backFace = bottomFace;
	bottomFace = temp;

	rightFace->orientCounterClockWise();
	leftFace->orientClockWise();
	backFace->totalReOrientation();
	topFace->totalReOrientation();
}

void Cube::rotateZClockWise() {
	CubeFace* temp = topFace;

	topFace = leftFace;
	leftFace = bottomFace;
	bottomFace = rightFace;
	rightFace = temp;

	frontFace->orientClockWise();
	topFace->orientClockWise();
	rightFace->orientClockWise();
	leftFace->orientClockWise();
	bottomFace->orientClockWise();
	backFace->orientCounterClockWise();	
}

void Cube::rotateZCounterClockWise() {
	CubeFace* temp = topFace;

	topFace = rightFace;
	rightFace = bottomFace;
	bottomFace = leftFace;
	leftFace = temp;

	frontFace->orientCounterClockWise();
	topFace->orientCounterClockWise();
	rightFace->orientCounterClockWise();
	leftFace->orientCounterClockWise();
	bottomFace->orientCounterClockWise();
	backFace->orientClockWise();	
}







