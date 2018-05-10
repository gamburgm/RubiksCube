#include "extractRight.h"
#include "cubeface.h"

vector<Color> ExtractRight::extractLeftFace(CubeFace* cubeface) const {
	return cubeface->getRight();
}

vector<Color> ExtractRight::extractRightFace(CubeFace* cubeface) const {
	return cubeface->getLeft();
}

vector<Color> ExtractRight::extractTopFace(CubeFace* cubeface) const {
	return cubeface->getRight();
}

vector<Color> ExtractRight::extractBottomFace(CubeFace* cubeface) const {
	return cubeface->getRight();
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
