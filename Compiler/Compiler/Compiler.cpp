#include "stdafx.h"
#include "ErrorModule.h"
#include "Compiler.h"



Compiler::Manager::Manager()
{
	err = gcnew ErrorModule;
	lex = new LexAnalyzer(err);
}

Compiler::Manager::~Manager()
{
	if (lex!=nullptr)
	{
		delete lex;
		lex = nullptr;
	}
}

void Compiler::Manager::lexAnalysis(String ^ srcCode)
{
	if (lex !=nullptr)
	{
		lex->parseSourceCode((const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(srcCode).ToPointer());
	}
}

cli::array<String^>^ Compiler::Manager::compileProgram(String ^ srcCode)
{
	
	// Analize the srcCode
	lexAnalysis(srcCode);
	/* Reserve Memory */
	int arrSize = lex->m_tokens.Lexem.size();
	compilationDetails = gcnew cli::array<String^>(arrSize);

	// Analyze Errors
	// 1)  Buscar en el indice en busca de error, si no lohay acumular su entrada para comprobar que hay datos corrector
	// 2) Si hay errores agregarlos por medio de la clase error al modulo de erres y acumular los mismos
	// 3) Obener los errores y concatenarlos, posteriormente llamar al resultado en el output del formulario
	

	int line = 0;
	String^ out_string;
	for (size_t i = 0; i < err->m_errorsArray->Length; i++)
	{
		// Concatenate in strings the group of line, lexem and type
		
		out_string += err->m_errorsArray[i] + "\r\n";
	}
	



	string temp = lex->m_parsedSrcCode;
	string str;
	vector <string> temp_Words;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != '@')
		{
			str += temp[i];
			//i++;
		}
		if (temp[i + 1] == '@')
		{

			//Words.Add(str);
			str = "";
			i++;
		}
		if (temp[i] == '\n')
		{
			i++;
		}
		if (temp_Words.size() == 3)
		{
			//String^ line = gcnew String(temp_Words[0].c_str());
			//int line = std::atoi(temp_Words[0].c_str());
			//String^ lexem = gcnew String(temp_Words[1].c_str());
			//err->addError(err->lexError, line, Error, lexem);
			//temp_Words.clear();
		}
	}

	// Cast string to String

	TokenaizedSTR = gcnew String(lex->m_parsedSrcCode.c_str());
	//ErrorSTR = gcnew String(err->getErrors()->ToString.c_str());
	// Sending the information to the UI
	compilationDetails[0] = gcnew String("___CompileOK___");
	compilationDetails[1] = gcnew String(TokenaizedSTR);
	compilationDetails[2] = gcnew String(out_string);
	lex->clearTokens();
	err->clearErrors();
	//parseSourceCode(srcCode);

	return compilationDetails;
	// TODO: insert return statement here
}
