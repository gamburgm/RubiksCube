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

//check if all colors in the face of the CubeFace is of this CubeFace's color
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

//add the given CubeFaces to this CubeFace's neighbor fields
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

//transform the colors of this CubeFace's face clockwise
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

//transform the colors of this CubeFace's face counter-clockwise
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

//return a vector of the topmost row of this face
vector<Color> CubeFace::getTop() {
	vector<Color> temp;

	for (int i = 0; i < 3; i++) {
		temp.push_back(face[0][i]);
	}

	return temp;
}

//return a vector of the bottommost row of this face
vector<Color> CubeFace::getBottom() {
	vector<Color> temp;

	for (int i = 0; i < 3; i++) {
		temp.push_back(face[2][i]);
	}

	return temp;
}

//return a vector of the leftmost column of this face
vector<Color> CubeFace::getLeft() {
	vector<Color> temp;

	for (int i = 0; i < 3; i++) {
		temp.push_back(face[i][0]);
	}

	return temp;
}

//return a vector of the rightmost column of this face
vector<Color> CubeFace::getRight() {
	vector<Color> temp;
	
	for (int i = 0; i < 3; i++) {
		temp.push_back(face[i][2]);
	}

	return temp;
}

//set the leftmost column of this face to the colors in the given vector
void CubeFace::setLeft(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[i][0] = colors[i];
		}
	}
}

//set the rightmost column of this face to the colors in the given vector
void CubeFace::setRight(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[i][2] = colors[i];
		}
	}
}

//set the topmost row of this face to the colors in the given vector
void CubeFace::setTop(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[0][i] = colors[i];
		}
	}
}

//set the bottommost row of this face to the colors in the given vector
void CubeFace::setBottom(vector<Color> colors) {
	if (colors.size() == 3) {
		for (int i = 0; i < 3; i++) {
			face[2][i] = colors[i];
		}
	}
}

//swap the colors of the neighbors of this CubeFace clockwise given an Extract
void CubeFace::swapSidesClockWise(const Extract &e) {
	vector<Color> temp = e.extractLeftFace(leftFace, true);
	e.setLeftFace(leftFace, e.extractBottomFace(bottomFace, true));	
	e.setBottomFace(bottomFace, e.extractRightFace(rightFace, true));
	e.setRightFace(rightFace, e.extractTopFace(topFace, true));
	e.setTopFace(topFace, temp);
}

//swap the colors of the neighbors of this CubeFace counter-clockwise given an Extract
void CubeFace::swapSidesCounterClockWise(const Extract &e) {
	vector<Color> temp = e.extractLeftFace(leftFace, false);
	e.setLeftFace(leftFace, e.extractTopFace(topFace, false));
	e.setTopFace(topFace, e.extractRightFace(rightFace, false));
	e.setRightFace(rightFace, e.extractBottomFace(bottomFace, false));
	e.setBottomFace(bottomFace, temp);
}

//rotate this CubeFace clockwise given an Extract
void CubeFace::rotateClockWise(const Extract &e) {
	turnClockWise();
	swapSidesClockWise(e);	
}

//rotate this CubeFace counter-clockwise given an Extract
void CubeFace::rotateCounterClockWise(const Extract &e) {
	turnCounterClockWise();
	swapSidesCounterClockWise(e);
}

//rotate this CubeFace given an Extract and a direction 
void CubeFace::rotate(const Extract &e, bool clockwise) {
	if (clockwise)
		rotateClockWise(e);
	else
		rotateCounterClockWise(e);
}

void CubeFace::orientClockWise() {
	turnClockWise();
	
	CubeFace* temp = leftFace;
	leftFace = bottomFace;
	bottomFace = rightFace;
	rightFace = topFace;
	topFace = temp;
}

void CubeFace::orientCounterClockWise() {
	turnCounterClockWise();

	CubeFace* temp = leftFace;
	leftFace = topFace;
	topFace = rightFace;
	rightFace = bottomFace;
	bottomFace = temp;
}

void CubeFace::totalReOrientation() {
	turnClockWise();
	turnClockWise();

	CubeFace* tempOne = topFace;
	topFace = bottomFace;
	bottomFace = tempOne;

	CubeFace* tempTwo = leftFace;
	leftFace = rightFace;
	rightFace = tempTwo;
}



