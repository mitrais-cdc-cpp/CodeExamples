/*
 * SpecialVisitor.h
 *
 *  Created on: Jul 20, 2016
 *      Author: developer
 */

#ifndef INC_SPECIALVISITOR_H_
#define INC_SPECIALVISITOR_H_

#include "GenericVisitor.h"

/**
 * Special visitor class that inherits generic visitor template
 */
class SpecialVisitor : public GenericVisitor<SpecialVisitor>
{
	friend class GenericVisitor<SpecialVisitor>;
private:
    void handle_RED(TreeNode* node);
};

#endif /* INC_SPECIALVISITOR_H_ */
