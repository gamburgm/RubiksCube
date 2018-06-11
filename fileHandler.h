#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include "cube.h"

class Cube;

using namespace std;

class FileHandler {
	private:
		fstream currFile;
	public:
		FileHandler();
		FileHandler(string fileName);
		void writeCommand(string command);
		void readCommands(Cube* c);		
};

#endif
