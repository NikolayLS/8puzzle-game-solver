#include "PuzzleBoard.h"


PuzzleBoard::PuzzleBoard()
{ 
	this->gameBoard = 1012345678;
	this->zeroIndex = '0';
}

PuzzleBoard::PuzzleBoard(const PuzzleBoard& puzzleBoard)
{
	this->gameBoard = puzzleBoard.gameBoard;
	this->zeroIndex = puzzleBoard.zeroIndex;
}
PuzzleBoard& PuzzleBoard::operator =(const PuzzleBoard& puzzleBoard)
{
	if (this != &puzzleBoard)
	{
		this->gameBoard = puzzleBoard.gameBoard;
		this->zeroIndex = puzzleBoard.zeroIndex;
	}
	return *this;
}
PuzzleBoard::~PuzzleBoard(){}

bool PuzzleBoard::operator==(const PuzzleBoard& other)const
{
	return this->gameBoard == other.gameBoard && this->zeroIndex == other.zeroIndex;
}

std::ostream& operator<<(std::ostream& os, const PuzzleBoard& puzzleBoard)
{
	for (short i = 0; i < 9; i++)
	{
		unsigned temp = pow(10, 8-i);
		os << (puzzleBoard.gameBoard / temp)%10;
		if (i == 2 || i == 5 || i == 8) os << std::endl;
	}
	return os;
}

void PuzzleBoard::shuffle()
{
	int* randomNumArr = randomArray();
	this->gameBoard = 1;
	for (int i = 0; i < 9;i++) // 9 is the lenght of random array
	{
		this->gameBoard = 10 * this->gameBoard + randomNumArr[i];
		if (randomNumArr[i] == 0) zeroIndex = '0' + i;
	}
	if (!this->isPuzzleSolvable()) this->shuffle();
}

int* PuzzleBoard::randomArray()const
{
	static int array[9] = { 0,1,2,3,4,5,6,7,8 };
	for (int i = 0; i < 100; i++)
	{
		int randNum1 = rand() % 9;
		int randNum2 = rand() % 9;
		std::swap(array[randNum1], array[randNum2]);
	}
	return array;
}

int PuzzleBoard::getZeroIndex()const
{
	return this->zeroIndex - '0';
}

int PuzzleBoard::getIndex(const int x)const
{
	int temp = pow(10, 8 - x);
	return gameBoard / temp % 10;
}

void PuzzleBoard::swap(const int x)
{
	int temp = pow(10, 8-x);
	int temp2 = pow(10, 8-this->getZeroIndex());
	gameBoard = gameBoard - temp * getIndex(x) + temp2 * getIndex(x);
	zeroIndex = x + '0';
}

std::vector<PuzzleBoard> PuzzleBoard::getAllNeighbours()const
{
	std::vector<int> neighbours = allNeighbours(zeroIndex - '0');
	std::vector<PuzzleBoard> forReturn;
	for (short i = 0; i < neighbours.size();i++)
	{
		forReturn.push_back(*this);
		forReturn[i].swap(neighbours[i]);
	}
	return forReturn;
}

int PuzzleBoard::heuruisticCOM()const
{
	int counter = 0;
	unsigned int temp = gameBoard;
	for (short i = 8; i >= 0; i--)
	{
		if (temp % 10 != i) counter++;
		temp = temp / 10;
	}
	return counter;
}

int PuzzleBoard::heuruisticMD()const  //Manhatten distance
{
	unsigned int temp = this->gameBoard;
	short tempArr[3][3];
	for (short i = 2; i >= 0; i--)
	{
		for (short j = 2; j >= 0; j--)
		{
			tempArr[i][j] = temp % 10;
			temp /= 10;
		}
	}

	short manhattanSum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (tempArr[i][j])
			{
			case 0:
				manhattanSum = manhattanSum + (abs(i - 0) + abs(j - 0));
				break;
			case 1:
				manhattanSum = manhattanSum + (abs(i - 0) + abs(j - 1));
				break;
			case 2:
				manhattanSum = manhattanSum + (abs(i - 0) + abs(j - 2));
				break;
			case 3:
				manhattanSum = manhattanSum + (abs(i - 1) + abs(j - 0));
				break;
			case 4:
				manhattanSum = manhattanSum + (abs(i - 1) + abs(j - 1));
				break;
			case 5:
				manhattanSum = manhattanSum + (abs(i - 1) + abs(j - 2));
				break;
			case 6:
				manhattanSum = manhattanSum + (abs(i - 2) + abs(j - 0));
				break;
			case 7:
				manhattanSum = manhattanSum + (abs(i - 2) + abs(j - 1));
				break;
			case 8:
				manhattanSum = manhattanSum + (abs(i - 2) + abs(j - 2));
				break;
			default:
				throw"Exception";
			}
		}
	}
	return manhattanSum;
}

int PuzzleBoard::numberOfInversions()const
{
	unsigned int temp = gameBoard;
	int arr[9];
	for (short i = 8; i >= 0; i--)
	{
		arr[i] = temp % 10;
		temp /= 10;
	}
	//if the inversions are odd the puzzle is unsolvable
	short invCount = 0;
	for (short i = 0;i < 9;i++)
	{
		for (short j = i; j < 9; j++)
		{
			if (arr[j] && arr[i] > arr[j]) invCount++;
		}
	}
	return invCount;
}

bool PuzzleBoard::isPuzzleSolvable()const
{

	return !(this->numberOfInversions()%2);
}


unsigned int PuzzleBoard::getBoard()
{
	return gameBoard;
}