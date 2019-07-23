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
	string nextToken;
  string CurrToken;
  int i = 0;

  for (int i = 0; i < Lex->m_tokens.Lexem.size(); i++)
  {
    if (m_state == 0)
    {
	    CurrToken = Lex->m_tokens.Lexem[i];
    }

    if (!CurrToken.compare("var"))
    {
      m_state = 1;
    }

    if (!CurrToken.compare("function"))
    {
      m_state = 2;
    }

    if (!CurrToken.compare("main"))
    {
      m_state = 3;
    }
    /////////////////////////////////////////
    // Analyze States
    // Var State
    if (m_state == 1)
    {
      varState(i);
    }
    // function State
    if (m_state == 2)
    {
      functionState(i);
      i = m_currIndex;
    }
    // main state
    if (m_state == 3)
    {
      mainState(i);
      i = m_currIndex;
    }
  }

  
}
// Generate temp in function
void Compiler::SyntaxState_Program::varState(int i)
{
  for (int j = i; j < Lex->m_tokens.Lexem.size(); j++)
  {
    string tempToken = Lex->m_tokens.Lexem[j];
    if (tempToken == ":")
    {
      m_state = 0;
      break;
    }
    if (tempToken != "var" && tempToken != ","
      && tempToken != "[" && tempToken != "]" && tempToken != "1" && tempToken != "2"
      && tempToken != "3" && tempToken != "4" && tempToken != "5" && tempToken != "6"
      && tempToken != "7" && tempToken != "8" && tempToken != "9" && tempToken != ":")
    {
      AllocateSymbol(Lex->m_tokens.line[j], tempToken, ":", GLOBAL_VAR, "[", j, false, m_tempInFunc);
    }
  }
}

void Compiler::SyntaxState_Program::functionState(int i)
{
  for (int j = i; j < Lex->m_tokens.Lexem.size(); j++)
  {
    string tempToken = Lex->m_tokens.Lexem[j];

    if (tempToken == ":" || tempToken == ";" || tempToken == "{")
    {
      m_state = 0;
      break;
    }
    if (tempToken == "(")
    {
      m_tempInFunc = Lex->m_tokens.Lexem[i + 1];
      Check_EXP_LOG(j);
      break;
    }
    // If token is different that 'var' or numbers
    if (tempToken != "function" && tempToken != "{"
      && tempToken != "}" && tempToken != ";"
      && tempToken != "(" && tempToken != ")")			                    // If the token isn't a reserved word, it will allocate the info in local node
    {
      AllocateSymbol(Lex->m_tokens.line[j], tempToken, ":", FUNCTION, "", j, true, m_tempInFunc);
    }
  }
}

void Compiler::SyntaxState_Program::mainState(int i)
{
  for (int j = i; j < Lex->m_tokens.Lexem.size(); j++)
  {
    string tempToken = Lex->m_tokens.Lexem[j];

    if (tempToken == ":" || tempToken == ";" || tempToken == "{")
    {
      m_state = 0;
      break;
    }
    if (tempToken == "(")
    {
      m_tempInFunc = Lex->m_tokens.Lexem[i ];
      Check_EXP_LOG(j);
      break;
    }
    // If token is different that 'var' or numbers
    if (tempToken != "main" && tempToken != "{"
      && tempToken != "}" && tempToken != ";"
      && tempToken != "(" && tempToken != ")")			                    // If the token isn't a reserved word, it will allocate the info in local node
    {
      AllocateSymbol(Lex->m_tokens.line[j], tempToken, ":", FUNCTION, "", j, true, m_tempInFunc);
    }
  }
}

// void Compiler::SyntaxState_Program::readStringToken(int index, int state)
// {
// //   for (size_t i = 0; i < tok.size(); i++)
// //   {
// //     if (tok[i] != '@')											                                // If the indexed token is different from '@', it concatenates all the token
// //     {
// //       l_str += tok[i];
// //     }
// //     if (tok[i + 1] == '@')										                              // If the indexed token in the next position is equal to the '@',
// //     {																                                            // it will allocate the tokens in a vector of 3 spaces
// //       m_simbols.push_back(l_str);
// //       l_str = "";
// // //      i++;
// //     }
// //   }
//     m_simbols.push_back(Lex->m_tokens.line[index]);
//     m_simbols.push_back(Lex->m_tokens.Lexem[index]);
//     m_simbols.push_back(Lex->m_tokens.type[index]);
//     m_state = 1;
// }

