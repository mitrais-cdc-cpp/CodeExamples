/*
 * TreeNode.h
 *
 *  Created on: Jul 20, 2016
 *      Author: developer
 */

#ifndef INC_TREENODE_H_
#define INC_TREENODE_H_

#include <iostream>

struct TreeNode
{
    enum Kind {RED, BLUE};

    TreeNode(Kind kind_, TreeNode* left_ = NULL, TreeNode* right_ = NULL)
        : kind(kind_), left(left_), right(right_)
    {}

    Kind kind;
    TreeNode *left, *right;
};

#endif /* INC_TREENODE_H_ */
