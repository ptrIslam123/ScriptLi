#include "file_stream.h"

FileStream::FileStream(const std::string& fileName)
	:fileName_(fileName)
{}


FileStream::FileStream(std::string&& fileName)
	:fileName_(std::move(fileName))
{}

bool FileStream::createfile()
{
	foutStream_.open(fileName_);
	foutStream_ << "";
	return true;
}
