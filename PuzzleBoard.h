#pragma once
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include "HelpFunctions.h"

class PuzzleBoard
{
	// in this task memory is important bcs algorithms are with bad space complexity
	// this is game board, but instead of making 2d int/short array i will parce it to only one integer
	// dont have to use integer to know where is the "empty/zero" bcs int is 4 bytes, but char is 1 so for this situation char
	// is better :)

	// unsigned int gameBoard - max value of int is 4,294,967,295
	// in this task we will need 9 digites but we have corner case with 0 in the begining
	// just putting 1 in the begining of the number so the number will look like -
	// 1-xxx-xxx-xxx
private:
	unsigned int gameBoard;
	char zeroIndex;

	int* randomArray()const;
public:
	void shuffle();
	PuzzleBoard();
	PuzzleBoard(const PuzzleBoard& puzzleBoard);
	PuzzleBoard& operator =(const PuzzleBoard& puzzleBoard);
	~PuzzleBoard();
	unsigned int getBoard();

	bool operator==(const PuzzleBoard& other)const;
	friend std::ostream& operator<<(std::ostream& os, const PuzzleBoard& board);
	int getZeroIndex()const;
	int getIndex(const int)const;
	std::vector<PuzzleBoard> getAllNeighbours()const;
	bool isPuzzleSolvable()const;
	int numberOfInversions()const;

	void swap(const int x);
	int heuruisticCOM()const; //number of wrong placed numbers
	int heuruisticMD()const;  //Manhatten distance
};

