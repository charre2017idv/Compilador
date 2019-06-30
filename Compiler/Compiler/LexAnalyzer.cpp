#include "stdafx.h"
#include "LexAnalyzer.h"


Compiler::LexAnalyzer::LexAnalyzer( ErrorModule ^ errorMod)
{
	m_refErrorMod = errorMod;
}

void Compiler::LexAnalyzer::tokenComp(string tok)
{
	string s;
	std::size_t founderer = tok.find(".");
	if (tok != "")
	{
		char va = tok.at(0);
		s = va;
	}
	if (find(m_keyword.begin(), m_keyword.end(), tok) != m_keyword.end())
	{
		addToken(out_string2, tok, "KEYWORD");
	}
	else if (find(m_separator.begin(), m_separator.end(), tok) != m_separator.end())
	{
		addToken(out_string2, tok, "SEPARATOR");
	}
	else if (find(m_op_dim.begin(), m_op_dim.end(), tok) != m_op_dim.end())
	{
		addToken(out_string2, tok, "DIMENSION_OPERATOR");
	}
	else if (find(m_op_grup.begin(), m_op_grup.end(), tok) != m_op_grup.end())
	{
		addToken(out_string2, tok, "GROUPING_OPERATOR");
	}
	else if (founderer != std::string::npos)
	{
		addToken(out_string2, tok, "FLOAT_NUMBER");
	}
	else if (find(m_digit.begin(), m_digit.end(), s) != m_digit.end())
	{
		addToken(out_string2, tok, "INT_NUMBER");
	}
	else if (find(m_op_log.begin(), m_op_log.end(), tok) != m_op_log.end())
	{
		addToken(out_string2, tok, "OP_LOGICO");
	}
	else if (find(m_op_arit.begin(), m_op_arit.end(), tok) != m_op_arit.end())
	{
		addToken(out_string2, tok, "OP_ARITMETICO");
	}
	else if (find(m_asignacion.begin(), m_asignacion.end(), tok) != m_asignacion.end())
	{
		addToken(out_string2, tok, "ASIGNATION");
	}
	else if (tok.front() == '"')
	{
		addToken(out_string2, tok, "STRING");
	}
	else
	{
		if (tok != "")
		{
			addToken(out_string2, tok, "ID");
		}
	}
}

void Compiler::LexAnalyzer::clearTokens()
{
}

