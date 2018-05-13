#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <string>
#include "color.h"
#include "cubeface.h"
#include "extract.h"
#include "extractLeft.h"
#include "extractRight.h"
#include "extractFront.h"
#include "extractBack.h"
#include "extractTop.h"
#include "extractBottom.h"

using namespace std;


class Cube {
	private:
		CubeFace* bottomFace;
		CubeFace* frontFace;
		CubeFace* rightFace;
		CubeFace* backFace;
		CubeFace* leftFace;
		CubeFace* topFace;
	public:
		Cube();
		~Cube();
		void printFace(string faceName);
		int chooseColor(string faceName);
		void rotateFaceClockWise(string faceName);
		void rotateFaceCounterClockWise(string faceName);
		bool wonGame();
		void readCommands();
		void printLegend();
		void printAllFaces();
		//void randomizeBoard();
};

#endif
