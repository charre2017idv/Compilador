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

		
	public:
		Token m_Token;
		msclr::gcroot<ErrorModule^> m_refErrorMod;
		vector <string> m_keyword = { "var", "int","float","main","string","bool","void","function","for","while","if","else","switch","case","default","print","read","return","true","false","inc","dec" };
		vector <string> m_separator = { ";",":", "," };
		vector <string> m_op_arit = { "+","-","*","/","%", "<", ">" };
		vector <string> m_op_grup = { "{","}","(",")" };
		vector <string> m_op_dim = { "[","]" };
		vector <string> m_op_log = { "!","||","&&","=="};
		vector <string> m_digit = { "0","1","2","3","4","5","6","7","8","9" };
		vector <string> m_letra= { "a","b","c","d","e","f","g","h","i","j","k","l","m","o","p","k","r" };
		vector <char> m_letters= { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		vector <string> m_asignacion = { "=" };
		vector <string> m_simbolos = { "#","$","@","ñ","Ñ","~", "¼" , "^", "¬","ダダン"};
		vector <char> m_general = { '<', '>',';',':', ',','.','+','-','*','/','%','{','}','(',')','[',']','!','0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','=',' ','\t','\n','"','&'};

		vector<string> temp_Code;
		vector<string> LLT;
		vector<string> tokens;
		vector<char> errores;
		string out_string2;
		string m_parsedSrcCode;
		Tokens m_tokens;
		Errors Error;

		//Token m_TOKEN;

		char prevToken;
		char currentToken;
		char nextToken;
		int m_state = 0;

		int m_currentToken = -1;


		int line = 1;
		bool isError = false;
		bool isString = false;

	public:
		LexAnalyzer(ErrorModule^errorMod);
		//~LexAnalyzer();
		void tokenComp(string tok);
		CStateManager StateManage;
	public:
		void clearTokens();
		bool parseSourceCode(const char*src);
		string parsedTokens();
		void getTokens(vector<Token*> * tokensVec);
		Token* getNextToken();
		string getNextTokenS();
		string getPrevTokenS();
		string peekToken(int i);
		void addToken(string lineNum, string lex,string type);
	};
}

