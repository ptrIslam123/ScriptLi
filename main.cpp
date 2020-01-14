#include <iostream>
#include <fstream>

#include "lexer.h"

#include "test_token_type.h"

#include "fileOutputStream.h"
#include "fileInputStream.h"

#include "pasrer.h"
#include "ast.h"


#include "singletonh.h"
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
	Widget()
		:x_(0),y_(0)
	{}

	void setX(int x) { x_ = x;  }
	void setY(int y) { y_ = y;  }

	int getX() { return x_; }
	int getY() { return y_; }

private:
	int x_;
	int y_;
};
auto factoryM = [](const TokenType&)
{
	return new Widget();
};


int main()
{

	/*std::string data = fileInputStream();
	
	auto container = makeContainer(ContainerType::List,0);
	auto lexical = makeLexicalGrammar(GrammarType::STD_GRAMMAR, data);

	Lexer lexer(data, lexical, container);
	lexer.run();

	auto tokens = lexer.getTokens();*/

	Singleton<Widget,TokenType, decltype(factoryM)> r(factoryM);

	Widget*  w1 = r.getBeen(TokenType::ADD);
	w1->setX(1010);
	w1->setY(2020);

	printf("w1 = {x1 = %d, y= %d}\n", w1->getX(), w1->getY());


	Widget* w2 = r.getBeen(TokenType::MULT);
	printf("w2 = {x1 = %d, y= %d}\n", w2->getX(), w2->getY());
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