#ifndef NAIVE_H
#define NAIVE_H

#include "Position.h"
#include <vector>

class Naive
{
    public:
    	static std::vector<double>* naive(Position*, int);
	private:
		static double getDistance(Position*, std::vector<double>, int, int);
};

#endif