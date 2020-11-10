#ifndef POSITION_H
#define POSITION_H

#include <cmath>
#include <iostream>

struct Position{
    double x, y, z;
	
	double getDistance(Position position){
		return sqrt(((x - position.x) * (x - position.x)) + ((y - position.y) * (y - position.y)) + ((z - position.z) * (z - position.z)));
	}
};

#endif