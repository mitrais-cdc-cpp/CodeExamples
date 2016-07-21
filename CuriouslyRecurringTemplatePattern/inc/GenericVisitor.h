/*
 * GenericVisitor.h
 *
 *  Created on: Jul 20, 2016
 *      Author: developer
 */

#ifndef INC_GENERICVISITOR_H_
#define INC_GENERICVISITOR_H_

#include <iostream>
#include "TreeNode.h"

using namespace std;

template <typename Derived>
class GenericVisitor
{
public:
	void visit_preorder(TreeNode* node)
	{
		if (node) {
			dispatch_node(node);
			visit_preorder(node->left);
			visit_preorder(node->right);
		}
	}

	void visit_inorder(TreeNode* node)
	{
		if (node) {
			visit_inorder(node->left);
			dispatch_node(node);
			visit_inorder(node->right);
		}
	}

	void visit_postorder(TreeNode* node)
	{
		if (node) {
			visit_postorder(node->left);
			visit_postorder(node->right);
			dispatch_node(node);
		}
	}

	void handle_RED(TreeNode* node)
	{
		cerr << "Generic handle RED\n";
	}

	void handle_BLUE(TreeNode* node)
	{
		cerr << "Generic handle BLUE\n";
	}

private:
    Derived& derived()
    {
        return *static_cast<Derived*>(this);
    }

    void dispatch_node(TreeNode* node)
    {
        switch (node->kind) {
            case TreeNode::RED:
                derived().handle_RED(node);
                break;
            case TreeNode::BLUE:
                derived().handle_BLUE(node);
                break;
            default:
    //                assert(0);
            	break;
        }
    }
};


#endif /* INC_GENERICVISITOR_H_ */
