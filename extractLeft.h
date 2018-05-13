#ifndef EXTRACTLEFT_H
#define EXTRACTLEFT_H

#include <algorithm>
#include "color.h"
#include "extract.h"

class CubeFace;

using namespace std;

class ExtractLeft : public Extract {
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
