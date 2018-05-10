#include "extractBack.h"
#include "cubeface.h"

vector<Color> ExtractBack::extractLeftFace(CubeFace* cubeface) const {
	return cubeface->getRight();
}

vector<Color> ExtractBack::extractRightFace(CubeFace* cubeface)  const {
	return cubeface->getLeft();
}

vector<Color> ExtractBack::extractTopFace(CubeFace* cubeface)  const {
	return cubeface->getTop();
}

vector<Color> ExtractBack::extractBottomFace(CubeFace* cubeface)  const {
	return cubeface->getBottom();
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

