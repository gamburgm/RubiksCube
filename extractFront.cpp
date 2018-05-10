#include "extractFront.h"
#include "cubeface.h"

vector<Color> ExtractFront::extractLeftFace(CubeFace* cubeface) const {
	return cubeface->getRight();
}

vector<Color> ExtractFront::extractRightFace(CubeFace* cubeface) const {
	return cubeface->getLeft();
}

vector<Color> ExtractFront::extractTopFace(CubeFace* cubeface) const {
	return cubeface->getBottom();
}

vector<Color> ExtractFront::extractBottomFace(CubeFace* cubeface) const {
	return cubeface->getTop();
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
