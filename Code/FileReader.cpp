#include "FileReader.h"

//Opens the fileName with in stream
FileReader::FileReader(std::string fileName){
	ifs.open(fileName);
}

//Destructor closes the opened file
FileReader::~FileReader(){
	ifs.close();
}

//Resets the pointer of the in stream to the beggining fo the file
void FileReader::reset(){
	ifs.clear();
	ifs.seekg(0);
}

//Closes the current file and opens a new file
void FileReader::open(std::string fileName){
	ifs.close();
	ifs.open(fileName);
}

//Returns true if in stream is at the end of file
bool FileReader::eof(){
	return ifs.eof();
}

//Returns the next line in the file as a string
std::string FileReader::nextLine(){
	std::string line;
	getline(ifs, line);
	return line;
}

//Returns the next line in the csv file as a vector of strings for each comma seperated value
std::vector<std::string>* FileReader::csvNextLine(){
	std::vector<std::string>* csv = new std::vector<std::string>();
	std::string line;
	//Reads the next line into string line and loops through each comma seperated value and adds it to return vector csv until line has no more values
	getline(ifs, line);
	while(line.find(',') != -1){
		//Gets next comma seperated value and stores it into return vector csv while removing it from line
		std::string temp = line.substr(0, line.find(','));
		line = line.substr(line.find(',') + 1);
		csv->push_back(temp);
	}
	std::string temp = line.substr(0, line.find(","));
	csv->push_back(temp);
	return csv;
}

//Returns the number of lines in the file
int FileReader::getFileSize(){
	int i = 0;
	std::string temp;
	//Loops through each line in the file and incriments counter i
	while(!ifs.eof()){
		i++;
		getline(ifs, temp);
	}
	return i;
}