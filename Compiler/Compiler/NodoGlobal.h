#pragma once
#include "Header.h"
#include "NodoLocal.h"
namespace Compiler {
	class NodoGlobal
	{
	private:
		string m_symbol;
		SYMBOL_CAT m_cat;
		string m_type;
		int m_dim;
		void * m_val;
		NodoLocal * m_nodoLocal;
	public:
		NodoGlobal();
		// Get
		void GetGlobalNode();
		// Set
		void SetGlobalNode();
	};

};