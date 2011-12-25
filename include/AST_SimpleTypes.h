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

#ifndef __AST_SIMPLETYPES_H
#define __AST_SIMPLETYPES_H

#include "AST_Node.h"

#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>

namespace lvalue
{
  /**
   * Class represents Integer value of the LValue abstract syntax tree.
   */
  class AST_Integer : public AST_Node
  {
    public:
	  long long value;
      AST_Integer(LValue_Builder &builder, long long value);
      virtual Value* emmitCode();
  };

  /**
   * Class represents Integer value of the LValue abstract syntax tree.
   */
  class AST_Double : public AST_Node
  {
    public:
	  long double value;
      AST_Double(LValue_Builder &builder, long double value);
      virtual Value* emmitCode();
  };

  /**
   * Class represents Integer value of the LValue abstract syntax tree.
   */
  class AST_Boolean : public AST_Node
  {
    public:
	  bool value;
      AST_Boolean(LValue_Builder &builder, bool value);
      virtual Value* emmitCode();
  };
}

#endif
