#pragma once
#include "windows.h"
#include <vcclr.h>
#include "ErrorModule.h"
#include "CStateManager.h"
#include "Token.h"
#include <map>
#include "Header.h"
namespace Compiler {
#define LEX_INVALID_CHAR "Invalid character"
#define _STRING_NOT_CLOSED "Invalid string"
#define _COMMENT_NOT_CLOSED "Invalid comment"
#define _INVALID_FLOAT "Invalid float"
#define _INVALID_OP_LOG "Invalid OP_LOG"
	public class LexAnalyzer
	{
	private:
		map<string, string> m_keywords;
		//vector<Token*> m_Tokens;

//		Tokens m_tokens;
		
	public:
		msclr::gcroot<ErrorModule^> m_refErrorMod;
		vector <string> m_keyword = { "var", "int","float","main","string","bool","void","function","for","while","if","else","switch","case","default","print","read","return","true","flase","inc","dec" };
		vector <string> m_separator = { ";",":", "," };
		vector <string> m_op_arit = { "+","-","*","/","%" };
		vector <string> m_op_dim = { "{","}","(",")","[","]" };
		vector <string> m_op_log = { "!","||","&&" };
		vector <string> m_digit = { "0","1","2","3","4","5","6","7","8","9" };
		vector <string> m_asignacion = { "=" };
		vector <string> m_simbolos = { "#","$","@","ñ","Ñ","~", "¼" };
		vector<string> temp_Code;
		vector<string> BA;
		string out_string2;
		string m_parsedSrcCode;
		Tokens m_tokens;
		Errors Error;


		int line = 0;
		bool isError = false;
		bool isString = false;

	public:
		LexAnalyzer(ErrorModule^errorMod);
		//~LexAnalyzer();
		CStateManager StateManage;
	public:
		void clearTokens();
		bool parseSourceCode(const char*src);
		void getTokens(vector<Token*> * tokensVec);
		Token* getNextToken();
		Token* getPrevToken();
		Token* peekToken();
		void addToken(const char* lex, int lineNum, TOKEN_TYPE tp);
	};
}

