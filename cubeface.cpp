#include "cubeface.h"
#include "color.h"
#include <string>
using namespace std;

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

void CubeFace::addNeighbors(CubeFace* btm, CubeFace* top, CubeFace* right, CubeFace* left) {
	bottomFace = btm;
	topFace = top;
	rightFace = right;
	leftFace = left;
}	

Color CubeFace::getFaceColor() {
	return faceColor;
}

Color CubeFace::getFace(int row, int col) {
	return face[row][col];
}

void CubeFace::setColor(Color clr) {
	faceColor = clr;
}

void CubeFace::setFace(int row, int col, Color clr) {
	face[row][col] = clr;
}	

void CubeFace::printCubeFace() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "[";
		
			Color clr = face[i][j];
			switch (clr) {
				case 0:
					cout << "R";
					break;
				case 2:
					cout << "B";
					break;
				case 4:
					cout << "G";
					break;
				case 1:
					cout << "Y";
					break;
				case 5:
					cout << "W";
					break;
				case 3:
					cout << "O";
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

void CubeFace::moveCubiesClockWise(int btmRow, int btmCol, int topRow, int topCol, int rightRow, int rightCol, int leftRow, int leftCol) {
	Color temp = topFace->getFace(topRow, topCol);

	topFace->setFace(topRow, topCol, rightFace->getFace(rightRow, rightCol));
	rightFace->setFace(rightRow, rightCol, bottomFace->getFace(btmRow, btmCol));
	bottomFace->setFace(btmRow, btmCol, leftFace->getFace(leftRow, leftCol));
	leftFace->setFace(leftRow, leftCol, temp);	
}

void CubeFace::moveCubiesCounterClockWise(int btmRow, int btmCol, int topRow, int topCol, int rightRow, int rightCol, int leftRow, int leftCol) {
	Color temp = topFace->getFace(topRow, topCol);

	topFace->setFace(topRow, topCol, leftFace->getFace(leftRow, leftCol));
	leftFace->setFace(leftRow, leftCol, bottomFace->getFace(btmRow, btmCol));
	bottomFace->setFace(btmRow, btmCol, rightFace->getFace(rightRow, rightCol));
	rightFace->setFace(rightRow, rightCol, temp);
}

void CubeFace::rotateClockWise() {
	turnClockWise();
	moveCubiesClockWise(0, 2, 2, 0, 0, 0, 2, 2);
	moveCubiesClockWise(0, 1, 2, 1, 1, 0, 1, 2);
	moveCubiesClockWise(0, 0, 2, 2, 2, 0, 0, 2);
}

void CubeFace::rotateCounterClockWise() {
	turnCounterClockWise();
	moveCubiesCounterClockWise(0, 2, 2, 0, 0, 0, 2, 2);
	moveCubiesCounterClockWise(0, 1, 2, 1, 1, 0, 1, 2);
	moveCubiesCounterClockWise(0, 0, 2, 2, 2, 0, 0, 2);
}









	
