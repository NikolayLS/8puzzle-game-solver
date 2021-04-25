#include <iostream>
#include <time.h> 
#include "PuzzleBoard.h"
#include "BestFirstSearch.h"
#include "AStar.h"

int main()
{
	try
	{
		srand(time(NULL));
		PuzzleBoard a;
		a.shuffle();
		std::cout << "Wellcome to 8-puzzle-solver!" << '\n';
		std::cout << "Your random generated board is:" << '\n';
		std::cout << a<<'\n';
		std::cout << "Press 1 to solve it with Best First Search with heuruistic function - count of messed numbers" << '\n';
		std::cout << "Press 2 to solve it with Best First Search with heuruistic function - Manhattan distance" << '\n';
		std::cout << "Press 3 to solve it with A* with heuruistic function - count of messed numbers" << '\n';
		std::cout << "Press 4 to solve it with A* with heuruistic function - Manhattan distance" << '\n';
		short t;
		std::cin >> t;
		std::cout << "solving... " << '\n';
		std::vector<PuzzleBoard> x;
		if (t == 1) x = bestFirstSearch(a, &PuzzleBoard::heuruisticCOM);
		else if (t == 2) x = bestFirstSearch(a, &PuzzleBoard::heuruisticMD);
		else if (t == 3) x = aStar(a, &PuzzleBoard::heuruisticCOM);
		else if (t == 4) x = aStar(a, &PuzzleBoard::heuruisticMD);
		else { std::cout << "wrong input" << '\n';return 0; }

		std::cout << std::endl << "solved in: " << x.size() << "steps" << std::endl;

		for (short i = 0;i < x.size();i++)
		{
			std::cout << x[i] << '\n';
			if (i != x.size() - 1)
			{
				std::cout << " ^  " << '\n';
				std::cout << " |  " << '\n';
				
			}
		}
	}
	catch (...)
	{
		std::cout << "something went wrong :(";
	}
}