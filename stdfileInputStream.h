#ifndef _STD_FILE_INPUT_STREAM_H_
#define _STD_FILE_INPUT_STREAM_H_

#include <fstream>
#include <string>
#include "fileInputStream.h"

class STDFileInputStream : public FileInputStream
{
public:
	STDFileInputStream(const std::string&);
	STDFileInputStream(std::string&&);
	~STDFileInputStream();
	
	virtual std::string read() override;
	virtual bool isExists() override;

private:
	std::string fileName_;
	std::ifstream fInStream_;
};

#endif // !_STD_FILE_INPUT_STREAM_H_
