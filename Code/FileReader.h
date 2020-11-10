#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <string>
#include <vector>

class FileReader
{
    public:
    	FileReader(std::string);
    	~FileReader();
		void reset();
		void open(std::string);
		bool eof();
		std::string nextLine();
		std::vector<std::string>* csvNextLine();
		int getFileSize();
    private:
    	std::ifstream ifs;
};

#endif