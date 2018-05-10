#ifndef CUBEFACE_H
#define CUBEFACE_H

#include <iostream>
#include <string>
#include <vector>
#include "color.h"
#include "extract.h"
#include "extractLeft.h"
#include "extractRight.h"
#include "extractFront.h"
#include "extractBack.h"
#include "extractTop.h"
#include "extractBottom.h"

class Extract;

using namespace std;

//a single face of a 3x3 Rubik's Cube
class CubeFace {
    private:
        Color faceColor;
        vector< vector<Color> > face;

		CubeFace* bottomFace;
		CubeFace* topFace;
		CubeFace* rightFace;
		CubeFace* leftFace;

        void turnClockWise();
        void turnCounterClockWise();
		void swapSidesClockWise(const Extract &e);
		void swapSidesCounterClockWise(const Extract &e);
    public:
        CubeFace(Color clr);
        bool completedFace();
        void addNeighbors(CubeFace* btm, CubeFace* top, CubeFace* right, CubeFace* left);
		Color getFaceColor();
		Color getFace(int row, int col);
		void setColor(Color clr);
		void setFace(int row, int col, Color clr);
		void printCubeFace();
		vector<Color> getTop();
		vector<Color> getBottom();
		vector<Color> getLeft();
		vector<Color> getRight();
		void setRight(vector<Color> colors);
		void setLeft(vector<Color> colors);
		void setTop(vector<Color> colors);
		void setBottom(vector<Color> colors);
		void rotateClockWise(const Extract &e);
		void rotateCounterClockWise(const Extract &e);
};

#endif
