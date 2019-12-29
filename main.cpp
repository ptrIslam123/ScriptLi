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

#include "node_ast.h"

#include "allocator.h"

#define FILE_NAME "script.txt"

std::unique_ptr<Container> createLex(const std::string&);
void fileOutputStream();
void fileInputStream();


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
	std::string data = "10 > 2 + 1*3";

	Allocator<NodeAST> allocatorNodeAST;
	auto tokens_container = createLex(data);	// get tokens;

	AST* bin_expr = new Expression(std::move(tokens_container),  allocatorNodeAST);

	NodeAST* header = bin_expr->build();

	return 0;
}

void fileInputStream()
{
	std::string path = "file1.txt";
	FileInputStream* fInStream = makeFileInputStream(path, FileIOStreamType::STDFileInputSTREAM);

	std::cout << fInStream->isExists() << "\n";

	std::cout << fInStream->read() << "\n";
}

void fileOutputStream()
{
	std::string path = "file1.txt";
	FileOutputStream* foutStream = makeFileOutputStream(path, FileIOStreamType::STDFileInputSTREAM);

	if (!foutStream->isExists())
	{
		std::cout << "!create file: " << path << "\n";
		foutStream->createfile();
	}

	foutStream->write("test load data in file\n");

}

std::unique_ptr<Container> createLex(const std::string& data)
{
	auto lexical = makeLexicalGrammar(GrammarType::STD_GRAMMAR, data);
	Container* container = makeContainer(ContainerType::List, 0);


	Lexer lexer(data, lexical, container);

	lexer.run();

	return lexer.getTokens();
}