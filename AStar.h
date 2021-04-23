#pragma once
#include "BestFirstSearch.h"
std::vector<PuzzleBoard> aStar(const PuzzleBoard& board, int (PuzzleBoard::*function)()const);