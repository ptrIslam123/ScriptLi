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
#include "concrete_ast.h"


#include "node_ast.h"

#define FILE_NAME "script.txt"

std::unique_ptr<Container> createLex(const std::string&);
void fileOutputStream();
void fileInputStream();


int main()
{
	std::string data = "10 + 20";
	BaseAST::Container_ptr tokens = createLex(data);

	AST* baseAST = new BaseAST(std::move(tokens));

	baseAST->build();

	//baseAST->build();


	//std::unique_ptr<AST> baseAST =  makeAST(TypeAST::BASE_AST, std::move(tokens));	//erorr destruct


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