#include "BestFirstSearch.h"


bool vectorContains(std::vector<PuzzleBoard> vector, PuzzleBoard element)
{
	for (int i = 0; i < vector.size(); i++)
	{
		if (vector[i] == element)return true;
	}
	return false;
}

std::vector<std::pair<PuzzleBoard, std::vector<PuzzleBoard>>>checkedRemover(const std::vector<std::pair<PuzzleBoard, std::vector<PuzzleBoard>>>& checked, const PuzzleBoard& board) 
{
	std::vector<std::pair<PuzzleBoard, std::vector<PuzzleBoard>>> newChecked;
	for (int i = 0; i < checked.size(); i++)
	{
		if (!(checked[i].first == board)) newChecked.push_back(checked[i]);
	}
	return newChecked;
}

std::vector<PuzzleBoard> bestFirstSearch(const PuzzleBoard& board, int (PuzzleBoard::*function)()const)
{
	std::vector<std::pair<PuzzleBoard, std::vector<PuzzleBoard>>> toBeChecked;
	std::vector<PuzzleBoard> emptyBoard;
	std::vector<PuzzleBoard> visitedBoards;
	visitedBoards.push_back(board);
	std::pair <PuzzleBoard, std::vector<PuzzleBoard>> minHValueBoard(board, emptyBoard);

	//At the begining we have only the first board:
	toBeChecked.push_back(std::pair<PuzzleBoard, std::vector<PuzzleBoard>>(board, emptyBoard));

	while (!toBeChecked.empty())
	{
		std::vector<PuzzleBoard> neighbours = minHValueBoard.first.getAllNeighbours();
		for (int i = 0; i < neighbours.size(); i++)
		{
			std::vector<PuzzleBoard> newPath = minHValueBoard.second;
			newPath.push_back(minHValueBoard.first);
			if (!vectorContains(visitedBoards, neighbours[i]) && newPath.size() < 50)
			{
				visitedBoards.push_back(neighbours[i]);
				toBeChecked.push_back(std::pair<PuzzleBoard, std::vector<PuzzleBoard>>(neighbours[i], newPath));
			}
		}
		minHValueBoard = toBeChecked[0];
		for (int i = 0; i < toBeChecked.size(); i++)
		{
			if ((toBeChecked[i].first.*function)() <= (minHValueBoard.first.*function)())
				minHValueBoard = toBeChecked[i];
		}
		toBeChecked = checkedRemover(toBeChecked, minHValueBoard.first);
	}
	if(minHValueBoard.second.empty()) throw std::runtime_error("algorithm did succeed");
	minHValueBoard.second.push_back(PuzzleBoard());
	return minHValueBoard.second;
}

