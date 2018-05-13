#include "extractBottom.h"
#include "cubeface.h"

vector<Color> ExtractBottom::extractLeftFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getBottom();
}

vector<Color> ExtractBottom::extractRightFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getBottom();
}

vector<Color> ExtractBottom::extractTopFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getBottom();
}

vector<Color> ExtractBottom::extractBottomFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getBottom();
}

void ExtractBottom::setLeftFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setBottom(colors);
}

void ExtractBottom::setRightFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setBottom(colors);
}

void ExtractBottom::setTopFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setBottom(colors);
}

void ExtractBottom::setBottomFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setBottom(colors);
}
