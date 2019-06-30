#pragma once
#include "Header.h"
#include "NodoGlobal.h"
namespace Compiler {
	class TabSymbol
	{
		
	private:
		map<string, NodoGlobal*> m_symbols;

	public:
		TabSymbol();
		bool addSymbol(string sym, int dim, SYMBOL_CAT cat, string func, string tp);
		bool symbolExists(string sym, SYMBOL_CAT cat, string func);
	};
}


