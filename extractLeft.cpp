#include "extractLeft.h"
#include "cubeface.h"

vector<Color> ExtractLeft::extractLeftFace(CubeFace* cubeface) const {
	return cubeface->getRight();
}

vector<Color> ExtractLeft::extractRightFace(CubeFace* cubeface) const {
	return cubeface->getLeft();
}

vector<Color> ExtractLeft::extractTopFace(CubeFace* cubeface) const {
	return cubeface->getLeft();
}

vector<Color> ExtractLeft::extractBottomFace(CubeFace* cubeface) const {
	return cubeface->getLeft();
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
