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

namespace lvalue
{
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
    public:
        llvm::Module *module;
        LValue_Builder();

        void pushBlock(SharedBasicBlock block);
        SharedBasicBlock popBlock();
        SharedBasicBlock currentBlock();
        std::map<std::string, SharedValue> &localVariables() { return blocks.top()->localVariables; };

    };
}
#endif	/* LVALUE_BUILDER_H */

