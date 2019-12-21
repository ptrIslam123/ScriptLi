#ifndef _FILE_STREAM_H_
#define _FILE_STREAM_H_

#include <iostream>
#include <string>
#include <fstream>


class FileStream
{
public:
	FileStream(const std::string&);
	FileStream(std::string&&);

	bool createfile();

private:
	std::string fileName_;
	std::ofstream foutStream_;
};

#endif // !_FILE_STREAM_H_
