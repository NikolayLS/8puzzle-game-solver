#pragma once
#include "PuzzleBoard.h"
#include "HelpFunctions.h"


bool vectorContains(std::vector<PuzzleBoard> vector, PuzzleBoard element);
std::vector<PuzzleBoard> bestFirstSearch(const PuzzleBoard& board, int (PuzzleBoard::*function)()const);
std::vector<std::pair<PuzzleBoard, std::vector<PuzzleBoard>>>checkedRemover(const std::vector<std::pair<PuzzleBoard,std::vector<PuzzleBoard>>>& checked, const PuzzleBoard& board);


