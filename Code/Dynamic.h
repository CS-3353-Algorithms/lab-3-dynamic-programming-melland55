#ifndef DYNAMIC_H
#define DYNAMIC_H

#include "Position.h"
#include <vector>

class Dynamic
{
    public:
		static std::vector<double>* memoization(Position*, int);
	private:
		static void combinations(int, int, int, int, std::vector<double>&);
		static double findMinCost(Position*, double**, int);
		static std::vector<double>* findOptimalTour(Position*, double**, int);
};

#endif