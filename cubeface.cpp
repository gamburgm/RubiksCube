#include "cubeface.h"
#include "color.h"
#include <string>
using namespace std;

//give a cubeface its defining color
CubeFace::CubeFace(Color clr) {
	faceColor = clr;

	for (int i = 0; i < 3; i++) {
		vector<Color> row;
		for (int j = 0; j < 3; j++) {
			row.push_back(clr);
		}
		face.push_back(row);
	}	
}

//check if all colors in the face of the CubeFace is of the respective color
bool CubeFace::completedFace() {
	for ( vector<Color> col : face ) {
		for ( Color clr : col ) {
			if (clr == faceColor) {
				return false;
			}
		}
	}
	
	return true;
}

//assign the surrounding CubeFace references
void CubeFace::addNeighbors(CubeFace* btm, CubeFace* top, CubeFace* right, CubeFace* left) {
	bottomFace = btm;
	topFace = top;
	rightFace = right;
	leftFace = left;
}	

//get the defining color of this cubeface
Color CubeFace::getFaceColor() {
	return faceColor;
}

//get a specific color at the given coordinate of this face
Color CubeFace::getFace(int row, int col) {
	return face[row][col];
}

//set the defining color of this cubeface
void CubeFace::setColor(Color clr) {
	faceColor = clr;
}

//set the color at the given coordinate in the face to the given color
void CubeFace::setFace(int row, int col, Color clr) {
	face[row][col] = clr;
}	

//print the cubeface and with the colors in each part of the face
void CubeFace::printCubeFace() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "[";
		
			Color clr = face[i][j];
			switch (clr) {
				case 0:
					cout << "W";
					break;
				case 1:
					cout << "R";
					break;
				case 2:
					cout << "G";
					break;
				case 3:
					cout << "O";
					break;
				case 4:
					cout << "B";
					break;
				case 5:
					cout << "Y";
					break;
				default:
					cout << "?";
					break;
			}
			cout << "]";
		}
		cout << endl;
	}
}

//re-orient the face clockwise
void CubeFace::turnClockWise() {
	vector< vector<Color> > turnedFace;

	for (int i = 0; i < 3; i++) {
		vector<Color> row;
		for (int j = 0; j < 3; j++) {
			row.push_back(face[3 - j - 1].at(i));
		}
		turnedFace.push_back(row);
	}
	
	face = turnedFace;
}				

//re-orient the face counterclockwise
void CubeFace::turnCounterClockWise() {
	vector< vector<Color> > turnedFace;

	for (int i = 0; i < 3; i++) {
		vector<Color> row;
		for (int j = 0; j < 3; j++) {
			row.push_back(face[j].at(3 - i - 1));
		}
		turnedFace.push_back(row);
	}
	
	face = turnedFace;
}	

//swap the colors at the given coordinates of this CubeFace's neighbors clockwise
void CubeFace::moveCubiesClockWise(int btmRow, int btmCol, int topRow, int topCol, int rightRow, int rightCol, int leftRow, int leftCol) {
	Color temp = topFace->getFace(topRow, topCol);

	topFace->setFace(topRow, topCol, rightFace->getFace(rightRow, rightCol));
	rightFace->setFace(rightRow, rightCol, bottomFace->getFace(btmRow, btmCol));
	bottomFace->setFace(btmRow, btmCol, leftFace->getFace(leftRow, leftCol));
	leftFace->setFace(leftRow, leftCol, temp);	
}

//swap the colors at the given coordinates of this CubeFace's neighbors counterclockwise
void CubeFace::moveCubiesCounterClockWise(int btmRow, int btmCol, int topRow, int topCol, int rightRow, int rightCol, int leftRow, int leftCol) {
	Color temp = topFace->getFace(topRow, topCol);

	topFace->setFace(topRow, topCol, leftFace->getFace(leftRow, leftCol));
	leftFace->setFace(leftRow, leftCol, bottomFace->getFace(btmRow, btmCol));
	bottomFace->setFace(btmRow, btmCol, rightFace->getFace(rightRow, rightCol));
	rightFace->setFace(rightRow, rightCol, temp);
}

//rotate this CubeFace clockwise by re-orienting its face clockwise and swapping the neighbor colors
void CubeFace::rotateClockWise() {
	turnClockWise();
	moveCubiesClockWise(0, 2, 2, 0, 0, 0, 2, 2);
	moveCubiesClockWise(0, 1, 2, 1, 1, 0, 1, 2);
	moveCubiesClockWise(0, 0, 2, 2, 2, 0, 0, 2);
}

//rotate this CubeFace counterclockwise by re-orienting its face counterclockwise and swapping the neighbor colors
void CubeFace::rotateCounterClockWise() {
	turnCounterClockWise();
	moveCubiesCounterClockWise(0, 2, 2, 0, 0, 0, 2, 2);
	moveCubiesCounterClockWise(0, 1, 2, 1, 1, 0, 1, 2);
	moveCubiesCounterClockWise(0, 0, 2, 2, 2, 0, 0, 2);
}









	
