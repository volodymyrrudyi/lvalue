/* 
 * File:   LValue_Builder.h
 * Author: tanysha
 *
 * Created on 25 грудня 2011, 12:48
 */

#ifndef LVALUE_BUILDER_H
#define	LVALUE_BUILDER_H

#include <llvm/Support/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>


namespace lvalue
{
    class LValue_Builder : public llvm::IRBuilder<> {
    public:
        llvm::Module *module;
        LValue_Builder();

    };
}
#endif	/* LVALUE_BUILDER_H */

