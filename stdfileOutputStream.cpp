#include <iostream>
#include "stdfileOutputStream.h"

#define FILE_NOT_FOUND_EXCEPTION std::cout << "Error: file not found\n"

STDFileOutputStream::STDFileOutputStream(const std::string& fileName, bool append)
	:fileName_(fileName), append_(append)
{}

STDFileOutputStream::STDFileOutputStream(std::string&& fileName, bool append)
	:fileName_(std::move(fileName)), append_(append)
{}

STDFileOutputStream::~STDFileOutputStream()
{
	fOutStream_.close();
}

void STDFileOutputStream::write(const std::string& data)
{
	if (!isExists())
	{
		FILE_NOT_FOUND_EXCEPTION;
	}
	else
	{
		fOutStream_ << data;
	}

}

void STDFileOutputStream::write(std::string&& data)
{
	if (!isExists())
	{
		FILE_NOT_FOUND_EXCEPTION;
	}
	else
	{
		fOutStream_ << std::move(data);
	}
}

bool STDFileOutputStream::isExists()
{
	if (!fOutStream_.is_open())
		return false;
	return true;
}

void STDFileOutputStream::createfile()
{
	if (append_)
	{
		//////////
		fOutStream_.open(fileName_);
	}
	else
	{
		fOutStream_.open(fileName_);
	}
}
