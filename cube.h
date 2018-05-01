#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <string>
#include "color.h"
#include "cubeface.h"
using namespace std;


class Cube {
	private:
		CubeFace* redFace;
		CubeFace* yellowFace;
		CubeFace* blueFace;	
		CubeFace* whiteFace;
		CubeFace* greenFace;
		CubeFace* orangeFace;
	public:
		Cube();
		~Cube();
		void printFace(string faceName);
		int chooseColor(string faceName);
		void rotateFaceClockWise(string faceName);
		void rotateFaceCounterClockWise(string faceName);
		//void randomizeBoard();
		//void rotateFace(CubeFace* face);	
};

#endif
