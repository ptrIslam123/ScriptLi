#include <iostream>
#include <fstream>

#include "lexer.h"

#include "test_token_type.h"

#include "fileOutputStream.h"
#include "fileInputStream.h"

#include "pasrer.h"
#include "ast.h"



#include "allocator.h"

#define FILE_NAME "main.txt"

std::unique_ptr<Container> createLex(const std::string&);
std::string fileInputStream();


class Widget
{
public:
	Widget(int x, short y)
	{
		x_ = x;
		y_ = y;
	}

	Widget() {}

	int getX() { return x_; }
	short getY() { return y_; }

private:
	int x_;
	short y_;
};


int main()
{

	std::string data = fileInputStream();
	
	auto tokens = getResult_of_the_Lexer(
		std::move(data),
		GrammarType::STD_GRAMMAR,
		ContainerType::List 
	);

	return 0;
}

std::string fileInputStream()
{
	std::string buffer;
	std::fstream file;
	file.open(FILE_NAME);
	char data;

	if (file.is_open())
	{
		while (file.get(data))
		{
			buffer += data;
		}
		return buffer;
	}
	else
	{
		return "error: file not found!";
	}

	
}

std::unique_ptr<Container> createLex(const std::string& data)
{
	return nullptr;
}