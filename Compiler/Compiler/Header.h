#pragma once
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;



struct Tokens
{
	vector <string> Lexem;
	vector <string> Type;
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

