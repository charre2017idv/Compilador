#pragma once
#include "ErrorModule.h"
#include "LexAnalyzer.h"
#include "TabSymbol.h"


namespace Compiler {
	class SyntaxAnalysis
	{
	private:
		LexAnalyzer * Lex;
		msclr::gcroot<ErrorModule^> Err;
		TabSymbol * Tab;
	public:
		NL m_tempNodes;
		string m_parsedNode;
	public:
		SyntaxAnalysis(LexAnalyzer * lex, ErrorModule ^err, TabSymbol * tab);
		void checkSyntax();
	};


}
