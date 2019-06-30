#include "stdafx.h"
#include "NodoLocal.h"



Compiler::NodoLocal::NodoLocal(string Line, string Name, string Type, SYMBOL_CAT Category, int Dimension, string Function, void* Value, NodoLocal* NextNode)
{
	Line = m_line;
	Name = m_name;
	Type = m_type;
	Category = m_cat;
	Dimension = m_dim;
	Function = m_func;
	Value = m_val;
	NextNode = m_next;
}

void Compiler::NodoLocal::GetLocalNode(string Line, string Name, string Type, SYMBOL_CAT Category, int Dimension, string Function, void* Value, NodoLocal* NextNode)//  SYMBOL_CAT Category, string Type, int Dimension, void* Value, string Function, NodoLocal* NextNode)
{
	Line	  = m_line ;
	Name	  = m_name ;
	Type	  = m_type ;
	Category  = m_cat  ;
	Dimension = m_dim  ;
	Function  = m_func ;
	Value	  = m_val  ;
	NextNode  = m_next ;
}
