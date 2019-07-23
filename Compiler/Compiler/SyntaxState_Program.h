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
		//vector<NodoLocal> m_NodosLocales;
		//vector<string> m_Temp_NodosLocales;
		vector<string> m_simbols;
		NL NODO;

		string m_parsedNode;
    string m_tempInFunc = "<GLOBAL SCOPE>";
    int m_currIndex;

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
    functionState(int i);
    void
    mainState(int i);
    void
    readStringToken(int index,int state);
    void
    AllocateSymbol
    (
      string line, 
      string name, 
      string type, 
      SYMBOL_CAT category, 
      string dimToken, 
      int i, 
      bool isFunc,
      string inFunction
    );
    void 
    Check_EXP_LOG(int i); // EXP LOG
    void
    CheckStatmentblock(int i);
    void 
    CheckforErrors(NL node, string currentSymbol, SYMBOL_CAT category);

	};
}


