#include "stdafx.h"
#include "SemanticTree.h"


Compiler::SemanticTree::SemanticTree()
{
}

void Compiler::SemanticTree::getExplog(vector<string> explogVec, NL semanticNodes)
{
  Nodes = semanticNodes;
  for (int i = 0; i < explogVec.size(); i++)
  {
    string str;
    string str2 = explogVec[i];
    size_t first = str2.find_first_of('(');
    size_t last  = str2.find_last_of(')');
    if (std::string::npos != first && std::string::npos != last)
    {
      str = str2.substr(first + 1, last - first - 1);
    }
    toPolishExp(str);
  }
}

int Compiler::SemanticTree::precedence(char op)
{
  if (op == '^')
    return 3;
  else if (op == '*' || op == '/')
    return 2;
  else if (op == '+' || op == '-')
    return 1;
  else
    return -1;
}

void Compiler::SemanticTree::toPolishExp(string str)
{
  st.push('N');
  int l = str.length();
  vector<string> tempTypes;
  string temp2;
  for (int i = 0; i < l; i++)
  {
    // If the scanned character is an operand, add it to output string. 
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
    {
      polishString += str[i];
//        temp2 += str[i];
//       for (int j = 0; j < Nodes.Name.size(); j++)
//       {
//         string temp = Nodes.Name[j];
//         if (temp == temp2 && tempTypes.size() <= 2)
//         {
//           // Check type
//           tempTypes.push_back(Nodes.Type[i]);
//           temp2.clear();
//         }
//       }
//       
//       if (tempTypes.size() == 2)
//       {
//         if (tempTypes[0] != tempTypes[1])
//         {
//           // Send Error...
//         }
//         tempTypes.clear();
//       }
    }

    // If the scanned character is an '(', push it to the stack. 
    else if (str[i] == '(')

      st.push('(');

    // If the scanned character is an ')', pop and to output string from the stack 
    // until an '(' is encountered. 
    else if (str[i] == ')')
    {
      while (st.top() != 'N' && st.top() != '(')
      {
        char c = st.top();
        st.pop();
        polishString += c;
      }
      if (st.top() == '(')
      {
        char c = st.top();
        st.pop();
      }
    }

    //If an operator is scanned 
    else {
      while (st.top() != 'N' && precedence(str[i]) <= precedence(st.top()))
      {
        char c = st.top();
        st.pop();
        polishString += c;
      }
      st.push(str[i]);
    }

  }
  //Pop all the remaining elements from the stack 
  while (st.top() != 'N')
  {
    char c = st.top();
    st.pop();
    polishString += c;
  }

  savePolish.push_back(polishString);
  //cout << polishString << endl;

}
