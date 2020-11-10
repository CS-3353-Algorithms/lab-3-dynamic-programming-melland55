#include "TravelingSalesman.h"
#include "FileWriter.h"

using namespace std;

int main(int argc, char* argv[])
{
	//file path for the graph and output
	string graph = "../Data/positions.txt";
	string data = "../Data/output.csv";

	//Creates an Algorithm pointer of type Salesman
	Algorithm *traveller = new Salesman();
	
	traveller->load(graph);
	traveller->display();
	bool nDone, dDone = false;

	//Adds column names to outpur csv
	FileWriter* fw = new FileWriter(data);
	fw->clear(data);
	fw->writeLine("Number of Nodes, Naive(ms), Dynamic(ms)");
	delete fw;
	//Loops through each algorithm increasing numNodes each time
	for(int i = 4; i <= 24; i++){
		FileWriter* fwa = new FileWriter(data);
		fwa->write(std::to_string(i));
		delete fwa;
		for(int k = Algorithm::NAIVE; k < Algorithm::END; k++){
			string algo;
			switch(k){
				case 0:
					algo = "Naive";
					break;
				default:
					algo = "Dynamic";
					break;
			}
			//Stops using Naive algorithm when number of nodes exceeds 12
			if(!(i > 12 && k == 0)){
				traveller->select(k);
				traveller->configure(i);
				traveller->execute();
				traveller->stats(algo);
				traveller->save(data);
			}else{
				//Adds empty value to csv
				FileWriter* fwc = new FileWriter(data);
				fwc->writeCsv("");
				delete fwc;
			}
		}
		//Adds a newline to csv
		FileWriter* fwb = new FileWriter(data);
		fwb->writeLine("");
		delete fwb;
	}
	while(true){

	}
    return 0;
}
