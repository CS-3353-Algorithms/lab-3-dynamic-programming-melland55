#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>

class Algorithm
{
    public:
    	//Creates an enumerator for each type of Traveling Salesmen Algorithm
        enum TravelerAlgo{
            NAIVE = 0,
            DYNAMIC,
            END
        };
    	
    	//Abstractly defines the functions of an algorithm
        virtual void load(std::string) = 0;
        virtual void execute() = 0;
        virtual void display() = 0;
        virtual void stats(std::string) = 0;
        virtual void select(int) = 0;
        virtual void save(std::string) = 0;
        virtual void configure(int) = 0;
};

#endif