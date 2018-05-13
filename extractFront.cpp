#include "extractFront.h"
#include "cubeface.h"

vector<Color> ExtractFront::extractLeftFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getRight();
	if (clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractFront::extractRightFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getLeft();
	if (clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractFront::extractTopFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getBottom();
	if (!clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractFront::extractBottomFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getTop();
	if (!clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

void ExtractFront::setLeftFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setRight(colors);
}

void ExtractFront::setRightFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setLeft(colors);
}

void ExtractFront::setTopFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setBottom(colors);
}

void ExtractFront::setBottomFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setTop(colors);
}
