#include "stdafx.h"
#include "TabSymbol.h"


Compiler::TabSymbol::TabSymbol()
{
}

bool Compiler::TabSymbol::addSymbol(string sym, int dim, SYMBOL_CAT cat, string func, string tp)
{
	if (!symbolExists(sym,cat,func))
	{
		if (cat == SYMBOL_CAT::GLOBAL_VAR)
		{
			// Verify that does not exist as function (call symbol Exist as specific word)
			// error
		}
		if (cat == SYMBOL_CAT::FUNCTION)
		{
			// Verify that does not exist as globla var
			// error
		}
		if (cat == SYMBOL_CAT::LOCAL_VAR)
		{
			// Verify that does not exist as parameter of the same function and named as function
			// error
		}
		if (cat == SYMBOL_CAT::PARAMETER)
		{
			// Verify that does not exist as local var and not named as function
			// error
		}

	}
	else
	{
		// Add error (Symbol Already defined)
	}
	return false;
}

bool Compiler::TabSymbol::symbolExists(string sym, SYMBOL_CAT cat, string func)
{
	return false;
}
