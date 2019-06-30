#include "stdafx.h"
#include "SyntaxState_Var.h"



Compiler::SyntaxState_Var::SyntaxState_Var()
{

}

void Compiler::SyntaxState_Var::checkSyntax(string token)
{
	string str;
	vector<string> Words;
	for (int i = 0; i < token.size(); i++)
	{
		if (token[i] != '@')
		{
			str += token[i];
			//i++;
		}
		if (token[i + 1] == '@')
		{
			Words.push_back(str);
			str = "";
			i++;
		}
		if (Words.size() == 3)
		{
			//dataGridView1.Rows.Add(Words[0], Words[1], Words[2]);
			//NodoLocal m_localNode;
			//m_localNode.GetLocalNode(Words[0], Words[1], Words[2], LOCAL_VAR, 0, "var", nullptr, nullptr);

			Words.clear();
		}
	}

	//m_LocalNodes.push_back(m_localNode);
	// Analyze the var and check for ; and return to stateprogram
	//return a; // Return the node to push it in program
}
