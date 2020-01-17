#include <iostream>
#include <fstream>

#include "lexer.h"

#include "test_token_type.h"

#include "fileOutputStream.h"
#include "fileInputStream.h"

#include "pasrer.h"
#include "ast.h"
#include "expression_ast.h"

#include "singletonh.h"
#include "allocator.h"

#define FILE_NAME "main.txt"

std::unique_ptr<Container> createLex(const std::string&);
std::string fileInputStream();

#define print(val) std::cout << val << "\n"

class Widget
{
public:
	Widget(const std::string& id)
	{
		id_ = id;
	}
	Widget()
		:id_("")
	{}

	void set(const std::string& id)
	{
		id_ = id;
	}

	std::string get()
	{
		return id_;
	}
	

private:
	std::string id_;
};

auto getTokens = [](const std::string& data)
{
	auto container = makeContainer(ContainerType::List, 0);
	auto lexical = makeLexicalGrammar(GrammarType::STD_GRAMMAR, data);

	Lexer lexer(data, lexical, container);
	lexer.run();

	return lexer.getTokens();
};

int main()
{

	std::string data = fileInputStream();
	
	auto tokens = getTokens(data);
	test_show_tokens(tokens.get());
	Allocator<NodeAST> allocator;
	size_t position = 0;
	AST* test = makeASTunit(ASTClassType::ARGS_LIST, tokens.get(), allocator, position);
	//// ÊÀÆÅÒÜÑß ÌÀÒÜ ÅÃÎ ÐÀÁÎÒÀÅÒ ÏÐÈÄÓ ÏÐÎÂÅÐÜÞ!!!!!!!

	test->build();

	/*Expression* expr = (Expression*)test;

	std::cout << "res = " << expr->isId(TokenType::NUMBER_INT) << "\n";*/

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

