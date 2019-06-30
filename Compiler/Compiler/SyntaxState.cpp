#include "stdafx.h"
#include "SyntaxState.h"


Compiler::SyntaxState::SyntaxState(LexAnalyzer * lex, SyntaxAnalysis * syn, SyntaxState * parent, string stateName)
{
	Lex = lex;
	Syn = syn;
	Parent = parent;
	m_stateName = stateName;
}

void Compiler::SyntaxState::checkSyntax()
{
}
