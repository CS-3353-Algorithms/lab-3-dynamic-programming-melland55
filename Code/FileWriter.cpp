#include "FileWriter.h"

//Opens the fileName with out stream and in append mode
FileWriter::FileWriter(std::string fileName){
	ofs.open(fileName, std::ios::app);
}

//Destructor closes the opened file
FileWriter::~FileWriter(){
	ofs.close();
}

//Closes the current file and opens a new file in append mode
void FileWriter::open(std::string fileName){
	ofs.close();
	ofs.open(fileName, std::ios::app);
}

//Deletes the contents of FileName by opening it not in append mode
void FileWriter::clear(std::string fileName){
	ofs.close();
	ofs.open(fileName);
}

//Writes a string to the file
void FileWriter::write(std::string str){
	ofs << str;
}

//Writes a string to the file as a line
void FileWriter::writeLine(std::string line){
	ofs << line << std::endl;
}

//Writes a string as a comma seperated value to file
void FileWriter::writeCsv(std::string csv){
    ofs << ", " << csv;
}

//Writes a vector of strings to the file as a line of comma seperated values
void FileWriter::writeCsvLine(std::vector<std::string> line){
    ofs << line.at(0);
    for(int i = 1; i < line.size(); i++){
        ofs << ", " << line.at(i);
    }
    ofs << std::endl;
}