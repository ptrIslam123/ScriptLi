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
	PRINT,
	SCANNER,
	STRUCT,

	WHILE,
	IF,
	ELSE,
	RET,

	NODE,



	/* operators */
	ADD,		// +
	SUB,		// -
	MULT,		// *
	DIV,		// /
	
	LQ,			// (
	RQ,			// )
	SHAPE_LQ,	// {
	SHAPE_RQ,	// }
	L_SQUARE,	// [
	R_SQUARE,	// ]

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
	ACCESS_ELEMENT,	// []
	DEC, // declare
	DEF,	// define
	LVALUE,
	RVALUE,
	CALL,

	PARAMS_LIST,
	FIELDS_LIST,
	STMT_LIST,
	INIT_LIST,
	ARGS_LIST,

	LOG_EXPR,
	BIN_EXPR,
	COND_EXPR,
	TERM,
	FACT,
	ID,
	MATCHER,


	EOI
};


#endif // !1