#pragma once
#include "Header.h"
using namespace System;
namespace Compiler {
	enum TOKEN_TYPE
	{
		UNDEFINED = 0,
		ID,
		INT,
		FLOAT
	};
	class Token
	{
	private:
		int m_lineNumber;
		string m_Lex;
		TOKEN_TYPE m_Type;
	public:
		Token(string lex, TOKEN_TYPE tp, int linNum);
		~Token();
		string getLex() const;
		TOKEN_TYPE getType() const;
		int getLineNum() const;
	};
}

