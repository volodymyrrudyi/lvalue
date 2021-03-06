/*
   Copyright (c) 2011 Chernihiv State Technological University

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#include "AST_IfStatement.h"
#include <llvm/Support/IRBuilder.h>

lvalue::AST_IfStatement::AST_IfStatement(LValue_Builder &builder, AST_Expression& conditionExpression,
		AST_Block &thenBlock, AST_Block &elseBlock)
	: AST_Statement(builder), conditionExpression(conditionExpression),
	  thenBlock(thenBlock), elseBlock(elseBlock)
{
}


Value* lvalue::AST_IfStatement::emmitCode()
{
	IRBuilder<> irBuilder(getGlobalContext());
	cout << "Creating If" << endl;
	Value *CondV = conditionExpression.emmitCode();
	if (CondV == 0) return 0;

	cout << "Inserting condition actions" << endl;
	// Conversion to comparsion with 0.0
	CondV = irBuilder.CreateFCmpONE(CondV,
								  ConstantFP::get(getGlobalContext(), APFloat(0.0)), "ifcond");

	Function *TheFunction = builder.currentBlock()->getParent();
	BasicBlock *ThenBB 	=  BasicBlock::Create(getGlobalContext(), "then", TheFunction);
	BasicBlock *ElseBB 	=  BasicBlock::Create(getGlobalContext(), "else", TheFunction);
	BasicBlock *MergeBB =  BasicBlock::Create(getGlobalContext(), "ifcont");

	irBuilder.SetInsertPoint(builder.currentBlock());
	irBuilder.CreateCondBr(CondV, ThenBB, ElseBB);

	irBuilder.SetInsertPoint(ThenBB);
	builder.pushBlock(ThenBB);
	Value *ThenV = this->thenBlock.emmitCode();
	irBuilder.CreateBr(MergeBB);
	builder.popBlock();
	if (ThenV == 0) return 0;

	BranchInst::Create(MergeBB);
	ThenBB = irBuilder.GetInsertBlock();

	TheFunction->getBasicBlockList().push_back(ElseBB);
	irBuilder.SetInsertPoint(ElseBB);

	builder.pushBlock(ElseBB);
	Value *ElseV = this->elseBlock.emmitCode();
	builder.popBlock();
	if (ElseV == 0) return 0;

	ElseBB = irBuilder.GetInsertBlock();

	TheFunction->getBasicBlockList().push_back(MergeBB);
	irBuilder.SetInsertPoint(MergeBB);
	PHINode *PN = irBuilder.CreatePHI(Type::getDoubleTy(getGlobalContext()),
									"iftmp");

	PN->addIncoming(ThenV, ThenBB);
	PN->addIncoming(ElseV, ElseBB);
	return PN;
}
