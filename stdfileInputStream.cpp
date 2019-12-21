#include <iostream>
#include "stdfileInputStream.h"

#define FILE_NOT_FOUND_EXCEPTION std::cout << "Error: file not found\n"

STDFileInputStream::STDFileInputStream(const std::string& fileName)
	:fileName_(fileName)
{
	fInStream_.open(fileName_);
}

STDFileInputStream::STDFileInputStream(std::string&&)
	:fileName_(std::move(fileName_))
{
	fInStream_.open(fileName_);
}

STDFileInputStream::~STDFileInputStream()
{
	fInStream_.close();
}

std::string STDFileInputStream::read()
{
	if (!isExists())
	{
		FILE_NOT_FOUND_EXCEPTION;
	}
	std::string buffer;
	char data;
	while (fInStream_.get(data))
	{
		buffer += data;
	}
	return buffer;
}

bool STDFileInputStream::isExists()
{
	if (!fInStream_.is_open())
		return false;
	return true;
}
