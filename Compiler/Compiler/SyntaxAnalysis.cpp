#include "stdafx.h"
#include "SyntaxAnalysis.h"
#include "SyntaxState_Program.h"

Compiler::SyntaxAnalysis::SyntaxAnalysis(LexAnalyzer * lex, ErrorModule ^err, TabSymbol * tab)
{
	Lex = lex;
	Err = err;
	Tab = tab;
}

void Compiler::SyntaxAnalysis::checkSyntax()
{
	SyntaxState_Program *Prog= new SyntaxState_Program(Lex,this,nullptr,"<PROGRAM>");
	Prog->checkSyntax();
	m_tempNodes = Prog->NODOLOCAL;
	vector <string> m_Temp_NodosLocales;
	for (size_t i = 0; i < m_tempNodes.Line.size(); i++)
	{
		string l_category;
		string l_NextNode;
		if (m_tempNodes.Category[i] == LOCAL_VAR)
		{
			l_category = "LOCAL_VAR";
		}
		if (m_tempNodes.Category[i] == GLOBAL_VAR)
		{
			l_category = "GLOBAL_VAR";
		}

		string temp = m_tempNodes.Line[i] + "@" + m_tempNodes.Name[i] +
			"@" + m_tempNodes.Type[i] + "@" + l_category +
			"@" + "0" + "@" + m_tempNodes.Function[i] + "@" + "<GLOBAL SCOPE>" + "@";

		m_Temp_NodosLocales.push_back(temp);
	}
	for (size_t i = 0; i < m_Temp_NodosLocales.size(); i++)
	{
		m_parsedNode += m_Temp_NodosLocales[i];
	}
	string parse = m_parsedNode;
	/* Crear el estado inicial <PROGRAMA> y llamar checkSyntax de ese estado "var" */
}
