#pragma once
#define MAX_ERRORS 30
#include "windows.h"
using namespace System;

namespace Compiler {
	public enum class ERROR_PHASE
	{
		GLOBAL,
		LEX_ANALYZER,
		SYN_ANALYZER,
		SEM_ANALYZER,
		CODE_GENERATION
	};
	public ref class ErrorModule
	{
	private:
		int m_numErrors;
	public:
		ErrorModule();
		cli::array<String^>^m_errorsArray;
		ERROR_PHASE lexError = ERROR_PHASE::LEX_ANALYZER;
		//~ErrorModule();
	public:
		void clearErrors(); //  debe de estar en todas las clases
		bool addError(ERROR_PHASE phase, int lineNumber, String^errorDesc, String^ errorLine); // "LEXICO, line 3, Caracter Invalido, 'var = @'"
		cli::array<String^>^getErrors()
		{
			return m_errorsArray;
		}
	};
}