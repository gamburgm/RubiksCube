# Rubik's Cube
Play a quick game of Rubik's Cube in your shell!

## Installation
Installing and running is easy: just clone the repo and compile the project.
```
git clone https://github.com/gamburgm/RubiksCube.git
cd RubiksCube/
make
```

## Usage
Playing is even easier—just execute the main binary.
```
./main
```

The game starts with a randomized cube and instructions to rotate each face. Keep rotating till you've finished!

![Start of Game](images/start.png)


![End of Game](images/finish.png)

Each game you play is saved in a `CubeX.txt` file for you to resume! Just run the program with your file as an argument:
```
./main Cube2.txt
```
