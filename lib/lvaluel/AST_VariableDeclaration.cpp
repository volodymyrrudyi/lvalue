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

#include "AST_VariableDeclaration.h"

lvalue::AST_VariableDeclaration::AST_VariableDeclaration(LValue_Builder &builder,
    AST_Identifier &id, AST_Identifier &type, AST_Expression* assignmentExpression) :
    AST_Node(builder),
    type(type),
    id(id),
    assignmentExpression(assignmentExpression)
{
}

Value* lvalue::AST_VariableDeclaration::emmitCode()
{
    AllocaInst *alloc = new AllocaInst(typeOf(type), id.name.c_str(), builder.currentBlock());
    builder.localVariables()[id.name] = alloc;
    if (assignmentExpression != NULL) {
        AST_Assignment assn(builder, id, *assignmentExpression);
        assn.emmitCode();
    }
    return alloc;
}
