#ifndef _FILE_INPUT_STREAM_H_
#define _FILE_INPUT_STREAM_H_

#include <string>
#include "FileIOStreamType.h"

class FileInputStream
{
public:
	virtual std::string read() = 0;
	virtual bool isExists() = 0;
};

using FileIn_t = FileIOStreamType;

FileInputStream* makeFileInputStream(const std::string&, FileIn_t&&);
FileInputStream* makeFileInputStream(std::string&&, FileIn_t&&);

#endif // !_FILE_INPUT_STREAM_H_