void Compiler::SyntaxState_Program::AllocateSymbol(string line, string name, string tpToken, SYMBOL_CAT category, string dimToken, int i, bool isFunc, string inFunction)
{
  CheckforErrors(NODO, name, GLOBAL_VAR); // Check for Equal global variables
  CheckforErrors(NODO, name, FUNCTION); // Check for Equal functions
  // Allocate the token line
  NODO.Line.push_back(line);					                                      // Allocate the line of token
  /////////////////////////////////////////
  // Allocate the token name 
  NODO.Name.push_back(name);					                                       // Allocate the variable 
  /////////////////////////////////////////
  // Allocate the token type of data
  for (int j = i; j < Lex->m_tokens.Lexem.size(); j++)                          // Find the type of data of the variable
  {
    string tipo;
    if (Lex->m_tokens.Lexem[j] == tpToken)
    {
      NODO.Type.push_back(Lex->m_tokens.Lexem[j + 1]);                     // Allocate the type of data
      break;												                                            // if the data is allocated, the loop ends 
    }
  }
  /////////////////////////////////////////
  // Allocate the token category
  NODO.Category.push_back(category);				                                // Allocate the type of data // <! Warning : Change the structure to detect if it is local or global node>
 /////////////////////////////////////////
 // Allocate the token dimension
  if (isFunc)
  {
    NODO.Dimension.push_back(0);
  }
  else
  {
    if (Lex->m_tokens.Lexem[i + 1] == dimToken)					                          // find the dimension of the variable // <! Warning : Also can detect '=' as dimension >
    { // Dimension
      string tempdim = Lex->m_tokens.Lexem[i + 2];
      int Dim = stoi(tempdim);
      NODO.Dimension.push_back(Dim);
    }
    else
    {
      NODO.Dimension.push_back(0);
    }
  }
  NODO.Function.push_back(inFunction);					                                // Allocate the function
  NODO.Value.push_back(nullptr);						                                // Allocate the value, necessary for P3
}

void Compiler::SyntaxState_Program::Check_EXP_LOG(int i)
{
  for (int j = i; j < Lex->m_tokens.Lexem.size(); j++)
  {
    string tempToken = Lex->m_tokens.Lexem[j];
    if (tempToken == "{")
    {
      CheckStatmentblock(j);
      break;
    }
    if (tempToken != "(" && tempToken != ")" && tempToken != ":" 
      && tempToken != "," && tempToken != "\n"
      && tempToken != "int"   && tempToken != "bool" 
      && tempToken != "float" && tempToken != "var")
    {
      AllocateSymbol(Lex->m_tokens.line[j], tempToken, ":", PARAMETER, "[", j, false, m_tempInFunc);
    }
    
  }
}

void Compiler::SyntaxState_Program::CheckStatmentblock(int i)
{
  for (int j = i; j < Lex->m_tokens.Lexem.size(); j++)
  {
    string tempToken = Lex->m_tokens.Lexem[j];
    if (tempToken == "}")
    {
      m_tempInFunc = "<GLOBAL SCOPE>";
      m_currIndex = j;
      m_state = 0;
      break;
    }
    if (tempToken != "var" && tempToken != ","&& tempToken != "{" && tempToken != "}"
      && tempToken != "[" && tempToken != "]" && tempToken != "1" && tempToken != "2"
      && tempToken != "3" && tempToken != "4" && tempToken != "5" && tempToken != "6"
      && tempToken != "7" && tempToken != "8" && tempToken != "9" && tempToken != ":"
      && tempToken != "0" && tempToken != "\n" && tempToken != "int" && tempToken != "bool"
      && tempToken != "var"&& tempToken != "float"&& tempToken != ";" && tempToken != "string"
      && tempToken != "return" && tempToken != "false" && tempToken != "true")
    {
      AllocateSymbol(Lex->m_tokens.line[j], tempToken, ":", LOCAL_VAR, "[", j, false, m_tempInFunc);
    }

  }
}

void Compiler::SyntaxState_Program::CheckforErrors(NL node, string currentSymbol, SYMBOL_CAT category)
{// SymbolName, category
  for (int i = 0; i < node.Name.size(); i++)
  {
    if (node.Name[i] == currentSymbol && node.Category[i] == category)
    {
      // Allocate Error
      String^ ErrorDesc = gcnew String(currentSymbol.c_str());
      String^ Error;
      Error = "Variable/Function already defined in the same scope";
      int n = std::stoi(node.Line[i]);
      Lex->m_refErrorMod->addError(Lex->m_refErrorMod->semanticError, n, Error, ErrorDesc);
    }
  }
}

