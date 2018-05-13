#include "extractTop.h"
#include "cubeface.h"

vector<Color> ExtractTop::extractLeftFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getTop();
}

vector<Color> ExtractTop::extractRightFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getTop();
}

vector<Color> ExtractTop::extractTopFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getTop();
}

vector<Color> ExtractTop::extractBottomFace(CubeFace* cubeface, bool clockwise) const {
	return cubeface->getTop();
}

void ExtractTop::setLeftFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setTop(colors);
}

void ExtractTop::setRightFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setTop(colors);
}

void ExtractTop::setTopFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setTop(colors);
}

void ExtractTop::setBottomFace(CubeFace* cubeface, vector<Color> colors) const {
	cubeface->setTop(colors);
}
