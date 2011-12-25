#include <iostream>
#include <llvm/ExecutionEngine/JIT.h>

#include "LValue_Builder.h"
#include "AST_Block.h"

using namespace std;
using namespace llvm;
using namespace lvalue;

extern LValue_Builder builder;
extern int yyparse();

int main(int argc, char **argv)
{
    InitializeNativeTarget();
    yyparse();

    builder.generateCode();


    return 0;
}
