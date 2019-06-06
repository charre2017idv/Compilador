#include "stdafx.h"
#include "LexAnalyzer.h"


Compiler::LexAnalyzer::LexAnalyzer( ErrorModule ^ errorMod)
{
	m_refErrorMod = errorMod;

}


void Compiler::LexAnalyzer::clearTokens()
{
}

bool Compiler::LexAnalyzer::parseSourceCode(const char * srcCode)
{
	//StateManage.AsignType(src, m_keywords);
	string str;
	string temp_string;

	int size = strlen(srcCode);

	// Separate the srcCode
	/*
	for (int i = 0; i < size; i++)
	{
		// Concatenate the string if the srcCode is not the token
		if (srcCode[i] != ' ' || srcCode[i] != ',')
		{
			str += srcCode[i];
		}

		if (srcCode[i] == '"')
		{
			//temp_string = srcCode[i+1];
			while (srcCode[i + 1] != '"')
			{
				str += srcCode[i+1];
				i++;
			}

			string cad = '"' + str + '"';
			temp_Code.push_back(cad);
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of space and separations
		if (srcCode[i + 1] == ' ' || srcCode[i + 1] == '\t' || srcCode[i + 1] == '\n' || srcCode[i + 1] == '\0')
		{
			temp_Code.push_back(str);
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of ':'
		if (srcCode[i + 1] == ':')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(":");
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of '('
		if (srcCode[i + 1] == '(')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("(");
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of ')'
		if (srcCode[i + 1] == ')')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(")");
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of '{'
		if (srcCode[i + 1] == '{')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("{");
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of '}'
		if (srcCode[i + 1] == '}')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("}");
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of ';'
		if (srcCode[i + 1] == ';')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(";");
			i++;
			str.clear();
		}

		// Push to the temp vector the actual string if the srccode is equal to the token of ','
		if (srcCode[i + 1] == ',')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(",");
			i++;
			str.clear();
		}
	}
	*/
	for (int i = 0; i < size; i++)
	{
		if (srcCode[i] != ' ' || srcCode[i] != ',' )
		{
			str += srcCode[i];
		}
		if (srcCode[i + 1] == ' ' || srcCode[i + 1] == '\t'  || srcCode[i + 1] == '\0')
		{
			temp_Code.push_back(str);
			i++;
			str.clear();
		}
		if (srcCode[i] == '\n' || srcCode[i + 1] == '\n')
		{
			temp_Code.push_back(str);
			//temp_Code.push_back("\n");
			i++;
			str.clear();
		}
		// Delimitadores
		if (srcCode[i + 1] == ',')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(",");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == ':')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(":");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == ';')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(";");
			i++;
			str.clear();
		}
		// Operadores Agrupacion
		if (srcCode[i + 1] == '(')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("(");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == ')')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(")");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == '{')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("{");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == '}')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("}");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == '[')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("[");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == ']')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("]");
			i++;
			str.clear();
		}
		// Asignacion
		if (srcCode[i + 1] == '=')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("=");
			i++;
			str.clear();
		}
		// Relacionales
		if (srcCode[i + 1] == '<=')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("<=");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == '>=')
		{
			temp_Code.push_back(str);
			temp_Code.push_back(">=");
			i++;
			str.clear();
		}
		// Operadores logicos
		if (srcCode[i + 1] == '&&')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("&&");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == '||')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("||");
			i++;
			str.clear();
		}
		// Operadores Logicos
		if (srcCode[i + 1] == '+')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("+");
			i++;
			str.clear();
		}
		if (srcCode[i + 1] == '-')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("-");
			i++;
			str.clear();
		}
		//if (srcCode[i + 1] == '*')
		//{
		//	temp_Code.push_back(str);
		//	temp_Code.push_back("*");
		//	i++;
		//	str.clear();
		//}
		if (srcCode[i + 1] == '%')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("%");
			i++;
			str.clear();
		}
		
		// Logico Unario
		if (srcCode[i + 1] == '!')
		{
			temp_Code.push_back(str);
			temp_Code.push_back("!");
			i++;
			str.clear();
		}
		// String
		if (srcCode[i] == '"')
		{
			str.clear();
			//temp_string = srcCode[i+1];

			while (srcCode[i + 1] != '"')
			{
				str += srcCode[i + 1];
				i++;
			}

			string cad = '"' + str + '"';
			temp_Code.push_back(cad);
			i++;
			str.clear();
		}
		// Comentario
		if (srcCode[i] == '/')
		{
			str.clear();
			//temp_string = srcCode[i+1];

			while (srcCode[i + 1] != '/')
			{
				str += srcCode[i + 1];
				i++;
			}

			string cad = '/' + str + '/';
			temp_Code.push_back(cad);
			i++;
			str.clear();
		}
		//
		if (srcCode[i] == '#')
		{
			//temp_Code.push_back(str);
			temp_Code.push_back("#");
			i++;
			str.clear();
		}
		if (srcCode[i] == '$' || srcCode[i+1] == '$')
		{
			//temp_Code.push_back(str);
 			temp_Code.push_back("$");
			i++;
			str.clear();
		}
	}
	// Asignar tipo y lexema
	string s;
	string s2;
	for (size_t i = 0; i < temp_Code.size(); i++)
	{
		std::size_t founderer = temp_Code[i].find(".");
		if (temp_Code[i] != "")
		{
			char va = temp_Code[i].at(0);
			//char vaz = temp_Code[i].at(1);
			s = va;
			//s2 = vaz;
		}
		if (find(m_keyword.begin(), m_keyword.end(), temp_Code[i]) != m_keyword.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("KEYWORD");
			// Element in vector.
		}
		else if (find(m_separator.begin(), m_separator.end(), temp_Code[i]) != m_separator.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("SEPARATOR");
			// Element in vector.
		}
		else if (find(m_op_dim.begin(), m_op_dim.end(), temp_Code[i]) != m_op_dim.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("OP_DIMENSIONAL");
			// Element in vector.
		}
		else if (find(m_digit.begin(), m_digit.end(), s) != m_digit.end())
		{
			
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("DIGIT");
		}
		else if (find(m_op_log.begin(), m_op_log.end(), temp_Code[i]) != m_op_log.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("OP_LOGICO");
		}
		else if (find(m_op_arit.begin(), m_op_arit.end(), temp_Code[i]) != m_op_arit.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("OP_ARITMETICO");
		}
		else if (find(m_asignacion.begin(), m_asignacion.end(), temp_Code[i]) != m_asignacion.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("ASIGNACION");
		}
		else if (founderer != std::string::npos)
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.Type.push_back("FLOAT");
		}
		else
		{
			if (temp_Code[i] != "")
			{
				m_tokens.Lexem.push_back(temp_Code[i]);
				m_tokens.Type.push_back("ID");
			}
			
			//if(find(m_simbolos.begin(), m_simbolos.end(), temp_Code[i]) != m_simbolos.end())
			//{
			//	Error.push_back(LEX_INVALID_CHAR);
			//}
		}
	}

	// Tokenize the temp_Code stored
	// Error por string

	int line = 0;
	for (size_t i = 0; i < m_tokens.Lexem.size(); i++)
	{
		isError = false;
		// If line jump is find, the cout line increases
		String^ Desc = gcnew String(m_tokens.Lexem[i].c_str());
		size_t found = m_tokens.Lexem[i].find('\n');
		if (found != string::npos)
		{
			line++;
		}
		out_string2 = to_string(line);
		String^ Error ;
		Error = LEX_INVALID_CHAR;

		std::size_t found4 = m_tokens.Lexem[i].find('/*');
		if (found4 != std::string::npos)
		{
			std::size_t found5 = m_tokens.Lexem[i].find("*/");
			if (found5 != std::string::npos)
			{
				Error = _COMMENT_NOT_CLOSED;
				isError = false;
			}
		}


		std::size_t founding = m_tokens.Lexem[i].find('"');
		if (founding != std::string::npos)
		{
			std::size_t end = m_tokens.Lexem[i].find("\r\n");
			if (end != std::string::npos)
			{
				Error = _COMMENT_NOT_CLOSED;
				isError = false;
			}
		}

		std::size_t founder = m_tokens.Lexem[i].find("#");
		if (founder != std::string::npos)
		{
			m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, Desc);
			isError = true;
		}
		std::size_t found2 = m_tokens.Lexem[i].find("$");
		if (found2 != std::string::npos)
		{
			m_refErrorMod->addError(m_refErrorMod->lexError, line, Error, Desc);
			isError = true;
		}
		std::size_t found3 = m_tokens.Lexem[i].find("\n");
		if (found3 != std::string::npos)
		{
			isError = true;
		}

		if (isError == false)
		{
			// Concatenate in strings the group of line, lexem and type
			string ab = out_string2 + "@" + m_tokens.Lexem[i] + "@" + m_tokens.Type[i] + "@";
			BA.push_back(ab);
			isError = false;
		}


		//isError == false;
		//else if (m_tokens.Lexem[i] == "#" || m_tokens.Lexem[i] == "$")
		//{
		//
		//	BA.push_back("@");
		//}
		
	}


	// Concatenate all the code in a single string
	for (size_t i = 0; i < BA.size(); i++)
	{
		m_parsedSrcCode += BA[i];
	}
	
	
	return false;
}

void Compiler::LexAnalyzer::getTokens(vector<Token*>* tokensVec)
{
}

Compiler::Token * Compiler::LexAnalyzer::getNextToken()
{
	return nullptr;
}

Compiler::Token * Compiler::LexAnalyzer::getPrevToken()
{
	return nullptr;
}

Compiler::Token * Compiler::LexAnalyzer::peekToken()
{
	return nullptr;
}

void Compiler::LexAnalyzer::addToken(const char * lex, int lineNum, TOKEN_TYPE tp)
{
}

