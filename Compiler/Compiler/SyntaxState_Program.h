#pragma once
#include "SyntaxState.h"
#include "LexAnalyzer.h"
#include "SyntaxAnalysis.h"
#include "NodoLocal.h"
#define CompareToken(Vec,token, delemiter_A, delemiter_B, indind, condition, tempFunc, Cat) \
   if (count(Vec.begin(), Vec.end(), token))\
   {\
   }\
   else\
     AllocateSymbol(Lex->m_tokens.line[indind], token,delemiter_A, Cat, delemiter_B, indind, condition, tempFunc);
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
    checkState(string delimiter_A, string delimiter_B, int i, bool isVar, bool isFunc, bool isMain, bool isParam, bool isStmblock);
    void 
    VARIABLE(int i);
    void
    FUNC(int i);
    void
      mainState(int i);
    void
      readStringToken(int index, int state);
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
    PARAM(int i); // EXP LOG
    void
    STATEMENT_BLOCK(int i);
    void 
    CheckforErrors(NL node, string currentSymbol, SYMBOL_CAT category);
    void IF(int i, SYMBOL_CAT category);
    void FOR(int i);
    void WHILE(int i);
    void SWITCH(int i);
    void PRINT(int i);
    void READ(int i);
    void RETURN(int i);
	};
}


