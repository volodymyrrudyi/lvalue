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
#include <boost/shared_ptr.hpp>
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
	typedef boost::shared_ptr<llvm::Value> SharedValue;
	typedef boost::shared_ptr<llvm::BasicBlock> SharedBasicBlock;

	struct LValue_Block
	{
	public:
		SharedBasicBlock basicBlock;
		std::map<std::string, SharedValue> localVariables;
	};

	typedef boost::shared_ptr<LValue_Block> SharedLValue_Block;

    class LValue_Builder : public llvm::IRBuilder<> {
    protected:
    	std::stack<SharedLValue_Block> blocks;
    	llvm::Function *mainFunction;
    public:
        llvm::Module *module;
        LValue_Builder();

        void pushBlock(SharedBasicBlock block);
        SharedBasicBlock popBlock();
        SharedBasicBlock currentBlock();
        std::map<std::string, SharedValue> &localVariables() { return blocks.top()->localVariables; };

        void generateCode(AST_Node *root);

    };
}
#endif	/* LVALUE_BUILDER_H */

