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
		std::cout << a.numberOfInversions() << '\n';
		std::cout << a;
		std::cout << a.isPuzzleSolvable();
		std::cout << '\n' << "new york: " << a.heuruisticMD() << '\n';
		std::cout << "this may take a while..." << std::endl;
		std::vector<PuzzleBoard> temp = a.getAllNeighbours();
		std::vector<PuzzleBoard> x = aStar(a, &PuzzleBoard::heuruisticMD);
		std::cout << std::endl << "solved in: " << x.size() << std::endl;

		for (short i = 0;i < x.size();i++)
		{
			std::cout << x[i];
		}
	}
	catch (...)
	{
		std::cout << "something went wrong :(";
	}
	
}