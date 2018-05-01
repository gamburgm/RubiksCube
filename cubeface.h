#ifndef CUBEFACE_H
#define CUBEFACE_H

#include <iostream>
#include <string>
#include <vector>
#include "color.h"
using namespace std;

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
		void moveCubiesClockWise(int btmRow, int btmCol, int topRow, int topCol, int rightRow, int rightCol, int leftRow, int leftCol);
		void moveCubiesCounterClockWise(int btmRow, int btmCol, int topRow, int topCol, int rightRow, int rightCol, int leftRow, int leftCol);
    public:
        CubeFace(Color clr);
        bool completedFace();
        void addNeighbors(CubeFace* btm, CubeFace* top, CubeFace* right, CubeFace* left);
		Color getFaceColor();
		Color getFace(int row, int col);
		void setColor(Color clr);
		void setFace(int row, int col, Color clr);
		void printCubeFace();
		void rotateClockWise();
		void rotateCounterClockWise();
};

#endif
