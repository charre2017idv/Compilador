#include "stdafx.h"
#include "SyntaxState_Program.h"
#include "SyntaxState_Var.h"
#include "Token.h"


Compiler::SyntaxState_Program::SyntaxState_Program(LexAnalyzer * lex, SyntaxAnalysis * syn, SyntaxState * parent, string stateName) :
	SyntaxState(lex, syn, parent, stateName)
{

}

void Compiler::SyntaxState_Program::checkSyntax()
{
	bool isChecking;
	string prevToken;
	string CurrToken;
	string nextToken;
	int i = 0;
	
	while (isChecking)															// Enter to the loop that checks all the states
	{
		// State 0 
		if (m_state == 0)
		{
			if (i != 0)
				prevToken = Lex->m_tokens.Lexem[i - 1];							// Get the prevToken of the vector of tokens
			CurrToken = Lex->m_tokens.Lexem[i];									// Get the currToken of the vector of tokens
			nextToken = Lex->m_tokens.Lexem[i + 1];								// Get the nextToken of the vector of tokens
			
																				/* If the current token is equal to 'var' the condition 
																				change the state to save the variable in the vector of nodes. */
			if (!CurrToken.compare("var"))
			{
				m_state = 1;
			}
			
			if (!CurrToken.compare("function"))
			{
				m_state = 2;
			}
			i++;
		}

		// <! State Machine >
		// Allocate var tokens in nodes
		if (m_state == 1)
		{
			string l_token = Lex->LLT[i];										// Create a string that gets the token indexed 
			string l_str;														// It is a variable that allocates the parsed token

			for (int k = 0; k < l_token.size(); k++)							// <! Start the loop that analyze the token string >
			{
				if (l_token[k] != '@')											// If the indexed token is different from '@', it concatenates all the token
				{
					l_str += l_token[k];
				}
				if (l_token[k + 1] == '@')										// If the indexed token in the next position is equal to the '@',
				{																// it will allocate the tokens in a vector of 3 spaces
					m_simbols.push_back(l_str);
					l_str = "";
					k++;
				}
				if (m_simbols.size() == 3)										// if this vector is equal to 3, is necessary to push the token to the node
				{
					if (m_simbols[1] == ":" || m_simbols[1] == ";")				// if the vector has in the lexem position a ':' or ';', the loop brakes and change the state
					{
						//isChecking = false;
						i++;
						m_state = 0;
						break;
					}
					if (m_simbols[1] != "var" && m_simbols[1] != ","			
						&& m_simbols[1] != "[" && m_simbols[1] != "]" 
						&& m_simbols[1] != "1" && m_simbols[1] != "2" 
						&& m_simbols[1] != "3" && m_simbols[1] != "4" 
						&& m_simbols[1] != "5" && m_simbols[1] != "6" 
						&& m_simbols[1] != "7" && m_simbols[1] != "8" 
						&& m_simbols[1] != "9" && m_simbols[1] != ":")			// If the token isn't a reserved word, it will allocate the info in local node
					{  
						NODOLOCAL.Line.push_back(m_simbols[0]);					// Allocate the line of token
						NODOLOCAL.Name.push_back(m_simbols[1]);					// Allocate the variable 
						for (size_t j = i; j < Lex->m_tokens.Lexem.size(); j++) // Find the type of data of the variable
						{
						  string tipo;
						  if (Lex->m_tokens.Lexem[j] == ":")
						  {
						  	NODOLOCAL.Type.push_back(Lex->m_tokens.Lexem[j+1]); // Allocate the type of data
						  	break;												// if the data is allocated, the loop ends 
						  }
						}
						NODOLOCAL.Category.push_back(GLOBAL_VAR);				// Allocate the type of data // <! Warning : Change the structure to detect if it is local or global node>
						if (Lex->m_tokens.Lexem[i + 1] == "[")					// find the dimension of the variable // <! Warning : Also can detect '=' as dimension >
						{ // Dimension
							string tempdim = Lex->m_tokens.Lexem[i + 2];
							int Dim = stoi(tempdim);
							NODOLOCAL.Dimension.push_back(Dim);
						}
						else
						{
							NODOLOCAL.Dimension.push_back(0);
						}
						NODOLOCAL.Function.push_back("var");					// Allocate the function
						NODOLOCAL.Value.push_back(nullptr);						// Allocate the value, necessary for P3
						m_state = 1;
						m_simbols.clear();
						i++;
					}
					else
					{															// If the token is a reserved word, it will change the state and start search for a new word
						m_state = 1;
						m_simbols.clear();
						i++;
					}
				}
			}																	// <! End the loop that analyze the token string >
		}
		// Allocate function tokens in node
		if (m_state == 2)
		{
		//if (isChecking == false)
		//{
		//}
			

			// Concatenate all the code in a single string
			//for (size_t i = 0; i < m_Temp_NodosLocales.size(); i++)
			//{
			//	m_parsedNode += m_Temp_NodosLocales[i];
			//}
			isChecking = false;
		}
	}
	


}
