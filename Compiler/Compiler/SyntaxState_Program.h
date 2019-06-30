#pragma once
#include "SyntaxState.h"
#include "LexAnalyzer.h"
#include "SyntaxAnalysis.h"
#include "NodoLocal.h"

namespace Compiler {
	class SyntaxState_Program: public SyntaxState
	{
	public:
		SyntaxState_Program(LexAnalyzer * lex, SyntaxAnalysis * syn, SyntaxState * parent, string stateName);
		LexAnalyzer *lexem;

		int m_state = 0;
		vector<NodoLocal> m_NodosLocales;
		vector<string> m_Temp_NodosLocales;
		vector<string> m_simbols;
		NL NODOLOCAL;

		string m_parsedNode;
		void checkSyntax();
	};
}


