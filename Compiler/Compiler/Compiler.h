#pragma once
#include "ErrorModule.h"
#include "LexAnalyzer.h"
#include "Token.h"
using namespace System;

namespace Compiler {
	public ref class Manager
	{ 
		// TODO: Add your methods for this class here.
	private:
		void lexAnalysis(String^srcCode);
		
	public:
		Manager();
		~Manager();
		ErrorModule ^err;
		Token *Tok;
		LexAnalyzer *lex = nullptr;

		cli::array<String^>^compilationDetails;
		String^ TokenaizedSTR;
		String^ ErrorSTR;

	public:

		cli::array<String^> ^compileProgram(String^srcCode);
	};
};
