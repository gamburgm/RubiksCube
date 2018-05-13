#include "extractBack.h"
#include "cubeface.h"

vector<Color> ExtractBack::extractLeftFace(CubeFace* cubeface, bool clockwise) const {
	vector<Color> colors = cubeface->getRight();
	if (!clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractBack::extractRightFace(CubeFace* cubeface, bool clockwise)  const {
	vector<Color> colors = cubeface->getLeft();
	if (!clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractBack::extractTopFace(CubeFace* cubeface, bool clockwise)  const {
	vector<Color> colors = cubeface->getTop();
	if (clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

vector<Color> ExtractBack::extractBottomFace(CubeFace* cubeface, bool clockwise)  const {
	vector<Color> colors = cubeface->getBottom();
	if (clockwise)
		reverse(colors.begin(), colors.end());
	return colors;
}

void ExtractBack::setLeftFace(CubeFace* cubeface, vector<Color> colors)  const {
	cubeface->setRight(colors);
}

void ExtractBack::setRightFace(CubeFace* cubeface, vector<Color> colors)  const {
	cubeface->setLeft(colors);
}

void ExtractBack::setTopFace(CubeFace* cubeface, vector<Color> colors)  const {
	cubeface->setTop(colors);
}

void ExtractBack::setBottomFace(CubeFace* cubeface, vector<Color> colors)  const {
	cubeface->setBottom(colors);
}

