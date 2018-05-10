ALLFILES = cubeMain.o cube.o cubeface.o extractLeft.o extractRight.o extractTop.o extractBottom.o extractFront.o extractBack.o
CFLAGS = -g -Wall -c
HFILES = cubeface.h color.h extract.h extractLeft.h extractRight.h extractBack.h extractFront.h extractTop.h extractBottom.h



main: ${ALLFILES}
	g++ ${ALLFILES} -o main

cubeMain.o: cubeMain.cpp cube.h ${HFILES} 
	g++ ${CFLAGS} cubeMain.cpp

cube.o: cube.cpp cube.h ${HFILES}
	g++ ${CFLAGS}  cube.cpp

cubeface.o: cubeface.cpp ${HFILES} 
	g++ ${CFLAGS} cubeface.cpp

extractLeft.o: extractLeft.cpp extractLeft.h ${HFILES}
	g++ ${CFLAGS} extractLeft.cpp

extractRight.o: extractRight.cpp extractRight.h ${HFILES}
	g++ ${CFLAGS} extractRight.cpp

extractTop.o: extractTop.cpp extractRight.h ${HFILES}
	g++ ${CFLAGS} extractTop.cpp

extractBottom.o: extractBottom.cpp extractBottom.h ${HFILES}
	g++ ${CFLAGS} extractBottom.cpp

extractFront.o: extractFront.cpp extractFront.h ${HFILES} 
	g++ ${CFLAGS} extractFront.cpp

extractBack.o: extractBack.cpp extractBack.h ${HFILES}
	g++ ${CFLAGS} extractBack.cpp

clean:
	rm -r ${ALLFILES} main
