#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>

#include "token.h"
#include "lexical_grammar.h"
#include "container.h"
#include "lexer.h"

#include "test_token_type.h"

#include "fileOutputStream.h"
#include "fileInputStream.h"

#include "pasrer.h"
#include "ast.h"

#include "expression_ast.h"
#include "declare_statement.h"

#include "node_ast.h"

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

	int getX() { return x_; }
	short getY() { return y_; }

private:
	int x_;
	short y_;
};


int main()
{
	

	std::string data = fileInputStream();
	
	auto tokens = createLex(data);

//	test_show_tokens(tokens.get());

	Parser parser(tokens.get());

	parser.run();

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
	auto lexical = makeLexicalGrammar(GrammarType::STD_GRAMMAR, data);
	Container* container = makeContainer(ContainerType::List, 0);


	Lexer lexer(data, lexical, container);

	lexer.run();

	return lexer.getTokens();
}