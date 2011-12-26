/* 
 * File:   LValue_Builder.h
 * Author: tanysha
 *
 * Created on 25 грудня 2011, 12:48
 */

#ifndef LVALUE_BUILDER_H
#define	LVALUE_BUILDER_H

#include <vector>
#include <stack>
#include <map>
#include <string>
#include <llvm/Support/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvm/BasicBlock.h>
#include <llvm/Value.h>
#include <llvm/Module.h>
#include <llvm/Function.h>
#include <llvm/Type.h>
#include <llvm/DerivedTypes.h>
#include <llvm/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/Instructions.h>
#include <llvm/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/Support/IRBuilder.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <iostream>
#include <vector>

using namespace std;
using namespace llvm;

namespace lvalue
{

	class AST_Node;

	struct LValue_Block
	{
	public:
		BasicBlock *basicBlock;
		map<std::string, Value*> localVariables;
	};

    class LValue_Builder {
    protected:
    	vector<LValue_Block*> blocks;
    	Function *mainFunction;
    public:
        Module *module;
        AST_Node* root;
        LValue_Builder();

        void pushBlock(BasicBlock* block);
        void popBlock();
        BasicBlock *currentBlock();
        map<std::string, Value*> &localVariables() { return blocks.back()->localVariables; };
        Value* getVariable(const string &name);

        void generateCode();

    };
}
#endif	/* LVALUE_BUILDER_H */

