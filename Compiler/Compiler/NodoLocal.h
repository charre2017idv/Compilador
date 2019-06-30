#pragma once
#include "Header.h"
namespace Compiler {
	class NodoLocal
	{
	private:

	public:
		string		m_line;
		string		m_name;
		SYMBOL_CAT	m_cat ;
		int			m_dim ;
		string		m_type;
		string		m_func;
		NodoLocal * m_next;
		void *		m_val ;
		
	public:
		NodoLocal(string Line, string Name, string Type, SYMBOL_CAT Category, int Dimension, string Function, void* Value, NodoLocal* NextNode);

		void GetLocalNode(string Line, string Name, string Type, SYMBOL_CAT Category, int Dimension, string Function, void* Value, NodoLocal* NextNode);
		//void SetLocalNode();
	};
};

