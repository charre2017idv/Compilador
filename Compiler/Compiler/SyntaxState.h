#pragma once
#include "LexAnalyzer.h"
#include "SyntaxAnalysis.h"
#include "Header.h"
namespace Compiler {
	class SyntaxState
	{
	public: 
		LexAnalyzer		*Lex;
		SyntaxAnalysis	*Syn;
		SyntaxState		*Parent;
		string			 m_stateName;
	public:
		SyntaxState(LexAnalyzer * lex, SyntaxAnalysis * syn, SyntaxState * parent, string stateName);
		void checkSyntax();
	};
}

