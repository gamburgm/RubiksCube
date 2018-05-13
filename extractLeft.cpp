#include "extractLeft.h"
#include "cubeface.h"

vector<Color> ExtractLeft::extractLeftFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getRight();
	reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractLeft::extractRightFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getLeft();
}

vector<Color> ExtractLeft::extractTopFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getLeft();
	if (!clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractLeft::extractBottomFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getLeft();
	if (clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

void ExtractLeft::setLeftFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setRight(colors);
}

void ExtractLeft::setRightFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setLeft(colors);
}

void ExtractLeft::setTopFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setLeft(colors);
}

void ExtractLeft::setBottomFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setLeft(colors);
}
