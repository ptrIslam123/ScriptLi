#ifndef _STD_FILE_OUTPUT_STREAM_H_
#define _STD_FILE_OUTPUT_STREAM_H_

#include <fstream>
#include <string>
#include "fileOutputStream.h"

class STDFileOutputStream : public FileOutputStream
{
public:
	STDFileOutputStream(const std::string&, bool append = false);
	STDFileOutputStream(std::string&&, bool append = false);
	~STDFileOutputStream();

	virtual void write(const std::string&) override;
	virtual void write(std::string&&) override;
	virtual bool isExists() override;
	virtual void createfile() override;

private:
	std::string fileName_;
	std::ofstream fOutStream_;
	bool append_;
};

#endif // !_STD_FILE_OUTPUT_STREAM_H_
