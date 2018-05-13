#ifndef EXTRACT_H
#define EXTRACT_H

#include "color.h"

class CubeFace;

using namespace std;

class Extract {
	public:
		virtual vector<Color> extractLeftFace(CubeFace* cubeface, bool clockwise) const = 0;
		virtual vector<Color> extractRightFace(CubeFace* cubeface, bool clockwise) const = 0;
		virtual vector<Color> extractTopFace(CubeFace* cubeface, bool clockwise) const = 0;
		virtual vector<Color> extractBottomFace(CubeFace* cubeface, bool clockwise) const = 0;
		virtual void setLeftFace(CubeFace* cubeface, vector<Color> colors) const = 0;
		virtual void setRightFace(CubeFace* cubeface, vector<Color> colors) const = 0;
		virtual void setTopFace(CubeFace* cubeface, vector<Color> colors) const = 0;
		virtual void setBottomFace(CubeFace* cubeface, vector<Color> colors) const = 0;
};

#endif
