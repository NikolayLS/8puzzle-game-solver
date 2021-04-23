#include "AStar.h"


std::vector<PuzzleBoard> aStar(const PuzzleBoard& board, int (PuzzleBoard::*function)()const)
{
	std::vector<std::pair<PuzzleBoard, std::vector<PuzzleBoard>>> toBeChecked;
	std::vector<PuzzleBoard> emptyBoard;
	std::vector<PuzzleBoard> visitedBoards;
	visitedBoards.push_back(board);
	std::pair <PuzzleBoard, std::vector<PuzzleBoard>> minHValueBoard(board, emptyBoard);

	//At the begining we have only the first board:
	toBeChecked.push_back(std::pair<PuzzleBoard, std::vector<PuzzleBoard>>(board, emptyBoard));

	while (minHValueBoard.first.getBoard() != 1012345678 && !toBeChecked.empty())
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
			if ((toBeChecked[i].first.*function)() + 200*toBeChecked[i].second.size() <= (minHValueBoard.first.*function)() + 200 * toBeChecked[i].second.size())
				minHValueBoard = toBeChecked[i];
		}
		toBeChecked = checkedRemover(toBeChecked, minHValueBoard.first);
	}
	if (minHValueBoard.second.empty()) throw std::runtime_error("algorithm did succeed");
	minHValueBoard.second.push_back(PuzzleBoard());
	return minHValueBoard.second;
}