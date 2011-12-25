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

void lvalue::LValue_Builder::generateCode(AST_Node* root)
{
    std::cout << "Generating code...\n";

    /* Create the top level interpreter function to call as entry */
    std::vector<const Type*> argTypes;
    FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), argTypes, false);
    mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
    BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);

    /* Push a new variable/block context */
    pushBlock(SharedBasicBlock(bblock));
    root->emmitCode(); /* emit bytecode for the toplevel block */
    ReturnInst::Create(getGlobalContext(), bblock);
    popBlock();


    /* Print the bytecode in a human-readable format
       to see if our program compiled properly
     */
    std::cout << "Code is generated.\n";
    PassManager pm;
    pm.add(createPrintModulePass(&outs()));
    pm.run(*module);

}

