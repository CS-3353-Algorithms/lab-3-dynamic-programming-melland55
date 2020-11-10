#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include <fstream>
#include <string>
#include <vector>

class FileWriter
{
    public:
    	FileWriter(std::string);
    	~FileWriter();
		void open(std::string);
		void clear(std::string);
		void write(std::string);
		void writeLine(std::string);
		void writeCsv(std::string);
		void writeCsvLine(std::vector<std::string>);
    private:
    	std::ofstream ofs;
};

#endif