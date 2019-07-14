#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>
#include <map>
//std::locale::global(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
using namespace std;



struct Tokens
{
  vector <string> line;
	vector <string> Lexem;
	vector <string> type;
};

struct Errors
{
	vector <string> Error;
	vector <string> Type;
};


struct FuncType
{
	vector <string> type = { "while","int","float","bool", "void" };
};

enum Tipos
{
	KEYWORD = 1,
	ID,
	Int,
	Float,
	OP_LOG,
	OP_REL,
	OP_ARIT,
	OP_LOG_UNARIO
};

enum SYMBOL_CAT
{
	UNDEFINED = 0,
	GLOBAL_VAR,
	LOCAL_VAR,
	FUNCTION,
	PARAMETER
};

struct NL
{
	vector<string> Line; // line of the variable
	vector<string> Name; // Variable
	vector<string> Type; // Data type (int, string, main, etc...)
	vector<SYMBOL_CAT> Category; // symbol category
	vector<int> Dimension; // Dimension of variable
	vector<string> Function; // Type of variable ( var, int, etc...)
	vector<void*> Value;
	vector<NL> NextLN;
	//NodoLocal* NextNode;
};