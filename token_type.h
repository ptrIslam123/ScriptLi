#ifndef _TOKEN_TYPE_H_
#define _TOKEN_TYPE_H_

enum class TokenType
{
	/* type system */
	NUMBER_INT,
	NUMBER_DOUBLE,
	TEXT,
	CHAR,

	/* key words */
	WORD,
	NODE,

	POINT,
	COMMA,
	EQULLY,



	/* operators */
	ADD,		// +
	SUB,		// -
	MULT,		// *
	DIV,		// /
	
	LQ,		// (
	RQ,		// )


	EOI
};


#endif // !1