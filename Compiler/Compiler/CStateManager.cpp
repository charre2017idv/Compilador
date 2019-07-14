#include "stdafx.h"
#include "CStateManager.h"


CStateManager::CStateManager()
{
}

void CStateManager::AsignType(const char * srcCode, map<string, string> m_keywords)
{
	maps();
	string str;
	string temp_string;

	// Separate all the characters in temp vector
/*
	int size = strlen(srcCode);
	for (int i = 0; i < size; i++)
	{
		temp.push_back(srcCode[i]);
	}

	// Get the words od srcCode in vector saparated by space
	for (int i = 0; i < size; i++)
	{
		if (srcCode[i] != ' ')
		{
			tempStr += srcCode[i];

		}
		if (srcCode[i] == ' ')
		{
			temp_Code.push_back(tempStr);
			tempStr.clear();
		}
	}

	for (int i = 0; i < temp.size(); i++)
	{
		if (m_state == 0)
		{
			CBuffer(i);
			NBuffer(i);

			if (CurrentBuffer[0] == ' ')
			{
				m_state = 0;
				NextBuffer.clear();
			}
			else
				m_state = 1;

		}
		if (m_state == 1) // KeyWord State
		{
			keywordState();
		}
		if (m_state == 2) // ID State
		{
			IDState(i);
		}
		if (m_state == 3) // Separator State
		{
			SeparatorState(i);
		}
		if (m_state == 4)
		{
			OPDimState(i);
		}
		if (m_state == 5)
		{
			DigitsState(i);
		}
		if (m_state == 6)
		{
			if (m_keywords.count(NextBuffer) > 0 && m_ID.count(NextBuffer) > 0 && m_SEPARATOR.count(NextBuffer) > 0 && m_OP_DIM.count(NextBuffer) > 0 && m_DIGITS.count(NextBuffer) > 0)
			{

			}
			else
			{
				for (int i = 0; i < temp_Code.size(); i++)
				{
					if (NextBuffer == temp_Code[i])
					{
						m_tokens.Lexem.push_back(NextBuffer);
						m_tokens.Type.push_back("ID");
					}

				}

				//IDState(i);
				m_state = 0;
			}
		}
	}
	*/

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
		if (srcCode[i] != ' ' || srcCode[i] != ',')
		{
			str += srcCode[i];
		}
		if (srcCode[i + 1] == ' ' || srcCode[i + 1] == '\t' || srcCode[i + 1] == '\n' || srcCode[i + 1] == '\0')
		{
			temp_Code.push_back(str);
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

		//if (srcCode[i+1] == '#')
		//{
		//	str.clear();
		//	//temp_string = srcCode[i+1];
		//
		//	while (srcCode[i + 1] != ' ' || srcCode[i + 1] != '\n')
		//	{
		//		str += srcCode[i + 1];
		//		i++;
		//	}
		//
		//	//string cad = '/' + str + '/';
		//	Error.Error.push_back(str);
		//	Error.Type.push_back(LEX_INVALID_CHAR);
		//	i++;
		//	str.clear();
		//}
		//if (srcCode[i+1] == '$')
		//{
		//	temp_Code.push_back(str);
		//	i++;
		//	str.clear();
		//}
	}
	// Asignar tipo y lexema
	string s;
	for (size_t i = 0; i < temp_Code.size(); i++)
	{
		if (temp_Code[i] != "")
		{
			char va = temp_Code[i].at(0);
			s = va;
		}
		if (find(m_keyword.begin(), m_keyword.end(), temp_Code[i]) != m_keyword.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("KEYWORD");
			// Element in vector.
		}
		else if (find(m_separator.begin(), m_separator.end(), temp_Code[i]) != m_separator.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("SEPARATOR");
			// Element in vector.
		}
		else if (find(m_op_dim.begin(), m_op_dim.end(), temp_Code[i]) != m_op_dim.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("OP_DIMENSIONAL");
			// Element in vector.
		}
		else if (find(m_digit.begin(), m_digit.end(),  s) != m_digit.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("DIGIT");
		}
		else if (find(m_op_log.begin(), m_op_log.end(), temp_Code[i]) != m_op_log.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("OP_LOGICO");
		}
		else if (find(m_op_arit.begin(), m_op_arit.end(), temp_Code[i]) != m_op_arit.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("OP_ARITMETICO");
		}
		else if (find(m_asignacion.begin(), m_asignacion.end(), temp_Code[i]) != m_asignacion.end())
		{
			m_tokens.Lexem.push_back(temp_Code[i]);
			m_tokens.type.push_back("ASIGNACION");
		}
		//else if (find(m_simbolos.begin(), m_simbolos.end(), temp_Code[i]) != m_simbolos.end())
		//{
		//	Error.Error.push_back(temp_Code[i]);
		//	Error.Type.push_back("Invalid character");
		//
		//}
		else
		{
			if (temp_Code[i] != "" )
			{
				m_tokens.Lexem.push_back(temp_Code[i]);
				m_tokens.type.push_back("ID");
			}
		
			std::size_t found = temp_Code[i].find("#");
			if (found != std::string::npos)
			{
				Error.Error.push_back(temp_Code[i]);
				Error.Type.push_back(LEX_INVALID_CHAR);
			}
			std::size_t found2 = temp_Code[i].find("$");
			if (found2 != std::string::npos)
			{
				Error.Error.push_back(temp_Code[i]);
				Error.Type.push_back(LEX_INVALID_CHAR);
			}
			std::size_t found3 = temp_Code[i].find("¼");
			if (found3 != std::string::npos)
			{
				Error.Error.push_back(temp_Code[i]);
				Error.Type.push_back(LEX_INVALID_CHAR);
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
		// If line jump is find, the cout line increases
		size_t found = m_tokens.Lexem[i].find('\n');
		if (found != string::npos)
		{
			line++;
		}
		out_string2 = to_string(line);
		// Concatenate in strings the group of line, lexem and type
		string ab = out_string2 + "@" + m_tokens.Lexem[i] + "@" + m_tokens.type[i] + "@";
		BA.push_back(ab);
	}
	// Concatenate all the code in a single string
	for (size_t i = 0; i < BA.size(); i++)
	{
		m_parsedSrcCode += BA[i];
	}
}


void CStateManager::CBuffer(int i)
{

	CurrentBuffer.clear();
	CurrentBuffer += temp[i];

}

void CStateManager::NBuffer(int i)
{
	NextBuffer += temp[i];
}

void CStateManager::keywordState()
{
	if (m_keywords.count(NextBuffer) > 0)
	{
		m_tokens.Lexem.push_back(NextBuffer);
		m_tokens.type.push_back("KEYWORD");
		NextBuffer.clear();
		m_state = 0;
	}
	else
	{
		m_state = 2;
	}

}

void CStateManager::IDState(int i)
{
	if (m_ID.count(CurrentBuffer) > 0)//if (m_keywords.count(a) < 0 || m_OP.count(es) < 0 )
	{
		char o = temp[i + 1];
		string f(1, o);
		m_tokens.Lexem.push_back(f);
		m_tokens.type.push_back("ID");
		NextBuffer.clear();
		m_state = 0;
	}
	else
	{
		m_state = 3;
	}
}

void CStateManager::SeparatorState(int i)
{
	if (m_SEPARATOR.count(CurrentBuffer) > 0)
	{
		char o = temp[i];
		string f(1, o);
		m_tokens.Lexem.push_back(CurrentBuffer);
		m_tokens.type.push_back("SEPARATOR");
		CurrentBuffer.clear();
		NextBuffer.clear();
		//NextBuffer = f[0];
		m_state = 0;
	}
	else
		m_state = 4;
}

void CStateManager::OPDimState(int i)
{
	if (m_OP_DIM.count(CurrentBuffer) > 0)//if (m_keywords.count(a) < 0 || m_OP.count(es) < 0 )
	{
		char o = temp[i];
		string f(1, o);
		m_tokens.Lexem.push_back(CurrentBuffer);
		m_tokens.type.push_back("OP_DIM");
		NextBuffer.clear();
		//NextBuffer = f[0];// Value between the OP_DIM
		m_state = 0;
	}
	else
		m_state = 5;
}

void CStateManager::DigitsState(int i)
{
	if (m_DIGITS.count(NextBuffer) > 0)//if (m_keywords.count(a) < 0 || m_OP.count(es) < 0 )
	{
		char o = temp[i];
		string f(1, o);
		m_tokens.Lexem.push_back(NextBuffer);
		m_tokens.type.push_back("DIGITS");
		NextBuffer.clear();
		//NextBuffer = f[0];
		m_state = 0;
	}
	else
		m_state = 6;
}

void CStateManager::maps()
{
	// Keywords
	m_keywords.insert(std::make_pair("var"		, ""));
	m_keywords.insert(std::make_pair("int"		, ""));
	m_keywords.insert(std::make_pair("float"	, ""));
	m_keywords.insert(std::make_pair("string"	, ""));
	m_keywords.insert(std::make_pair("bool"		, ""));
	m_keywords.insert(std::make_pair("void"		, ""));
	m_keywords.insert(std::make_pair("function"	, ""));
	m_keywords.insert(std::make_pair("for"		, ""));
	m_keywords.insert(std::make_pair("while"	, ""));
	m_keywords.insert(std::make_pair("if"		, ""));
	m_keywords.insert(std::make_pair("else"		, ""));
	m_keywords.insert(std::make_pair("switch"	, ""));
	m_keywords.insert(std::make_pair("case"		, ""));
	m_keywords.insert(std::make_pair("default"	, ""));
	m_keywords.insert(std::make_pair("print"	, ""));
	m_keywords.insert(std::make_pair("read"		, ""));
	m_keywords.insert(std::make_pair("return"	, ""));
	m_keywords.insert(std::make_pair("true"		, ""));
	m_keywords.insert(std::make_pair("flase"	, ""));
	m_keywords.insert(std::make_pair("inc"		, ""));
	m_keywords.insert(std::make_pair("dec"		, ""));
	// Separadores
	m_SEPARATOR.insert(std::make_pair(";", ""));
	m_SEPARATOR.insert(std::make_pair(":", ""));
	m_SEPARATOR.insert(std::make_pair(",", ""));
	//m_SEPARATOR.insert(std::make_pair(" ", ""));
	// Letras
	m_letras.insert(std::make_pair("A", ""));
	m_letras.insert(std::make_pair("a", ""));
	m_letras.insert(std::make_pair("B", ""));
	m_letras.insert(std::make_pair("b", ""));
	m_letras.insert(std::make_pair("C", ""));
	m_letras.insert(std::make_pair("c", ""));
	m_letras.insert(std::make_pair("D", ""));
	m_letras.insert(std::make_pair("d", ""));
	m_letras.insert(std::make_pair("E", ""));
	m_letras.insert(std::make_pair("e", ""));
	m_letras.insert(std::make_pair("F", ""));
	m_letras.insert(std::make_pair("f", ""));
	m_letras.insert(std::make_pair("G", ""));
	m_letras.insert(std::make_pair("g", ""));
	m_letras.insert(std::make_pair("H", ""));
	m_letras.insert(std::make_pair("h", ""));
	m_letras.insert(std::make_pair("I", ""));
	m_letras.insert(std::make_pair("i", ""));
	m_letras.insert(std::make_pair("J", ""));
	m_letras.insert(std::make_pair("j", ""));
	m_letras.insert(std::make_pair("K", ""));
	m_letras.insert(std::make_pair("k", ""));
	m_letras.insert(std::make_pair("L", ""));
	m_letras.insert(std::make_pair("l", ""));
	m_letras.insert(std::make_pair("M", ""));
	m_letras.insert(std::make_pair("m", ""));
	m_letras.insert(std::make_pair("N", ""));
	m_letras.insert(std::make_pair("n", ""));
	m_letras.insert(std::make_pair("O", ""));
	m_letras.insert(std::make_pair("o", ""));
	m_letras.insert(std::make_pair("P", ""));
	m_letras.insert(std::make_pair("p", ""));
	m_letras.insert(std::make_pair("Q", ""));
	m_letras.insert(std::make_pair("q", ""));
	m_letras.insert(std::make_pair("R", ""));
	m_letras.insert(std::make_pair("r", ""));
	m_letras.insert(std::make_pair("S", ""));
	m_letras.insert(std::make_pair("s", ""));
	m_letras.insert(std::make_pair("T", ""));
	m_letras.insert(std::make_pair("t", ""));
	m_letras.insert(std::make_pair("U", ""));
	m_letras.insert(std::make_pair("u", ""));
	m_letras.insert(std::make_pair("V", ""));
	m_letras.insert(std::make_pair("v", ""));
	m_letras.insert(std::make_pair("W", ""));
	m_letras.insert(std::make_pair("w", ""));
	m_letras.insert(std::make_pair("X", ""));
	m_letras.insert(std::make_pair("x", ""));
	m_letras.insert(std::make_pair("Y", ""));
	m_letras.insert(std::make_pair("y", ""));
	m_letras.insert(std::make_pair("Z", ""));
	m_letras.insert(std::make_pair("z", ""));
	// ID
	m_ID.insert(std::make_pair("_", ""));
	//m_ID.insert(std::make_pair(" ", ""));
	// Operador Dimensional
	m_OP_DIM.insert(std::make_pair("[", ""));
	m_OP_DIM.insert(std::make_pair("]", ""));
	// Digitos
	m_DIGITS.insert(std::make_pair("0", ""));
	m_DIGITS.insert(std::make_pair("1", ""));
	m_DIGITS.insert(std::make_pair("2", ""));
	m_DIGITS.insert(std::make_pair("3", ""));
	m_DIGITS.insert(std::make_pair("4", ""));
	m_DIGITS.insert(std::make_pair("5", ""));
	m_DIGITS.insert(std::make_pair("6", ""));
	m_DIGITS.insert(std::make_pair("7", ""));
	m_DIGITS.insert(std::make_pair("8", ""));
	m_DIGITS.insert(std::make_pair("9", ""));

}