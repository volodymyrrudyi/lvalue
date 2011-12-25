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

#ifndef __AST_NODE_H
#define __AST_NODE_H

#include "LValue_Builder.h"

namespace lvalue
{
  /**
   * Class represents node of the LValue abstract syntax tree.
   */
  class AST_Node
  {
    protected:
      LValue_Builder &builder;
    public:

      AST_Node(LValue_Builder &builder);
      /**
       * Virtual method for emmiting LLVM IR code of this AST Node
       */
      virtual Value* emmitCode();

      /**
       * Empty virtual destructor to allow avoid memory leaks in child classes.
       */
      virtual ~AST_Node();
  };
}

#endif
