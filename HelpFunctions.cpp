#include "HelpFunctions.h"

int fromCoordinateToInt(std::pair<int, int> x)
{
	if (x.first == 0 && x.second == 0) return 0;
	if (x.first == 0 && x.second == 1) return 1;
	if (x.first == 0 && x.second == 2) return 2;
	if (x.first == 1 && x.second == 0) return 3;
	if (x.first == 1 && x.second == 1) return 4;
	if (x.first == 1 && x.second == 2) return 5;
	if (x.first == 2 && x.second == 0) return 6;
	if (x.first == 2 && x.second == 1) return 7;
	if (x.first == 2 && x.second == 2) return 8;
	throw std::runtime_error("invalid");
}

std::pair<int, int> fromIndexToCoordinate(const int x)
{
	switch (x)
	{
	case 0: return std::pair<int, int>(0, 0);
	case 1: return std::pair<int, int>(0, 1);
	case 2: return std::pair<int, int>(0, 2);
	case 3: return std::pair<int, int>(1, 0);
	case 4: return std::pair<int, int>(1, 1);
	case 5: return std::pair<int, int>(1, 2);
	case 6: return std::pair<int, int>(2, 0);
	case 7: return std::pair<int, int>(2, 1);
	case 8: return std::pair<int, int>(2, 2);
	default: throw std::runtime_error("invalid");
	}
}

std::vector<std::pair<int, int>> allNeighboursHelp(std::pair<int,int> x)
{
	std::vector<std::pair<int, int>> temp;
	int height = x.first;
	int width = x.second;
	if (x.first - 1 > -1) temp.push_back(std::pair<int, int>(height - 1, width));
	if (x.first + 1 < 3) temp.push_back(std::pair<int, int>(height + 1, width));
	if (x.second + 1 < 3) temp.push_back(std::pair<int, int>(height, width + 1));
	if (x.second - 1 > -1) temp.push_back(std::pair<int, int>(height, width - 1));
	return temp;
}

std::vector<int> allNeighbours(int x)
{
	std::pair<int, int> tempPair = fromIndexToCoordinate(x);
	std::vector<std::pair<int, int>> tempVector = allNeighboursHelp(tempPair);
	std::vector<int> forReturn;
	for (short i = 0; i < tempVector.size();i++)
	{
		forReturn.push_back(fromCoordinateToInt(tempVector[i]));
	}
	return forReturn;
}