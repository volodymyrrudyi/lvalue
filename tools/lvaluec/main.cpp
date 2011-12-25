#include <iostream>
#include <llvm/ExecutionEngine/JIT.h>

#include "LValue_Builder.h"
#include "AST_Block.h"

using namespace std;
using namespace llvm;
using namespace lvalue;

extern int yyparse();

int main(int argc, char **argv)
{
    InitializeNativeTarget();
    yyparse();

    AST_Block *root;

    LValue_Builder builder;
    builder.generateCode(root);


    return 0;
}
