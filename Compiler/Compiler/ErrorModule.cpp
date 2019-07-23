#include "stdafx.h"
#include "ErrorModule.h"

Compiler::ErrorModule::ErrorModule()
{
	m_numErrors = 0;
	m_errorsArray = gcnew cli::array<String^>(MAX_ERRORS);
	for (int i = 0; i < MAX_ERRORS; i++)
	{
		m_errorsArray[i] = gcnew String(" ");
	}
}

void Compiler::ErrorModule::clearErrors()
{
}

bool Compiler::ErrorModule::addError(ERROR_PHASE phase, int lineNumber, String ^ errorDesc, String ^ errorLine)
{
	if (m_numErrors < (MAX_ERRORS - 1))
	{
		m_errorsArray->SetValue(String::Format("{0}:{1}{2}{3}", phase.ToString() , "\t" + lineNumber, "\t" + errorDesc + "\t", errorLine), m_numErrors);
		m_numErrors++;
		return true;
	}

	return false;
}
