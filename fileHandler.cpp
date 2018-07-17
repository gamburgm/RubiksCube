#include <fstream>
#include <iostream>
#include "fileHandler.h"

FileHandler::FileHandler() {
	int fileNum = 0;

	while (true) {
		string fileName = "Cube" + to_string(fileNum) + ".txt";

		ifstream test(fileName);
		bool isNewFile = test.good();
		test.close();

		if (!isNewFile) {
			currFile.open(fileName, ios::out | ios::in | ios::app);
			break;
		}

		fileNum++;
	}
}

FileHandler::FileHandler(string fileName) {
	currFile.open(fileName, ios::out | ios::in | ios::app); // maybe abstract file opening?
}

void FileHandler::writeCommand(string command) {
	currFile << command << endl;
}

void FileHandler::readCommands(Cube* c) {
	string line;

	currFile.clear();
	currFile.seekg(0, ios::beg);

	while (getline(currFile, line)) {
		c->readCommand(line);
	}	
}

