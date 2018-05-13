#include "extractRight.h"
#include "cubeface.h"

vector<Color> ExtractRight::extractLeftFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getRight();
}

vector<Color> ExtractRight::extractRightFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getLeft();
	reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractRight::extractTopFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getRight();
	if (clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractRight::extractBottomFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getRight();
	if (!clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

void ExtractRight::setLeftFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setRight(colors);
}

void ExtractRight::setRightFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setLeft(colors);
}

void ExtractRight::setTopFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setRight(colors);
}

void ExtractRight::setBottomFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setRight(colors);
}
