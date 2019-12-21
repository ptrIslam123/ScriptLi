#include <iostream>
#include "fileInputStream.h"
#include "stdfileInputStream.h"

#define ERROR_FILE_STREAM_TYPE std::cout << "\nUNDEFINED_FILE_IO_STREAM_TYPE\n"

using FileIn_t = FileIOStreamType;

FileInputStream* makeFileInputStream(const std::string& fileName, FileIn_t&& foStream_t)
{
	switch (foStream_t)
	{
	case FileIn_t::STDFileInputSTREAM: return new STDFileInputStream(fileName);

	default :
		ERROR_FILE_STREAM_TYPE;
	}
	return nullptr;
}

FileInputStream* makeFileInputStream(std::string&& fileName, FileIn_t&& foStream_t)
{
	switch (foStream_t)
	{
	case FileIn_t::STDFileInputSTREAM: return new STDFileInputStream(std::move(fileName));

	default:
		ERROR_FILE_STREAM_TYPE;
	}
	return nullptr;
}
