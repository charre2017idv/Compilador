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
		map<string, string> m_MapTokens;
	public:
		vector<string> m_tokenGroup;
		string m_parsedSrcCode;

		Token();
		//Token(string line, string lex, string type);
		void getToken(string line, string lex, string type);
		string parsedTokens();
		//~Token();
		string getLex() const;
		//TOKEN_TYPE getType() const;
		//int getLineNum() const;
	};
}

