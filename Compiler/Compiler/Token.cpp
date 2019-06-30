#include "stdafx.h"
#include "Token.h"


Compiler::Token::Token()
{

}

void Compiler::Token::getToken(string line, string lex, string type)
{
	string Tok = line + "@" + lex + "@" + type + "@";
	m_tokenGroup.push_back(Tok);
}

string Compiler::Token::parsedTokens()
{
	// Concatenate all the code in a single string
	for (size_t i = 0; i < m_tokenGroup.size(); i++)
	{
		m_parsedSrcCode += m_tokenGroup[i];
	}
	return m_parsedSrcCode;
}

string Compiler::Token::getLex() const
{
	return string();
}
