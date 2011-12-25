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

#include "AST_FunctionDeclaration.h"

lvalue::AST_FunctionDeclaration::AST_FunctionDeclaration(LValue_Builder &builder,
		AST_Identifier &type, AST_Identifier &id, VariableList arguments,
		AST_Block &block)
    : AST_Statement(builder), type(type), id(id), arguments(arguments), block(block)
{
}

Value* lvalue::AST_FunctionDeclaration::emmitCode()
{
	  	std::vector<const Type*> argTypes;
	    VariableList::const_iterator it;
	    for (it = arguments.begin(); it != arguments.end(); it++) {
	        argTypes.push_back(typeOf((**it).type));
	    }
	    FunctionType *ftype = FunctionType::get(typeOf(type), argTypes, false);
	    Function *function = Function::Create(ftype, GlobalValue::InternalLinkage, id.name.c_str(), builder.module);
	    BasicBlock *bblock = BasicBlock::Create(getGlobalContext(), "entry", function, 0);

	    builder.pushBlock(bblock);

	    for (it = arguments.begin(); it != arguments.end(); it++) {
	        (**it).emmitCode();
	    }

	    block.emmitCode();
	    builder.CreateRet(bblock);
	    //ReturnInst::Create(getGlobalContext(), bblock);

	    builder.popBlock();
	   // std::cout << "Creating function: " << id.name << std::endl;
	    return function;
}
