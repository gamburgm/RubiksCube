#include <iostream>
#include <fstream>
#include "extract.h"
#include "cube.h"
#include "fileHandler.h"


int main() {

	cout << "Before playing, let's check if FileHandler works." << endl;

	FileHandler h;

	Cube c;

	c.playGame();

	return 0;
}
