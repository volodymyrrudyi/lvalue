#include <iostream>
#include <llvm/ExecutionEngine/JIT.h>
#include <stdio.h>

#include "LValue_Builder.h"
#include "AST_Block.h"

using namespace std;
using namespace llvm;
using namespace lvalue;

extern LValue_Builder builder;
extern int yyparse();
extern FILE* yyin;

int main(int argc, char **argv)
{
    InitializeNativeTarget();
    if (argc > 1)
    {
    	yyin = fopen(argv[1], "r");
    }
    yyparse();

    builder.generateCode();


    return 0;
}
