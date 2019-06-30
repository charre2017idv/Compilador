#pragma once
#include "ErrorModule.h"
#include "LexAnalyzer.h"
// Analisis Sintactico
#include "TabSymbol.h"
#include "SemanticAnalysis.h"
#include "SyntaxAnalysis.h"

#include "Token.h"


using namespace System;

namespace Compiler {
	public ref class Manager
	{ 
		// TODO: Add your methods for this class here.
	private:
		void lexAnalysis(String^srcCode);
		void checkSyntax();
	public:
		Manager();
		~Manager();
		ErrorModule ^err;
		Token *Tok = nullptr;
		LexAnalyzer *lex = nullptr;
		// Analisis Sintactico
		TabSymbol			*SymbolTable	 = nullptr;
		SyntaxAnalysis		*SyntaxAnalisis	 = nullptr;
		SemanticAnalysis	*SemanticAnalisis = nullptr;
		

		cli::array<String^>^compilationDetails;
		String^ TokenaizedSTR;
		String^ SymbolsSTR;
		String^ ErrorSTR;
		String^ m_errorString;
	public:

		cli::array<String^> ^compileProgram(String^srcCode);
	};
};
