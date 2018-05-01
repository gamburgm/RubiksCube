main: cubeMain.o cube.o cubeface.o
	g++ cubeMain.o cube.o cubeface.o -o main

cubeMain.o: cubeMain.cpp cube.h cubeface.h color.h
	g++ -g -Wall -c cubeMain.cpp

cube.o: cube.cpp cube.h cubeface.h color.h
	g++ -g -Wall -c cube.cpp

cubeface.o: cubeface.cpp cubeface.h color.h
	g++ -g -Wall -c cubeface.cpp

clean:
	rm -r cubeMain.o cube.o cubeface.o main
