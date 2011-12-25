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

#ifndef AST_VARIABLEDECLARATION_H
#define AST_VARIABLEDECLARATION_H

#include "AST_Node.h"
#include "AST_Identifier.h"
#include "AST_Expression.h"
#include "AST_Assignment.h"

namespace lvalue
{
    class AST_VariableDeclaration : public AST_Node
    {
    public:
        AST_Identifier &type;
        AST_Identifier &id;
        SharedExpression assignmentExpression;
        AST_VariableDeclaration(LValue_Builder &builder,
        AST_Identifier &id, AST_Identifier &type,
        	SharedExpression assignmentExpression);

        SharedValue emmitCode();
    };

    typedef boost::shared_ptr<AST_VariableDeclaration> SharedVariable;
    typedef std::vector<SharedVariable> VariableList;
}

#endif // AST_VARIABLEDECLARATION_H