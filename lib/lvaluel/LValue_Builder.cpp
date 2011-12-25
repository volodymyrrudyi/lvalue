/* 
 * File:   LValue_Builder.cpp
 * Author: tanysha
 * 
 * Created on 25 грудня 2011, 12:48
 */

#include "LValue_Builder.h"
#include "AST_Node.h"

lvalue::LValue_Builder::LValue_Builder() : IRBuilder<>(getGlobalContext())
{
    module = new Module("main", getGlobalContext());
}

void lvalue::LValue_Builder::pushBlock(BasicBlock* block)
{
	LValue_Block* lvalueBlock = new LValue_Block();
	lvalueBlock->basicBlock = block;
	blocks.push(lvalueBlock);
}

void lvalue::LValue_Builder::popBlock()
{
	LValue_Block *block = blocks.top();
	blocks.pop();

	delete block;
}

BasicBlock* lvalue::LValue_Builder::currentBlock()
{
	return blocks.top()->basicBlock;
}

void lvalue::LValue_Builder::generateCode()
{
    std::vector<const Type*> argTypes;
    FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), argTypes, false);
    mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
    BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);


    pushBlock(bblock);
    root->emmitCode(); /* emit bytecode for the toplevel block */
    ReturnInst::Create(getGlobalContext(), bblock);
    popBlock();


    std::cout << "Code is generated.\n";
    PassManager pm;
    pm.add(createPrintModulePass(&outs()));
    pm.run(*module);

}

