#ifndef EXTRACTBACK_H
#define EXTRACTBACK_H

#include <algorithm>
#include "extract.h"
#include "color.h"

class CubeFace;

using namespace std;

class ExtractBack : public Extract {
	public:
		vector<Color> extractLeftFace(CubeFace* cubeface, bool clockwise) const;
		vector<Color> extractRightFace(CubeFace* cubeface, bool clockwise) const;
		vector<Color> extractTopFace(CubeFace* cubeface, bool clockwise) const;
		vector<Color> extractBottomFace(CubeFace* cubeface, bool clockwise) const;
		void setLeftFace(CubeFace* cubeface, vector<Color> colors) const;
		void setRightFace(CubeFace* cubeface, vector<Color> colors) const;
		void setTopFace(CubeFace* cubeface, vector<Color> colors) const;
		void setBottomFace(CubeFace* cubeface, vector<Color> colors) const;
};

#endif
