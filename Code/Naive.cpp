#include "Naive.h"
#include <algorithm>

std::vector<double>* Naive::naive(Position* positions, int numNodes){
	std::vector<double>* bestPath = new std::vector<double>();
	std::vector<double> nodes;
	double bestDistance = INFINITY;
    
    //Adds all the nodes to to vector of nodes, nodes
	for(int i = 0; i < numNodes; i++){
		nodes.push_back(i + 1);
	}
    
    //Adds border value of 1
	nodes.push_back(1);
    
    //Refrence: https://www.javatpoint.com/cpp-algorithm-next_permutation-function
    //Loops through every permutation of nodes (ignoring the first and last border nodes) and checks the distance to see if it is the best path
	do{
		//Calculates distance of given path permutation of nodes with recursive function getDistance from 0 to numNodes
		double distance = getDistance(positions, nodes, 0, numNodes);
        
		//Checks if the distance of the new permutation of nodes is better than the previous best then sets it
		if(distance < bestDistance){
			bestDistance = distance;
			*bestPath = nodes;
		}
	}while(std::next_permutation(nodes.begin() + 1, nodes.end() - 1));
    
	//Removes the tail value and stores the paths total distance
    bestPath->pop_back();
	bestPath->push_back(bestDistance);
	return bestPath;
}

double Naive::getDistance(Position* positions, std::vector<double> nodes, int from, int to){
	if(to - from == 1){
		//Returns the distance between the last two nodes in vector nodes
		return positions[(int)(nodes.at(from)) - 1].getDistance(positions[(int)(nodes.at(from + 1)) - 1]);
	}else{
        //Returns the distance between the current and next node and recursively calls getDistance from the next position to calculate to the end
	    return positions[(int)(nodes.at(from)) - 1].getDistance(positions[(int)(nodes.at(from + 1)) - 1]) + getDistance(positions, nodes, from + 1, to);
    }
}