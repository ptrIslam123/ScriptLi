#ifndef _FILE_OUTPUT_STREAM_H_
#define _FILE_OUTPUT_STREAM_H_

#include <string>
#include "FileIOStreamType.h"

class FileOutputStream
{
public:
	virtual void write(const std::string&) = 0;
	virtual void write(std::string&&) = 0;
	virtual bool isExists() = 0;
	virtual void createfile() = 0;
};

using FileOut_t = FileIOStreamType;

FileOutputStream* makeFileOutputStream(const std::string&, FileOut_t&&);
FileOutputStream* makeFileOutputStream(std::string&&, FileOut_t&&);

#endif // !_file_outpur_stream_h_
