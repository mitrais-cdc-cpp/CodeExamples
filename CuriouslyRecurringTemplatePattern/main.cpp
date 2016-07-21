//============================================================================
// Name        : CRTP_Sample.cpp
// Author      : Albertus Adityo Wahono
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "inc/SpecialVisitor.h"

using namespace std;

int main()
{
	TreeNode tr1(TreeNode::BLUE), tr2(TreeNode::RED);
	TreeNode tr(TreeNode::RED, &tr1, &tr2);
	SpecialVisitor vis;
	vis.visit_preorder(&tr);
}
