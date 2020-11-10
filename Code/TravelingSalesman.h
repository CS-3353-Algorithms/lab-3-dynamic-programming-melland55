#ifndef TRAVELING_SALESMAN_H
#define TRAVELING_SALESMAN_H

#include "Algorithm.h"
#include "Dynamic.h"
#include "Naive.h"
#include "Position.h"
#include <chrono>
#include <ratio>

class Salesman : public Algorithm
{
    public:
    	Salesman();
    	~Salesman();
        void load(std::string);
        void execute();
        void display();
        void stats(std::string);
        void select(int);
        void save(std::string);
        void configure(int);
    private:
    	std::vector<double>* (*algoPointer)(Position*, int);
    	std::string currentAlgo;
		std::vector<int>* path;
    	std::chrono::duration<double, std::milli> time;
    	Position* positions;
		int numNodes = 0;
		int nodeCount = 0;
		double distance = 0;
};

#endif