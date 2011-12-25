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

#include "AST_Identifier.h"

lvalue::AST_Identifier::AST_Identifier(LValue_Builder &builder, const std::string &name) :
    AST_Node(builder), name(name)
{
}

lvalue::SharedValue lvalue::AST_Identifier::emmitCode()
{
	  	// std::cout << "Creating identifier reference: " << name << std::endl;
	    if (builder.localVariables().find(name) == builder.localVariables().end()) {
	        //std::cerr << "undeclared variable " << name << std::endl;
	        return SharedValue();
	    }

	    return SharedValue(builder.CreateLoad(builder.localVariables()[name].get()));
	    //return SharedValue(new llvm::LoadInst(builder.localVariables()[name], "", false, builder.currentBlock()));
}

const llvm::Type *lvalue::typeOf(const AST_Identifier& type)
{
    if (type.name.compare("int") == 0) {
        return llvm::Type::getInt64Ty(llvm::getGlobalContext());
    }
    else if (type.name.compare("double") == 0) {
        return llvm::Type::getDoubleTy(llvm::getGlobalContext());
    }
    else if (type.name.compare("boolean") == 0) {
           return llvm::Type::getInt16Ty(llvm::getGlobalContext());
       }
    return llvm::Type::getVoidTy(llvm::getGlobalContext());
}
