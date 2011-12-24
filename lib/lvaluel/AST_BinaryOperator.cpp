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

#include "AST_BinaryOperator.h"
#include "AST_Expression.h"

lvalue::AST_BinaryOperator::AST_BinaryOperator(llvm::IRBuilder<> &builder, 
        AST_Expression &lhs, int op, AST_Expression &rhs) 
: AST_Node(builder), op(op), rhs(rhs), lhs(lhs)
{
    
}

lvalue::AST_BinaryOperator::emmitCode()
{
    llvm::Instruction::BinaryOps instr;
    switch (op) {
        
    case TPLUS: 	instr = llvm::Instruction::Add; goto math;
    case TMINUS: 	instr = llvm::Instruction::Sub; goto math;
    case TMUL: 		instr = llvm::Instruction::Mul; goto math;
    case TDIV: 		instr = llvm::Instruction::SDiv; goto math;
    }

    return SharedValue();
    math:
        return builder.CreateBinOp(instr, rhs.emmitCode(), lhs.emmitCode(), 
            "binop");
}
