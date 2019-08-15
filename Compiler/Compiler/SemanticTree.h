#pragma once
#include "Header.h"
#include <stack>
//https://www.geeksforgeeks.org/expression-tree/
namespace Compiler {
  class SemanticTree
  {
  public:
    SemanticTree();
    //~SemanticTree();
  public:
    void getExplog(vector<string> explogVec, NL semanticNodes);
    int precedence(char op);
    void toPolishExp(string str);
  public:
    std::stack<char> st;
    string polishString;
    NL Nodes;
    vector<string> savePolish;
  };
} 

