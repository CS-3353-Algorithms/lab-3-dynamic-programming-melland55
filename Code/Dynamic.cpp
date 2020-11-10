#include "Dynamic.h"
#include <math.h>
#include <algorithm>

//Reference: https://www.geeksforgeeks.org/memoization-1d-2d-and-3d/
//Reference: https://www.youtube.com/watch?v=cY4HiiFHO1o TimeStamp 9:30

//Uses top down memoization function to return best path
std::vector<double>* Dynamic::memoization(Position* positions, int numNodes){
    //Initializes memo table and stores infinity in every value
	double** memoTable = new double*[numNodes];
	int memoWidth = pow(2, numNodes);
    
	for(int i = 0; i < numNodes; i++){
		memoTable[i] = new double[memoWidth];
		std::fill_n(memoTable[i], memoWidth, INFINITY);
	}
    
	//Stores the distance from the first location to every other in the memo table
    for(int i = 1; i < numNodes; i++){
		memoTable[i][1 | 1 << i] = positions[0].getDistance(positions[i]);
	}
    
    //Solves the memo Table
    for(int i = 3; i <= numNodes; i++){
		std::vector<double> set;
        combinations(0, 0, i, numNodes, set);
		//Iterates through all bit-sets of size numNodes with i bits set to 1
		for(int j = 0; j < set.size(); j++){
			int subset = set.at(j);
			if(((1 << 0) & subset) == 0){
				continue;
            }
            
			for(int next = 1; next < numNodes; next++){
				if(((1 << next) & subset) == 0){
					continue;
                }
                
				int state = subset ^ (1 << next);
				double minDistance = INFINITY;
                
				for(int end = 1; end < numNodes; end++){
					if(end == next || ((1 << end) & subset) == 0){
						continue;
                    }
                    
					double distance = memoTable[end][state] + positions[end].getDistance(positions[next]);
                    
					if(distance < minDistance){
						minDistance = distance;
                    }
                    
					memoTable[next][subset] = minDistance;
				}
			}
		}
	}
	
	//Calculates the best path and its distance
	double bestDistance = findMinCost(positions, memoTable, numNodes);
	std::vector<double>* tour = findOptimalTour(positions, memoTable, numNodes);
    
	//Deletes memo table
	for(int i = 0; i < numNodes; i++){
		delete[] memoTable[i];
	}
	delete[] memoTable;
    
	//Reverses the path and adds the distance to the end of the path
    std::reverse(tour->begin(),tour->end());
    tour->pop_back();
	tour->push_back(bestDistance);

	return tour;
}

//Reference: https://www.youtube.com/watch?v=cY4HiiFHO1o TimeStamp 15:30
//Generates all bit-sets of size numNodes with r bits set to 1
void Dynamic::combinations(int set, int at, int r, int N, std::vector<double>& sets){
	if(r == 0){
	    sets.push_back(set);
	}else{
		for(int i = at; i < N; i++){
			set = set | (1 << i);
			combinations(set, i + 1, r - 1, N, sets);
			set = set & ~(1 << i);
		}
	}
}

//Reference: https://www.youtube.com/watch?v=cY4HiiFHO1o TimeStamp 17:15
//Utilizing the memo table, the minimum cost for all the paths is returned
double Dynamic::findMinCost(Position* positions, double** memo, int N){
	int endState = (1 << N) - 1;
	double minTourCost = INFINITY;
    
	for(int end = 1; end < N; end++){
		double tourCost = memo[end][endState] + positions[end].getDistance(positions[0]);
        
		if(tourCost < minTourCost){
			minTourCost = tourCost;
		}
	}
    
	return minTourCost;
}

//Reference: https://www.youtube.com/watch?v=cY4HiiFHO1o TimeStamp 18:00
//Utilizing the memo table, the minimum cost path is returned
std::vector<double>* Dynamic::findOptimalTour(Position* positions, double** memo, int N){
	int lastIndex = 0;
	int state = (1 << N) - 1;
	std::vector<double>* tour = new std::vector<double>(N + 1);
    
	for(int i = N-1; i > 0; i--){
		int index = 1;
        
		for(int j = 1; j < N; j++){
			if(((1 << j) & state) == 0){
				continue;
            }
			double prevDist = memo[index][state] + positions[index].getDistance(positions[lastIndex]);
			double newDist = memo[j][state] + positions[j].getDistance(positions[lastIndex]);
            
			if(newDist < prevDist){
				index = j;
            }
		}
        
		tour->at(i) = index;
		state = state ^ (1 << index);
		lastIndex = index;
	}
    
	tour->at(0) = 0;
	tour->at(N) = 0;
    
	for(int i = 0; i < tour->size(); i++){
		tour->at(i) = tour->at(i) + 1;
	}
    
	return tour;
}