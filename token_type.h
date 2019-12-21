#ifndef _TOKEN_TYPE_H_
#define _TOKEN_TYPE_H_

enum class TokenType
{
	UNDEFINE,

	/* type system */
	NUMBER_INT,
	NUMBER_DOUBLE,
	TEXT,
	CHAR,
	BOOL,

	/* key words */
	WORD,
	PRINTLN,
	SCANNER,
	STRUCT,

	NODE,



	/* operators */
	ADD,		// +
	SUB,		// -
	MULT,		// *
	DIV,		// /
	
	LQ,		// (
	RQ,		// )

	POINT,		// .
	COMMA,		// ,

	/* logical operators*/
	EQULLY,		// =
	MORE,		// >
	LESS,		// <
	MORE_EQ,	// >=
	LESS_EQ,	// <=
	EQ,			// ==
	BUT,		// !
	NO_EQ,		// !=
	AND,		// &&
	OR,			// ||


	/* Contecst fruently grammar */
	STMT,
	EXPR,
	TERM,
	FACT,


	EOI
};


#endif // !1