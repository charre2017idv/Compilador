#pragma once
#define LEX_INVALID_CHAR "Invalid character"
#include "Header.h"
#include <map>
class CStateManager
{
public:
	CStateManager();
public:
	vector <string> m_keyword = { "var", "int","float","string","bool","void","function","for","while","if","else","switch","case","default","print","read","return","true","flase","inc","dec" };
	vector <string> m_separator = { ";",":", "," };
	vector <string> m_op_arit = { "+","-","*","/","%" };
	vector <string> m_op_dim = {"{","}","(",")","[","]" };
	vector <string> m_op_log = {"!","||","&&"};
	vector <string> m_digit = { "0","1","2","3","4","5","6","7","8","9" };
	vector <string> m_asignacion = { "=" };
	vector <string> m_simbolos = { "#","$","@","ñ","Ñ","~", "¼" };

	map<string, string> m_letras;
	map<string, string> m_keywords;
	map<string, string> m_SEPARATOR;
	map<string, string> m_ID;
	map<string, string> m_OP_DIM;
	map<string, string> m_DIGITS;

	Tokens m_tokens;
	vector<string> temp_Code;
	vector<char> temp;
	string NextBuffer;    // NextBuffer
	string CurrentBuffer; // CurrentBuffer
	string Str;
	string tempStr;

	string m_parsedSrcCode;
	vector<string> BA;
	string out_string2;
	Errors Error;

	int m_state = 0;
public:
	void AsignType(const char * srcCode, map<string, string> m_keywords);
private:
	void CBuffer(int i); 
	void NBuffer(int i);
	void maps();
	void keywordState();
	void IDState(int i);
	void SeparatorState(int i);
	void OPDimState(int i);
	void DigitsState(int i);

};

