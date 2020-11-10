#include "TravelingSalesman.h"
#include "FileReader.h"
#include "FileWriter.h"

Salesman::Salesman(){
}

Salesman::~Salesman(){
	delete positions;
	delete path;
}

void Salesman::load(std::string graph){
	FileReader* fr = new FileReader(graph);
	numNodes = fr->getFileSize();
	nodeCount = numNodes;
	positions = new Position[numNodes];
	fr->reset();
	
	int i = 0;
	while(!fr->eof()){
		std::vector<std::string>* line = fr->csvNextLine();
		Position position;
		position.x = stod(line->at(1));
		position.y = stod(line->at(2));
		position.z = stod(line->at(3));
		positions[i++] = position;
	}
	delete fr;
}

void Salesman::execute(){
	auto start = std::chrono::high_resolution_clock::now();
	std::vector<double>* temp = algoPointer(positions, nodeCount);
	time = std::chrono::high_resolution_clock::now() - start;
	distance = temp->back();
	temp->pop_back();
	path = new std::vector<int>(temp->begin(), temp->end());
	delete temp;
}

void Salesman::display(){
}

void Salesman::stats(std::string algo){
	std::cout << "--------------------------" << std::endl;
	std::cout << "Algorithm: " << algo << std::endl;
	std::cout << "Path: ";
	for(int i = 0; i < path->size() - 1; i++){
		std:: cout << path->at(i) << " -> ";
	}
	std::cout<< path->at(path->size() - 1) << std::endl;
	std::cout << std::endl << "Search Time: " << time.count() << " miliseconds"<< std::endl;
	std::cout << "--------------------------" << std::endl;
}

void Salesman::select(int salesmanAlgo){
	switch(salesmanAlgo){
		case NAIVE:
			algoPointer = &Naive::naive;
			break;
		case DYNAMIC:
			algoPointer = &Dynamic::memoization;
			break;
	}
}

void Salesman::save(std::string filePath){
	FileWriter* fw = new FileWriter(filePath);
	fw->writeCsv(std::to_string(time.count()));
	delete fw;
}

void Salesman::configure(int num){
	if(num > 0 && num <= numNodes){
		nodeCount = num;
	}
}