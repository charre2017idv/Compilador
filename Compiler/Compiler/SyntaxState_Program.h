#pragma once
#include "SyntaxState.h"
#include "LexAnalyzer.h"
#include "SyntaxAnalysis.h"
#include "NodoLocal.h"

namespace Compiler {
	class SyntaxState_Program: public SyntaxState
	{
	public:
		SyntaxState_Program
    (
      LexAnalyzer * lex, 
      SyntaxAnalysis * syn, 
      SyntaxState * parent, 
      string stateName
    );
		LexAnalyzer *lexem;

		int m_state = 0;
		vector<NodoLocal> m_NodosLocales;
		vector<string> m_Temp_NodosLocales;
		vector<string> m_simbols;
		NL NODO;

		string m_parsedNode;

    string l_token;
    string l_str;
    int Curtok = 0;
    bool isFunction = false;
  public:
		void 
    checkSyntax();
    void 
    varState(int i);
    void
    readStringToken(int index,int state);
    void
    AllocateSymbol(string line, string name, string type, SYMBOL_CAT category, string dimToken, int i, bool isFunc);

    void 
    CheckParameter(int i); // EXP LOG
    void
    CheckStatmentblock(int i);
	};
}


