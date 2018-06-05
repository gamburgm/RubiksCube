#include <fstream>
#include <iostream>
#include "fileHandler.h"

FileHandler::FileHandler() {
	int fileNum = 0;

	while (true) {
		cout << "curr num is " << fileNum << "!!!!" << endl;

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


	currFile << "HI" << endl;
}

