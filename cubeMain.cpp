#include <iostream>
#include <fstream>
#include "extract.h"
#include "cube.h"
#include "fileHandler.h"


int main(int argc, char* argv[]) {
	
	if (argc > 1) {
		Cube c(argv[1]);
		c.playGame();
	}
	else {
		Cube c;
		c.playGame();
	}		


	return 0;
}
