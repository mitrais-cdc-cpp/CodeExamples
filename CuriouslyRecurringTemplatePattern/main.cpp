//============================================================================
// Name        : CRTP_Sample.cpp
// Author      : Albertus Adityo Wahono
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "inc/SpecialVisitor.h"

/**
 * Source:
 * http://eli.thegreenplace.net/2011/05/17/the-curiously-recurring-template-pattern-in-c
 *
 * Definition:
 * CRTP is one of many ways to implement polymorphism, the idea is to inject the real type of derived
 * class into the base, at compile time, allowing the static_cast of 'this' in the derived()
 * to produce the desired result
 *
 * Code Explanation:
 * The visitor object will call the visit order which defined in the generic visitor template
 * During the execution of visit order, the dispatch node method will be called
 * And define which handler will be called based on the color, before the handler is called
 * There will be downcast process from generic to special visitor
 * During runtime, the system will resolve which handler will be called and overridden by the specific one
 * Which defined in the special visitor class, that's why when we have RED node and
 * It's dispatched "RED is special" message will be displayed instead of "Generic handle RED"
 */

using namespace std;

int main()
{
	// Create a tree nodes as a branch named RED and BLUE
	TreeNode tr1(TreeNode::BLUE), tr2(TreeNode::RED);

	/**
	 * Create a tree node as the trunk named RED
	 * With 2 branches named RED and BLUE as mentioned above
	 */
	TreeNode tr(TreeNode::RED, &tr1, &tr2);

	/**
	 * Instantiate a special visitor object
	 * Which inherit generic visitor template class
	 */
	SpecialVisitor vis;

	// Start the visit order with the visitor
	vis.visit_preorder(&tr);
}