bool Compiler::LexAnalyzer::parseSourceCode(const char * srcCode)
{
	string str;
	int size = strlen(srcCode);
	// Separate the srcCode
	for (int i = 0; i < size; i++)
	{
		prevToken = srcCode[i - 1];
		currentToken = srcCode[i];
		nextToken = srcCode[i + 1];
		if (m_state == 0)
		{
			// Simbolors, op_log, separadores
			if (currentToken == ',' || currentToken == ':' || currentToken == ';' || currentToken == '\n' || currentToken == '(' || currentToken == ')' || currentToken == '[' || currentToken == ']' || currentToken == '{' || currentToken == '}' || currentToken == '+' || currentToken == '-' || currentToken == '/' || currentToken == '*' || currentToken == '!' || currentToken == '^' || currentToken == '@' || currentToken == '$' || currentToken == '#' || currentToken == '_' )
			{
				m_state = 2;
			}
			// int
			if (currentToken >= '0' && currentToken <= '9')
			{
				m_state = 3;
			}
			// float
			// Error float
			if (currentToken == '.' && isdigit(nextToken))
			{
				m_state = 4;
			}
			else if (currentToken == '.')
			{
				m_state = 4;
			}
			if ( (currentToken >= '0' && currentToken <= '9') && nextToken == '.'  && (nextToken >= '0' && nextToken <= '9'))
			{
				m_state = 4;
			}
			// string
			if (currentToken == '"')
			{
				m_state = 5;
			}
			// Comment
			if (currentToken == '/' && nextToken == '*')
			{
				m_state = 6;
			}
			// And
			if (currentToken == '&' && nextToken == '&')
			{
				m_state = 7;
			}
			// Equal Equal
			if (currentToken == '=' && nextToken == '=')
			{
				m_state = 8;
			}
			// Asignacion
			if ((prevToken != '=' && currentToken == '=' && nextToken != '=') || (prevToken != '&' && currentToken == '&' && nextToken != '&'))
			{
				m_state = 9;
			}
			// letter
			if ((currentToken >= 'a' && currentToken <= 'z') || (currentToken >= 'A' && currentToken <= 'Z'))
			{
				m_state = 1;
			}
			/* Errors of Lexem */
			// Error Op Log
			if (currentToken == '&' && nextToken != '&')
			{
				str = currentToken;
				String^ ErrorDesc = gcnew String(str.c_str());
				String^ Error;
				Error = _INVALID_OP_LOG;
				m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, ErrorDesc);
				//isError = true;
				i++;
				str.clear();
				m_state = 0;
			}
			// Error Char
			if (find(m_general.begin(), m_general.end(), currentToken) != m_general.end())
			{
			}
			else
			{
				m_state = 10;
				//errores.push_back(currentToken);
			}
		}

		
		// letter
		if (m_state == 1)
		{
			if (currentToken != ' ' && currentToken != ','  && currentToken != '.' && currentToken != '\t' && currentToken != '\n' && currentToken != '\r\n')
			{
				str += currentToken;
			}
			if (nextToken == ' ' || nextToken == ',' || nextToken == '.' || nextToken == '\0' || nextToken == '\n' || nextToken == '\r\n' || nextToken == '\t' || nextToken == ';' || nextToken == ':' || nextToken == '(' || nextToken == ')' || nextToken == '[' || nextToken == ']' || nextToken == '{' || nextToken == '}') // agregar tabulador en condicion
			{
				// HACER FUNCION COMPROBACION Y ASIGNAR AHI LOS TIPOS
				temp_Code.push_back(str);
				tokenComp(str);
				//i++;
				str.clear();
				m_state = 0;
			}
		}
		// Separadores
		if (m_state == 2)
		{
			str += currentToken;
			temp_Code.push_back(str);
			tokenComp(str);
			str.clear();
			m_state = 0;
		}
		// Int
		if (m_state == 3)
		{
			if (currentToken != ' ' && currentToken != '\t' && currentToken != '.')
			{
				str += currentToken;
			}
			if (currentToken == '.')
			{
				m_state = 4;
			}
			if (nextToken == ' ' || isalpha(nextToken) || nextToken == ';' || nextToken == '\n' || nextToken == '\0' || nextToken == ']' || nextToken == ')')
			{
				temp_Code.push_back(str);
				tokenComp(str);
				//i++;
				str.clear();
				m_state = 0;
			}
		}
		// float
		if (m_state == 4)
		{
			if (currentToken != ' ' && currentToken != '\t' )
			{
				str += currentToken;
			}
			//if (find(m_letters.begin(), m_letters.end(), currentToken) != m_letters.end())
			//{
			//	String^ ErrorDesc = gcnew String(str.c_str());
			//	String^ Error;
			//	Error = _COMMENT_NOT_CLOSED;
			//	m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, ErrorDesc);
			//	//isError = true;
			//	i++;
			//	str.clear();
			//	m_state = 0;
			//}	
			if (nextToken == ' ' || nextToken == ';' || nextToken == '\n' || nextToken == '\0' || nextToken == ']' || nextToken == ')')
			{
				temp_Code.push_back(str);
				tokenComp(str);
				//i++;
				str.clear();
				m_state = 0;
			}
		}
		// String
		if (m_state == 5)
		{
			str += currentToken;

			if (nextToken == '"')
			{
				temp_Code.push_back(str + nextToken);
				tokenComp(str + nextToken);
				i++;
				str.clear();
				m_state = 0;
			}
			if (nextToken == '\0')
			{
				//str = currentToken;
				String^ ErrorDesc = gcnew String(str.c_str());
				String^ Error;
				Error = _STRING_NOT_CLOSED;
				m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, ErrorDesc);
				//isError = true;
				i++;
				str.clear();
				m_state = 0;
			}
		}
		// Comment
		if (m_state == 6)
		{
			str += currentToken;
			if (currentToken == '*' && nextToken == '/')
			{
				temp_Code.push_back(str + nextToken);
				tokenComp(str + nextToken);
				i++;
				str.clear();
				m_state = 0;
			}
			if (nextToken == '\0')
			{
				//str = currentToken;
				String^ ErrorDesc = gcnew String(str.c_str());
				String^ Error;
				Error = _COMMENT_NOT_CLOSED;
				m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, ErrorDesc);
				//isError = true;
				i++;
				str.clear();
				m_state = 0;
			}
		}
		// And
		if (m_state == 7)
		{
			str += currentToken;
			temp_Code.push_back(str + nextToken);
			tokenComp(str + nextToken);
			str.clear();
			m_state = 0;
		}
		// ==
		if (m_state == 8)
		{
			str += currentToken;
			temp_Code.push_back(str + nextToken);
			tokenComp(str + nextToken);
			str.clear();
			m_state = 0;
		}
		if (m_state == 9)
		{
			str += currentToken;
			temp_Code.push_back(str);
			tokenComp(str);
			str.clear();
			m_state = 0;
		}
		// Errors
		if (m_state == 10)
		{
			str = currentToken;
			String^ ErrorDesc = gcnew String(str.c_str());
			String^ Error;
			Error = LEX_INVALID_CHAR;
			m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, ErrorDesc);
			//isError = true;
			i++;
			str.clear();
			m_state = 0;
		}
	}

	// Asignar tipo y lexema
	
	for (size_t i = 0; i < temp_Code.size(); i++)
	{
		// If line jump is find, the cout line increases
		size_t found = temp_Code[i].find('\n');
		if (found != string::npos)
		{
			line++;
		}
	}
	// Tokenize the temp_Code store
	int line = 0;
	for (size_t i = 0; i < m_tokens.Lexem.size(); i++)
	{
		isError = false;

		// If line jump is find, the cout line increases
		String^ ErrorDesc = gcnew String(m_tokens.Lexem[i].c_str());
		size_t found = m_tokens.Lexem[i].find('\n');
		if (found != string::npos)
			line++;
		// Cast the 'line' to string
		out_string2 = to_string(line);

		std::size_t found3 = m_tokens.Lexem[i].find("\n");
		if (found3 != std::string::npos)
		{
			isError = true;
		}
		// Concatenate in strings the group of line, lexem and type
		if (isError == false)
		{
			string ab = out_string2 + "@" + m_tokens.Lexem[i] + "@" + m_tokens.Type[i] + "@";
			LLT.push_back(ab);
			isError = false;
		}	
	}
	return false;
}

