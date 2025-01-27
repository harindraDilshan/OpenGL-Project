#include<fstream>
#include<string>
#include<iostream>


static std::string grid[100] = {};

int getNumberOfLinse() {
	std::string symboolRow;

	std::ifstream MyReadFile("my_maze.txt");

	if (!MyReadFile.is_open()) {
		std::cout << "Error opening the file! <==1";
		return 0;
	}

	int numOfLines = 0;
	while (getline(MyReadFile, symboolRow)) {
		numOfLines++;
	}
	// Close the file
	MyReadFile.close();

	return numOfLines;
}


std::string* generateGridArray() {
	std::string symboolRow;

	std::ifstream MyReadFile("my_maze.txt");

	if (!MyReadFile.is_open()) {
		std::cout << "Error opening the file! <==2";
		return {};
	}

	int i = 0;
	while (getline(MyReadFile, symboolRow)) {
		grid[i] = symboolRow;
		i++;
	}
	// Close the file
	MyReadFile.close();

	return grid;
}