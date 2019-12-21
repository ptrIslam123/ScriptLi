#include <iostream>
#include "fileOutputStream.h"
#include "stdfileOutputStream.h"

#define ERROR_FILE_STREAM_TYPE std::cout << "\nUNDEFINED_FILE_IO_STREAM_TYPE\n"

using FileOut_t = FileIOStreamType;

FileOutputStream* makeFileOutputStream(const std::string& fileName, FileOut_t&& foStream_t)
{
	switch (foStream_t)
	{
	case FileOut_t::STDFileOutputSTREAM: return new STDFileOutputStream(fileName);

		default : 
			ERROR_FILE_STREAM_TYPE;
	}
	return nullptr;
}

FileOutputStream* makeFileOutputStream(std::string&& fileName, FileOut_t&& foStream_t)
{
	switch (foStream_t)
	{
	case FileOut_t::STDFileOutputSTREAM: return new STDFileOutputStream(std::move(fileName));

	default:
		ERROR_FILE_STREAM_TYPE;
	}
	return nullptr;
}
