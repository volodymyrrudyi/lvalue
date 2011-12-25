/* 
 * File:   LValue_Builder.cpp
 * Author: tanysha
 * 
 * Created on 25 грудня 2011, 12:48
 */

#include "LValue_Builder.h"

lvalue::LValue_Builder::LValue_Builder() : llvm::IRBuilder<>(llvm::getGlobalContext())
{
    module = new llvm::Module("main", llvm::getGlobalContext());
}

void lvalue::LValue_Builder::pushBlock(SharedBasicBlock block)
{
	SharedLValue_Block lvalueBlock = SharedLValue_Block(new LValue_Block());
	lvalueBlock->basicBlock = block;
	blocks.push(lvalueBlock);
}

lvalue::SharedBasicBlock lvalue::LValue_Builder::popBlock()
{
	SharedBasicBlock block = blocks.top()->basicBlock;
	blocks.pop();

	return block;
}

lvalue::SharedBasicBlock lvalue::LValue_Builder::currentBlock()
{
	return blocks.top()->basicBlock;
}
