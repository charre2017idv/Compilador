#pragma once

#include "SyntaxState.h"
#include "LexAnalyzer.h"
#include "SyntaxAnalysis.h"
#include "NodoLocal.h"
namespace Compiler {
	class SyntaxState_Var 
	{
	public:
		SyntaxState_Var();
		LexAnalyzer *lexem;
		
		vector <NodoLocal> m_LocalNodes;
		void checkSyntax(string);
	};
}