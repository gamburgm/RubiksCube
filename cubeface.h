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

//a single face of a 3x3x3 Rubik's Cube
class CubeFace {
    private:
        Color faceColor;
        vector< vector<Color> > face;

		//the four neighbors of this CubeFace
		CubeFace* bottomFace;
		CubeFace* topFace;
		CubeFace* rightFace;
		CubeFace* leftFace;

		//transform the colors of this CubeFace's face based on a specified direction direction
        void turnClockWise();
        void turnCounterClockWise();
		//swap the colors of the neighboring faces of this CubeFace given an Extract and with a specified direction
		void swapSidesClockWise(const Extract &e);
		void swapSidesCounterClockWise(const Extract &e);
		//rotate this CubeFace in a specified direction
		void rotateClockWise(const Extract &e);
		void rotateCounterClockWise(const Extract &e);
    public:
        CubeFace(Color clr);
        bool completedFace();  //check that all colors in this Face are equal to this CubeFace's color field
        void addNeighbors(CubeFace* btm, CubeFace* top, CubeFace* right, CubeFace* left); //add the given CubeFaces to this CubeFace's neighbor fields
		Color getFaceColor();  //return the defined color of this CubeFace
		Color getFace(int row, int col); //return the color at the given index of this face
		void setColor(Color clr); //set the defined color of this CubeFace to the given color
		void setFace(int row, int col, Color clr); //set the color at the given index of this face to the given color
		void printCubeFace();  //print this CubeFace
		vector<Color> getTop();    //return a vector of the colors on the topmost row of this face
		vector<Color> getBottom(); //return a vector of the colors on the bottommost row of this face
		vector<Color> getLeft();   //return a vector of the colors on the leftmost column of this face
		vector<Color> getRight();  //return a vector of the columns of the rightmost column of this face
		void setRight(vector<Color> colors);   //set the rightmost column to the given vector 
		void setLeft(vector<Color> colors);    //set the leftmost column to the given vector
		void setTop(vector<Color> colors);     //set the topmost row to the given vector
		void setBottom(vector<Color> colors);  //set the bottomost row to the given vector
		void rotate(const Extract &e, bool clockwise);  //rotate this face given an Extract and a direction
};

#endif