string Compiler::LexAnalyzer::parsedTokens()
{
	// Concatenate all the code in a single string
	for (size_t i = 0; i < LLT.size(); i++)
	{
		m_parsedSrcCode += LLT[i];
	}
	return m_parsedSrcCode;
}

void Compiler::LexAnalyzer::getTokens(vector<Token*>* tokensVec)
{
	
}

Compiler::Token * Compiler::LexAnalyzer::getNextToken()
{
	//Token* t = nullptr;
	string t;
	if (m_currentToken < LLT.size())
	{
		t = LLT[++m_currentToken];
	}

	return nullptr;// Dice cual es el ultimo Token que ha procesado el analizador sintactico
}

string Compiler::LexAnalyzer::getNextTokenS()
{
	//Token* t = nullptr;
	string str;
	string t;
	
	m_currentToken++;
	if (m_currentToken < m_tokens.Lexem.size())
	{
		t = m_tokens.Lexem[m_currentToken];
	}

	return t;// Dice cual es el ultimo Token que ha procesado el analizador sintactico
}

string Compiler::LexAnalyzer::getPrevTokenS()
{
	//Token* t = nullptr;
	string str;
	string t;

	
	if (m_currentToken < m_tokens.Lexem.size())
	{
		t = m_tokens.Lexem[m_currentToken];
	}

	return t;
}

string Compiler::LexAnalyzer::peekToken(int i)
{
	//Token* t = nullptr;
	string str;
	string t;

	t = m_tokens.Lexem[i];

	return t;
}

void Compiler::LexAnalyzer::addToken(string lineNum, string lex, string type)
{
	m_tokens.Lexem.push_back(lex);
	m_tokens.Type.push_back(type);
}

