/* 
 * File:   LValue_Builder.cpp
 * Author: tanysha
 * 
 * Created on 25 грудня 2011, 12:48
 */

#include "LValue_Builder.h"

lvalue::LValue_Builder::LValue_Builder() 
{
    module = new llvm::Module("main", getGlobalContext());
}
