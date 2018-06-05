import os

for i in range(1, 100000):
	fileName = "Cube" + str(i) + ".txt"
	try:
		os.remove(fileName)
	except FileNotFoundError:
		continue


