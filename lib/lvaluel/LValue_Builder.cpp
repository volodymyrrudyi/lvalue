/* 
 * File:   LValue_Builder.cpp
 * Author: tanysha
 * 
 * Created on 25 грудня 2011, 12:48
 */

#include "LValue_Builder.h"
#include "AST_Node.h"

lvalue::LValue_Builder::LValue_Builder()
{
    module = new Module("main", getGlobalContext());
}

void lvalue::LValue_Builder::pushBlock(BasicBlock* block)
{
	LValue_Block* lvalueBlock = new LValue_Block();
	lvalueBlock->basicBlock = block;
	blocks.push_back(lvalueBlock);
}

void lvalue::LValue_Builder::popBlock()
{
	LValue_Block *block = blocks.back();
	blocks.pop_back();

	delete block;
}

BasicBlock* lvalue::LValue_Builder::currentBlock()
{
	return blocks.back()->basicBlock;
}

void lvalue::LValue_Builder::generateCode()
{
    std::vector<const Type*> argTypes;
    FunctionType *ftype = FunctionType::get(Type::getVoidTy(getGlobalContext()), argTypes, false);
    mainFunction = Function::Create(ftype, GlobalValue::InternalLinkage, "main", module);
    BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", mainFunction, 0);


    pushBlock(bblock);
    root->emmitCode(); /* emit bytecode for the toplevel block */
    popBlock();
    BasicBlock *outerBblock = BasicBlock::Create(getGlobalContext(), "leaving", mainFunction, 0);

    pushBlock(outerBblock);
    ReturnInst::Create(getGlobalContext(), outerBblock);
    popBlock();


    std::cout << "Code is generated.\n";
    PassManager pm;
    pm.add(createPrintModulePass(&outs()));
    pm.run(*module);

}

Value* lvalue::LValue_Builder::getVariable(const string &name)
{
	for (vector<LValue_Block*>::iterator i = this->blocks.begin(); i != blocks.end(); i++)
	{
		std::map<std::string, Value*>::iterator pos = (*i)->localVariables.find(name);
		if( pos != (*i)->localVariables.end())
		{
			return pos->second;
		}
	}

	return NULL;
}
