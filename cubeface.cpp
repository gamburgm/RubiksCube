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
			if (clr != faceColor) {
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
					cout << "\033[1mW\033[0m";
					break;
				case 1:
					cout << "\033[1;31mR\033[0m";
					break;
				case 2:
					cout << "\033[1;38;5;10mG\033[0m";
					break;
				case 3:
					cout << "\033[1;38;5;202mO\033[0m";
					break;
				case 4:
					cout << "\033[1;38;5;12mB\033[0m";
					break;
				case 5:
					cout << "\033[1;38;5;11mY\033[0m";
					break;
				default:
					cout << "?";
					break;
			}
			cout << "]";
		}
		cout << endl;
	}
	cout << endl;
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

//extract the colors from the topmost row
vector<Color> CubeFace::getTop() {
	vector<Color> temp;

	for (int i = 0; i < 3; i++) {
		temp.push_back(face[0][i]);
	}

	return temp;
}

//extract the colors of the bottommost row
vector<Color> CubeFace::getBottom() {
	vector<Color> temp;

	for (int i = 0; i < 3; i++) {
		temp.push_back(face[2][i]);
	}

	return temp;
}

//extract the colors of the leftmost row
vector<Color> CubeFace::getLeft() {
	vector<Color> temp;

	for (int i = 0; i < 3; i++) {
		temp.push_back(face[i][0]);
	}

	return temp;
}

//extract the colors of the rightmost column
vector<Color> CubeFace::getRight() {
	vector<Color> temp;
	
	for (int i = 0; i < 3; i++) {
		temp.push_back(face[i][2]);
	}

	return temp;
}

void CubeFace::setLeft(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[i][0] = colors[i];
		}
	}
}

void CubeFace::setRight(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[i][2] = colors[i];
		}
	}
}

void CubeFace::setTop(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[0][i] = colors[i];
		}
	}
}

void CubeFace::setBottom(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[2][i] = colors[i];
		}
	}
}

void CubeFace::swapSidesClockWise(const Extract &e) {
	vector<Color> temp = e.extractLeftFace(leftFace);
	e.setLeftFace(leftFace, e.extractBottomFace(bottomFace));	
	e.setBottomFace(bottomFace, e.extractRightFace(rightFace));
	e.setRightFace(rightFace, e.extractTopFace(topFace));
	e.setTopFace(topFace, temp);
}

void CubeFace::swapSidesCounterClockWise(const Extract &e) {
	vector<Color> temp = e.extractLeftFace(leftFace);
	e.setLeftFace(leftFace, e.extractTopFace(topFace));
	e.setTopFace(topFace, e.extractRightFace(rightFace));
	e.setRightFace(rightFace, e.extractBottomFace(bottomFace));
	e.setBottomFace(bottomFace, temp);
}

void CubeFace::rotateClockWise(const Extract &e) {
	turnClockWise();
	swapSidesClockWise(e);	
}

void CubeFace::rotateCounterClockWise(const Extract &e) {
	turnCounterClockWise();
	swapSidesCounterClockWise(e);
}

