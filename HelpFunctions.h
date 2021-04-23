#pragma once
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "PuzzleBoard.h"


int fromCoordinateToInt(std::pair<int, int> x);
std::pair<int, int> fromIndexToCoordinate(const int x);
std::vector<std::pair<int, int>> allNeighboursHelp(std::pair<int,int> x);
std::vector<int> allNeighbours(int x);