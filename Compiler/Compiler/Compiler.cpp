#include "stdafx.h"
#include "ErrorModule.h"
#include "Compiler.h"

// <! Warning : Github - Branch 'Development'>

Compiler::Manager::Manager()
{
	err = gcnew ErrorModule;
	lex = new LexAnalyzer(err);
	SymbolTable = new TabSymbol;
	SemanticAnalisis = new SemanticAnalysis;
	SyntaxAnalisis = new SyntaxAnalysis(lex,err,SymbolTable); // Add the point of SemanticAnalisis
}

Compiler::Manager::~Manager()
{
	// Delete lex analysis
	if (lex!=nullptr)
	{
		delete lex;
		lex = nullptr;
	}
	// Delete Symbol Table
	if (SymbolTable != nullptr)
	{
		delete SymbolTable;
		SymbolTable = nullptr;
	}
	// Delete SyntaxAnalisis
	if (SyntaxAnalisis != nullptr)
	{
		delete SyntaxAnalisis;
		SyntaxAnalisis = nullptr;
	}
	// Delete SemanticAnalisis
	if (SemanticAnalisis != nullptr)
	{
		delete SemanticAnalisis;
		SemanticAnalisis = nullptr;
	}
}

void Compiler::Manager::lexAnalysis(String ^ srcCode)
{
	if (lex !=nullptr)
	{
		lex->parseSourceCode((const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(srcCode).ToPointer());
	}
}

void Compiler::Manager::checkSyntax()
{
	if (SyntaxAnalisis != nullptr)
	{
		SyntaxAnalisis->checkSyntax();
	}
}

cli::array<String^>^ Compiler::Manager::compileProgram(String ^ srcCode)
{
	// analyze the srcCode
	lexAnalysis(srcCode);
	// Analysis syntactic
	checkSyntax();
	/* Reserve Memory */
	int arrSize = lex->m_tokens.Lexem.size();
	compilationDetails = gcnew cli::array<String^>(arrSize);

	for (size_t i = 0; i < err->m_errorsArray->Length; i++)						            // Concatenate in strings the group of line, lexem and type of errors
	{ 
		m_errorString += err->m_errorsArray[i] + "\r\n";
	}
	
	//string temp = lex->m_parsedSrcCode;
	//string str;
	//vector <string> temp_Words;
	//for (int i = 0; i < temp.size(); i++)
	//{
	//	if (temp[i] != '@')
	//	{
	//		str += temp[i];
	//	}
	//	if (temp[i + 1] == '@')
	//	{
	//		str = "";
	//		i++;
	//	}
	//	if (temp[i] == '\n')
	//	{
	//		i++;
	//	}
	//}
	
	// Cast lexem string to tokenized String
	TokenaizedSTR = gcnew String(lex->parsedTokens().c_str());
	SymbolsSTR = gcnew String(SyntaxAnalisis->m_parsedNode.c_str());

	// Sending the information to the UI
	compilationDetails[0] = gcnew String("___CompileOK___");
	compilationDetails[1] = gcnew String(TokenaizedSTR);
	compilationDetails[2] = gcnew String(m_errorString);
	compilationDetails[3] = gcnew String(SymbolsSTR);
	// Clean Up
	lex->clearTokens();
	err->clearErrors();

	return compilationDetails;
	// TODO: insert return statement here
}
