#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iterator>
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
		//the six faces of the cube
		CubeFace* bottomFace;
		CubeFace* frontFace;
		CubeFace* rightFace;
		CubeFace* backFace;
		CubeFace* leftFace;
		CubeFace* topFace;
	public:
		Cube();
		~Cube();
		void printFace(string faceName);       //print a CubeFace given its name
		int chooseFace(string faceName);      //determine a face given its name
		void readCommand(string input);      //execute a print or rotation given instructions
		void handleCommand(string command, bool cw); 
		void rotateCube(string command, bool cw);
		void rotateFace(string faceName, bool clockwise); //rotate a face given the face's name and rotation direction
		bool wonGame();        //check if the game is won
		void playGame();       //play Rubik's Cube
		void printLegend();    //print the instructions that the user can use
		void printAllFaces();  //print all cubefaces of this cube
		void randomizeCube();  //randomly rotate the cube
		void rotateYClockWise(); //change orientation y cw
		void rotateYCounterClockWise(); //change orientation y ccw
		void rotateXClockWise();
		void rotateXCounterClockWise();
		void rotateZClockWise();
		void rotateZCounterClockWise();
};

#endif
